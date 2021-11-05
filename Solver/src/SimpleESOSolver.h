#pragma once

#include "ESO.h"
#include "NLAESOSolver.h"
#include <memory>

class SimpleESOSolver : public NLAESOSolver {
public:
	// constructors
	SimpleESOSolver(ESO* eso);
	~SimpleESOSolver() = default;
	SimpleESOSolver(const SimpleESOSolver& other) = delete;
	SimpleESOSolver& operator=(const SimpleESOSolver& other) = delete;

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
