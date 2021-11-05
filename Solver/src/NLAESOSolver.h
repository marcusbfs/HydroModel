#pragma once

#include <limits>
#include <memory>

//typedef std::unique_ptr<NLAESOSolver> NLAESOSolverPtr;

class NLAESOSolver {
public:
	// solve ESO
	virtual void solve() = 0;
	// set tolerance
	virtual inline void setTol(const double& tol) { m_tol = tol; };

protected:
	double m_tol = 1e2*std::numeric_limits<double>::epsilon();
};
