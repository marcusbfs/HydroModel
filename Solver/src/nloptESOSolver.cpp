#include "nloptESOSolver.h"

#include "SolverLog.h"
#include "nlopt.hpp"
#include "nlopt.h"
#include <vector>
#include <cmath>

namespace nloptESO {
	ESO* eso_;
	std::unique_ptr<double[]> jac_;
	std::unique_ptr<double[]> x_;
	std::unique_ptr<double[]> F_;
}

double nloptFuncApiImpl(const std::vector<double >& x, std::vector<double >& grad, void* f_data) {
	// calcualte residuals
	std::copy(x.begin(), x.end(), nloptESO::x_.get());
	nloptESO::eso_->SetAllVariables(nloptESO::x_.get());
	nloptESO::eso_->GetAllResiduals(nloptESO::F_.get());
	// return the squares sum

	double res2 = 0;

	for (size_t i = 0; i < x.size(); ++i)
		res2 += nloptESO::F_[i] * nloptESO::F_[i];

	// calculate grad if necessary
	// res = fi^2 + ...
	// dres/dxj = 2*fi*dfi/dfj + ...
	if (!grad.empty()) {
		for (size_t j = 0; j < grad.size(); ++j) {
			grad[j] = 0.0;
			for (size_t i = 0; i < x.size(); ++i) {
				double tmp;
				nloptESO::eso_->GetFiDiffXj(static_cast<int>(i), static_cast<int>(j), &tmp);
				grad[j] += 2 * tmp * nloptESO::F_[i];
			}
		}
	}

	return res2;
}

void nloptESOSolver::solve()
{
	nloptESO::eso_->GetAllVariables(nloptESO::x_.get());
	std::vector<double> lb(m_l.get(), m_l.get() + n_vars);
	std::vector<double> ub(m_u.get(), m_u.get() + n_vars);
	std::vector<double> x(nloptESO::x_.get(), nloptESO::x_.get() + n_vars);
	double opt_f;
	void* f_data = nullptr;

	constexpr int maxeval = 500;

	//{
	//	nlopt::opt opt(nlopt::algorithm::GD_STOGO_RAND, n_vars);
	//	opt.set_min_objective(nloptFuncApiImpl, f_data);
	//	opt.set_lower_bounds(lb);
	//	opt.set_upper_bounds(ub);
	//	// set tolerance
	//	opt.set_maxeval(maxeval);
	//	// perform
	//	nlopt::result res = opt.optimize(x, opt_f);
	//}
	 //does a local for better results
	{
		nlopt::opt opt(nlopt::algorithm::LN_COBYLA, n_vars);
		opt.set_min_objective(nloptFuncApiImpl, f_data);
		opt.set_lower_bounds(lb);
		opt.set_upper_bounds(ub);
		// set tolerance
		opt.set_maxeval(maxeval);
		// perform
		nlopt::result res = opt.optimize(x, opt_f);
	}

	// set x values on output
	std::copy(x.begin(), x.end(), nloptESO::x_.get());
	nloptESO::eso_->SetAllVariables(nloptESO::x_.get());
}

nloptESOSolver::nloptESOSolver(ESO* eso)
{
	nloptESO::eso_ = eso;

	n_vars = nloptESO::eso_->GetNumVars();
	n_eqns = nloptESO::eso_->GetNumEqns();

	m_l = std::unique_ptr<double[]>(new double[n_vars]);
	m_u = std::unique_ptr<double[]>(new double[n_vars]);

	nloptESO::jac_ = std::unique_ptr<double[]>(new double[n_vars*n_eqns]);
	nloptESO::x_ = std::unique_ptr<double[]>(new double[n_vars]);
	nloptESO::F_ = std::unique_ptr<double[]>(new double[n_eqns]);

	nloptESO::eso_->GetAllLowerBounds(m_l.get());
	nloptESO::eso_->GetAllUpperBounds(m_u.get());
}
