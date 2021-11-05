#include "NewtonMethodEqNode.h"
#include <cmath>
#include <Eigen/Dense>

void NewtonEqNode::solve(EqNodePtr& root, EqNodePtr var)
{
	EqNodePtr derivRoot;
	double x1, x2, f1, tol, df1, err;
	int kmax, k;

	tol = 1e-8;
	kmax = 100;

	x1 = var->getValue();
	f1 = root->getValue();
	df1 = root->getDerValue(*var);

	for (k = 0; k < kmax; k++) {
		x2 = x1 - f1 / df1;
		err = abs(x2 - x1);

		var->v = x2;
		x1 = x2;
		if (err < tol)
			return;

		f1 = root->getValue();
		df1 = root->getDerValue(*var);
	}
}

void NewtonEqNode::NLASolve(const int& n, std::vector< EqNodePtr >& eqs,
	std::vector < EqNodePtr >& vars, const double& tol)
{
	int kmax, k;
	Eigen::MatrixXd Jac(n, n);
	Eigen::VectorXd F(n), x(n);
	Eigen::VectorXd delta(n);

	kmax = 300;
	double err = 0;

	for (const auto& var : vars)
		var->correctValueInsideBoundaries();

	for (k = 0; k < kmax; ++k) {

		for (int i = 0; i < n; ++i) {
			x[i] = vars[i]->v;
			F[i] = eqs[i]->getValue();
			for (int j = 0; j < n; ++j)
				Jac(i, j) = eqs[i]->getDerValue(*vars[j]);
		}

		// Solve linear system
		delta = Jac.fullPivLu().solve(-F);
		// Update x values
		x = x + delta;

		for (int i = 0; i < n; ++i) vars[i]->v = x[i];

		// criterion for stop
		// get max abs value of function
		err = 0.0;
		for (int i = 0; i < n; ++i) {
			err = err < std::abs(F[i]) ? abs(F[i]) : err;
			err = err < std::abs(delta[i]) ? abs(delta[i]) : err;
		}

		if (err < tol) return;

		for (auto& var : vars) var->correctValueInsideBoundaries();
	}
}
