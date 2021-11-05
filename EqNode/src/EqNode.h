#ifndef EQNODE_H
#define EQNODE_H

#include <memory>

class EqNode;
typedef std::shared_ptr<EqNode> EqNodePtr;

// Class for a equation node
class EqNode {
public:
	// Type of nodes
	enum class OperatorType {
		Variable, Parameter, Number, Equal,
		Add, Subtract, Multiply, Divide, Power,
		Sin, Cos, Exp, Ln, Log10
	};

public:
	// === Constructors ===
	// Constructor
	EqNode();
	// Defines operator only
	EqNode(const OperatorType& o);
	// Single operator OP(LEFT)
	EqNode(const EqNodePtr& l, const OperatorType& o);
	// Normal operator left OP right
	EqNode(const EqNodePtr& l, const EqNodePtr& r, const OperatorType& o);
	// Double value
	EqNode(const double& val);
	// Double value variable
	EqNode(const double& val, const OperatorType& o);

public:
	// === Methods ===
	// Get the current value from node
	double value() const noexcept;
	// Update current value from node and returns it
	double getValue();
	// Get derivative of current node w.r. to var
	double getDerValue(const EqNode& var) const;
	// Return true if current node depends on var
	bool depends(const EqNode& var) const;
	// Return derivRoot which represents the derivative of current EqNode w.r.t. var
	void derive(const EqNode& var, EqNodePtr& derivRoot);
	// check if node has upper bound
	bool hasUpperBound() const noexcept;
	// check if node has lower bound
	bool hasLowerBound() const  noexcept;
	// returns upper bound value
	double getUpperBound() const noexcept;
	// returns lower bound value
	double getLowerBound() const noexcept;
	// sets upper bound value
	void setUpperBound(const double& upper);
	// sets lower bound value
	void setLowerBound(const double& lower);
	// check if value is inside boundaries
	bool isInBoundaries() const;
	// correct value if outside boundaries
	void correctValueInsideBoundaries();
	// simplify eqnode. Ex: 1 + 2 -> 3
	void simplify();
	// Returns true if current node is a leaf node (terminal node)
	bool isLeaf() const noexcept;
	// Return if current node is operator
	bool isOperator() const noexcept;
	// Return if current node is number
	bool isNumber() const noexcept;

public:
	// === Parameters ===
	// Numerical value assigned to this node
	double v{ 0.0 };
	// Type of this node operator
	OperatorType op = OperatorType::Parameter;
	// Left child of this node
	EqNodePtr left{ nullptr };
	// Right child of this node
	EqNodePtr right{ nullptr };
private:
	// has lower bound
	bool m_hasLowerBound{ false };
	// has upper bound
	bool m_hasUpperBound{ false };
	double m_upper{ 0.0 };
	double m_lower{ 0.0 };

protected:
	// === Methods ===
	// Return if two doubles are equal given a tolerance
	bool areEqual(const double& a, const double& b, const double& tol) const noexcept;
};

#endif // EQNODE_H
