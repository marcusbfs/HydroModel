#ifndef NEWTON_METHOD_EQ_NODE_H
#define NEWTON_METHOD_EQ_NODE_H

#ifndef EQNODE_H
#include "EqNode.h"
#endif
#include <vector>

namespace NewtonEqNode {
	struct Constraints {
		std::vector<bool> hasLower, hasUpper;
		std::vector<double> lower, upper;
	};

	void solve(EqNodePtr& root, EqNodePtr var);

	void NLASolve(const int& n, std::vector< EqNodePtr >& eqs,
	std::vector < EqNodePtr >& vars, const double& tol);

}

#endif // NEWTON_METHOD_EQ_NODE_H
