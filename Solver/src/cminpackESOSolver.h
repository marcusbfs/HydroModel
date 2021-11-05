#pragma once

#include "ESO.h"
#include "NLAESOSolver.h"
#include <memory>

class cminpackESOSolver : public NLAESOSolver {
public:
	// constructors
	cminpackESOSolver(ESO* eso);
	~cminpackESOSolver() = default;
	cminpackESOSolver(const cminpackESOSolver& other) = delete;
	cminpackESOSolver& operator=(const cminpackESOSolver& other) = delete;

	// solves system
	virtual void solve();

private:
	unsigned int n_eqns, n_vars;
	// lower boundaries
	std::unique_ptr<double[]> m_l;
	// upper boundaries
	std::unique_ptr<double[]> m_u;
};
