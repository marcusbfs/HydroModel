#include "cminpackESOSolver.h"

//#include "minpack.hpp"
//#include "minpack.cpp"

namespace cminpackESO {
	ESO* eso_;
	std::unique_ptr<double[]> jac_,  x_,  F_;
}

void fcnd__cminpack(int n, double x[], double fvec[], int& iflag)
{
	cminpackESO::eso_->SetAllVariables(x);
	cminpackESO::eso_->correctBoundaries(); // test
	cminpackESO::eso_->GetAllResiduals(fvec);
}

cminpackESOSolver::cminpackESOSolver(ESO* eso)
{
	cminpackESO::eso_ = eso;

	n_vars = cminpackESO::eso_->GetNumVars();
	n_eqns = cminpackESO::eso_->GetNumEqns();

	m_l = std::unique_ptr<double[]>(new double[n_vars]);
	m_u = std::unique_ptr<double[]>(new double[n_vars]);
	cminpackESO::jac_ = std::unique_ptr<double[]>(new double[n_vars * n_eqns]);
	cminpackESO::x_ = std::unique_ptr<double[]>(new double[n_vars]);
	cminpackESO::F_ = std::unique_ptr<double[]>(new double[n_eqns]);

	cminpackESO::eso_->GetAllLowerBounds(m_l.get());
	cminpackESO::eso_->GetAllUpperBounds(m_u.get());
}

void cminpackESOSolver::solve()
{
	const int& n = n_vars;
	const int& ldfjac = n_vars;
	const double& tol = m_tol;
	int info;

	// temp array used in calculations
	int lwa = 1 + n * (3 * n + 13) / 2;
	std::unique_ptr<double[]> wa = std::unique_ptr<double[]>(new double[lwa]);

	// get initial guesses
	cminpackESO::eso_->GetAllVariables(cminpackESO::x_.get());

	// solve
	//info = hybrd1(fcnd__cminpack, n, cminpackESO::x_.get(), cminpackESO::F_.get(), tol,  wa.get(), lwa);
}
