#include "SimpleESOSolver.h"

#include <cmath>
#include <iostream>
#include <Eigen/Dense>

SimpleESOSolver::SimpleESOSolver(ESO* eso)
{
	m_ESO = eso;
	n_vars = m_ESO->GetNumVars();
	n_eqns = m_ESO->GetNumEqns();

	jac = std::unique_ptr<double[]>(new double[n_vars * n_eqns]);
	xx = std::unique_ptr<double[]>(new double[n_vars]);
	FF = std::unique_ptr<double[]>(new double[n_eqns]);
}

void SimpleESOSolver::solve()
{
	int kmax, k;
	const auto& n = n_eqns;

	kmax = 300;
	double err = 0;

	Eigen::Map<Eigen::VectorXd> F(FF.get(), n);
	Eigen::Map<Eigen::VectorXd> x(xx.get(), n);
	Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> Jac(jac.get(), n, n);

	Eigen::VectorXd delta(n);

	m_ESO->correctBoundaries();
	m_ESO->GetAllVariables(xx.get());

	for (k = 0; k < kmax; ++k) {

		m_ESO->GetAllResiduals(FF.get());
		m_ESO->getAllJacobianValues(jac.get());

		// Solve linear system
		delta = Jac.fullPivLu().solve(-F);

		// Update x values
		x = x + delta;

		m_ESO->SetAllVariables(xx.get());

		// criterion for stop
		// get max abs value of function
		err = 0.0;
		for (size_t i = 0; i < n; ++i) {
			err = err < std::abs(F[i]) ? abs(F[i]) : err;
			err = err < std::abs(delta[i]) ? abs(delta[i]) : err;
		}

		if (err < m_tol) return;

		m_ESO->correctBoundaries();
	}
}
