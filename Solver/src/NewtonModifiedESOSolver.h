#pragma once

#include "ESO.h"
#include "NLAESOSolver.h"
#include <memory>

class NewtonModifiedESOSolver : public NLAESOSolver {
public:
	// constructors
	NewtonModifiedESOSolver(ESO* eso);
	~NewtonModifiedESOSolver() = default;
	NewtonModifiedESOSolver(const NewtonModifiedESOSolver& other) = delete;
	NewtonModifiedESOSolver& operator=(const NewtonModifiedESOSolver& other) = delete;

	// solves system
	virtual void solve();

private:
	// properties
	ESO* m_ESO;
	unsigned int n_eqns, n_vars;
	// reference to variables;
	std::unique_ptr<double[]> jac;
	std::unique_ptr<double[]> xx;
	std::unique_ptr<double[]> FF;
};
