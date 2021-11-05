#include "simplify.h"

bool SimplifyEqNode::simplify(EqNode& root)
{
	bool changed = joinNumbers(root);
	while (joinNumbers(root));
	return changed;
}

bool SimplifyEqNode::joinNumbers(EqNode& root)
{
	bool changed = false;
	if (root.isOperator()) {

		bool left_changed = false;
		bool right_changed = false;

		if (root.left)
			left_changed = joinNumbers(*root.left);
		if (root.right)
			right_changed = joinNumbers(*root.right);

		changed = left_changed || right_changed;

		if (
			root.left
			&& root.right)
			if (
				root.left->isNumber()
				&& root.right->isNumber()
				) {
				root.getValue();
				root.op = EqNode::OperatorType::Number;
				root.left = nullptr;
				root.right = nullptr;
				changed = true;
			}
	}
	return changed;
}
