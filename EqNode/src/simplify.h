#pragma once

#include "EqNode.h"

namespace SimplifyEqNode {
	// auto simplify
	// it is not working properly
	bool simplify(EqNode& root);
	// Join two childs numbers.
	// returns true if it changed
	bool joinNumbers(EqNode& root);
}
