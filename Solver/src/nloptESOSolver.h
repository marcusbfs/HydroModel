#pragma once

#include "ESO.h"
#include "NLAESOSolver.h"
#include <memory>

class nloptESOSolver : public NLAESOSolver {
public:
	// constructors
	nloptESOSolver(ESO* eso);
	~nloptESOSolver() = default;
	nloptESOSolver(const nloptESOSolver& other) = delete;
	nloptESOSolver& operator=(const nloptESOSolver& other) = delete;

	// solves system
	virtual void solve();

private:
	unsigned int n_eqns, n_vars;
	// lower boundaries
	std::unique_ptr<double[]> m_l;
	// upper boundaries
	std::unique_ptr<double[]> m_u;
};
