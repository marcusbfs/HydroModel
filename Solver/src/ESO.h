#pragma once

// class to represente an system of equations of the form F(x)
class ESO {
public:
	// get number of variables
	virtual unsigned long GetNumVars() const = 0;
	// get number of equations
	virtual unsigned long GetNumEqns() const = 0;
	// set the values of all variables
	virtual void SetAllVariables(const double* const vars) = 0;
	// get all adress of variables
	virtual void GetAllVariables(double* vars) = 0;
	// get all variables lower bounds
	virtual void GetAllLowerBounds(double* l) const = 0;
	// get all variables upper bounds
	virtual void GetAllUpperBounds(double* u) const = 0;
	// get derivative of function i w.r.t. variable j
	virtual void GetFiDiffXj(const int& i, const int& j, double* ans) const = 0;
	// get all residuals
	virtual void GetAllResiduals(double* res) const = 0;
	// get all jacobian values
	// Stored in row major order. Supossing Jacobian matrix with N rows and M columns Jacobian(N, M):
	// Jacobian[i, j]  = i*(M) + j
	virtual void getAllJacobianValues(double* jacvals) const = 0;
	// correct boundaries
	virtual void correctBoundaries() = 0;
};
