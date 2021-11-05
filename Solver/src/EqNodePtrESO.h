#pragma once

#include "ESO.h"
#include "EqNode.h"

#include "CoreDLL.h"

#include <vector>

extern "C" {


	class EqNodePtrESO : public ESO {
	public:
		// constructors
		SOLVERAPI EqNodePtrESO(std::vector<EqNodePtr>* eqns, std::vector<EqNodePtr>* vars);
		~EqNodePtrESO() = default;
		EqNodePtrESO(const EqNodePtrESO& other) = delete;
		EqNodePtrESO& operator=(const EqNodePtrESO& other) = delete;

		// methods
		// get number of variables
		virtual unsigned long SOLVERAPI GetNumVars() const;
		// get number of equations
		virtual unsigned long SOLVERAPI GetNumEqns() const;
		// set the values of all variables
		virtual void SOLVERAPI SetAllVariables(const double* const vars);
		// get all adress of variables
		virtual void SOLVERAPI GetAllVariables(double* vars);
		// get all residuals
		virtual void SOLVERAPI GetAllResiduals(double* res) const;
		// get all jacobian values
		// Stored in row major order. Supossing Jacobian matrix with N rows and M columns Jacobian(N, M):
		// Jacobian[i, j]  = i*(M) + j
		virtual void SOLVERAPI getAllJacobianValues(double* jacvals) const;
		// get all variables lower bounds
		virtual void SOLVERAPI GetAllLowerBounds(double* l) const;
		// get all variables upper bounds
		virtual void SOLVERAPI GetAllUpperBounds(double* u) const;
		// correct boundaries
		virtual void SOLVERAPI correctBoundaries();
		// 
		virtual void SOLVERAPI GetFiDiffXj(const int& i, const int& j, double* ans) const;

	public:
		std::vector<EqNodePtr>* m_eqns;
		std::vector<EqNodePtr>* m_vars;
		size_t m_num_eqns;
		size_t m_num_vars;
	};
}
