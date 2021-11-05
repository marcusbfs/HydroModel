#include "EqNode.h"
#include <cmath>

// Constructors
EqNode::EqNode()
{
}

// Defines operator only
EqNode::EqNode(const OperatorType& o)
	: op(o)
{
}

// Single operator OP(LEFT)
EqNode::EqNode(const EqNodePtr& l, const OperatorType& o)
	: left(l)
	, op(o)
{
}

// Normal operator left OP right
EqNode::EqNode(const EqNodePtr& l, const EqNodePtr& r, const OperatorType& o)
	: op(o)
	, left(l)
	, right(r)
{
}

// Double value parameter
EqNode::EqNode(const double& val)
	:v(val)
	, op(OperatorType::Number)
{
}

// Double value variable
EqNode::EqNode(const double& val, const OperatorType& o)
	: v(val)
	, op(o)
{
}

// Get the current value from node
double EqNode::value() const noexcept
{
	return v;
}

// Update current value from node and returns it
double EqNode::getValue()
{
	if (!isLeaf())
		switch (op) {
		case OperatorType::Add:
			this->v = left->getValue() + right->getValue();
			break;
		case OperatorType::Subtract:
			this->v = left->getValue() - right->getValue();
			break;
		case OperatorType::Multiply:
			this->v = left->getValue() * right->getValue();
			break;
		case OperatorType::Divide: {
			// a / b
			// if b = 0; return 0
			const auto b = right->getValue();
			this->v = areEqual(b, 0, 1e-12) ? 0.0 : left->getValue() / b;
			break;
		}
		case OperatorType::Power:
			this->v = std::pow(left->getValue(), right->getValue());
			break;
		case OperatorType::Exp:
			this->v = std::exp(left->getValue());
			break;
		case OperatorType::Ln: {
			// ln(a). if a < 0; return 0.0
			const auto a = left->getValue();
			this->v = (a < 0) ? 0.0 : std::log(a);
			break;
		}
		case OperatorType::Log10: {
			// log10(a). if a < 0; return 0.0
			const auto a = left->getValue();
			this->v = (a < 0) ? 0.0 : std::log10(a);
			break;
		}
		case OperatorType::Sin:
			this->v = std::sin(left->getValue());
			break;
		case OperatorType::Cos:
			this->v = std::cos(left->getValue());
			break;
		}
	return this->v;
}

// Get derivative of current node w.r. to var
double EqNode::getDerValue(const EqNode& var) const
{
	if (isLeaf())
		if (this == &var)
			return 1.0;
		else
			return 0.0;
	else
		switch (op) {
		case OperatorType::Add:
			return left->getDerValue(var) + right->getDerValue(var);
			break;
		case OperatorType::Subtract:
			return left->getDerValue(var) - right->getDerValue(var);
			break;
		case OperatorType::Multiply:
			return right->v * left->getDerValue(var) + left->v * right->getDerValue(var);
			break;
		case OperatorType::Divide: {
			// is dividing by right-v. se we make sure it is not 0
			double right_v = right->v;
			if (!areEqual(right_v, 0, 1e-12))
				return (right->v * left->getDerValue(var) - left->v * right->getDerValue(var)) / (right->v * right->v);
			else
				return 0.0;
			break;
		}
		case OperatorType::Power: {
			// d(f(x) ^g(x))/dx = f^g * [ g' *ln(f) + g*f'/f ]
			const auto f = this->left->v;
			const auto g = this->right->v;
			const auto fp = this->left->getDerValue(var);
			const auto gp = this->right->getDerValue(var);
			// we have to check if f is not negative and if f is not 0
			//return pow(f, g) * (gp * log(f) + g * fp / f);
			//const double first_term = (f < 0) ? 0.0 : gp * log(f);
			//const double second_term = areEqual(f, 0, 1e-11) ? 0.0 : g * fp / f;
			//return pow(f, g) * (first_term + second_term);
			return pow(f, g) * (((f < 0) ? 0.0 : gp * log(f)) + (areEqual(f, 0, 1e-11) ? 0.0 : g * fp / f));
			break;
		}
		case OperatorType::Exp:
			return std::exp(left->v) * left->getDerValue(var);
			break;
		case OperatorType::Ln: {
			// check if dividend is not 0
			return areEqual(left->v, 0, 1e-12) ? 0.0 : left->getDerValue(var) / left->v;
			break;
		}
		case OperatorType::Log10: {
			// check if dividend is not 0
			return areEqual(left->v, 0, 1e-12) ? 0.0 : (left->getDerValue(var) / left->v) / std::log(10.0);
			break;
		}
		case OperatorType::Sin:
			return std::cos(left->v) * left->getDerValue(var);
			break;
		case OperatorType::Cos:
			return -std::sin(left->v) * left->getDerValue(var);
			break;
		default:
			return 0.0;
		} // end of switch
}

// Return true if current node depends on var
bool EqNode::depends(const EqNode& var) const {
	if (this->isLeaf())
		return this == &var;

	return (right == nullptr) ? left->depends(var) : (left->depends(var) || right->depends(var));
	//else
	//	// If right is null, check only left
	//	if (right == nullptr)
	//		return left->depends(var);
	//// Else, check if at least one of them is
	//	else
	//		return (left->depends(var) || right->depends(var));
}

// Return EqNode which represents the derivative of current EqNode
void EqNode::derive(const EqNode& var, EqNodePtr& derivRoot)
{
	if (!derivRoot)
		derivRoot = std::make_shared<EqNode>();
	if (isLeaf()) {
		derivRoot->op = OperatorType::Parameter;
		if (depends(var))
			derivRoot->v = 1.0;
		else
			derivRoot->v = 0.0;
	}
	else
		switch (op) {
		case OperatorType::Add:
		case OperatorType::Subtract: {
			derivRoot->op = op;
			this->left->derive(var, derivRoot->left);
			this->right->derive(var, derivRoot->right);
			break;
		}
		case OperatorType::Multiply: {
			// derivRoot->left = this->left * derive(this->right)
			// derivRoot->right = this->right * derive(this->left)
			// derivRoot->op = Add
			derivRoot->op = OperatorType::Add;
			// treating derivRoot->left
			derivRoot->left = std::make_shared<EqNode>();
			derivRoot->left->op = OperatorType::Multiply;
			derivRoot->left->left = this->left;
			this->right->derive(var, derivRoot->left->right);
			// treating derivRoot->right
			derivRoot->right = std::make_shared<EqNode>();
			derivRoot->right->op = OperatorType::Multiply;
			derivRoot->right->left = this->right;
			this->left->derive(var, derivRoot->right->right);
			break;
		}
		case OperatorType::Divide: {
			// derivRoot->left = derivative(this->left) / this->right
			// derivRoot->right = this->left * derivative(this->right) / (this->right * this->right)
			// derivRoot->op = Substract
			// d(f(x)/g(x))/dx = f' / g - g' * f/ g^2
			// f = this->left;
			// g = this->right;
			derivRoot->op = OperatorType::Subtract;
			// treating derivRoot->left
			derivRoot->left = std::make_shared<EqNode>(OperatorType::Divide);
			this->left->derive(var, derivRoot->left->left);
			derivRoot->left->right = this->right; // ok
			// treating derivRoot->right
			derivRoot->right = std::make_shared<EqNode>(OperatorType::Divide);
			// derivRoot->right->left = g' * f
			// derivRoot->right->right = g * g
			derivRoot->right->left = std::make_shared<EqNode>(OperatorType::Multiply);
			derivRoot->right->left->left = this->left;
			this->right->derive(var, derivRoot->right->left->right); //ok

			derivRoot->right->right = std::make_shared<EqNode>(OperatorType::Multiply);
			derivRoot->right->right->left = this->right;
			derivRoot->right->right->right = this->right;
			break;
		}
		case OperatorType::Power: {
			// derivRoot->left = this->left * derive(this->right)
			// derivRoot->right = this->right * derive(this->left)
			// derivRoot->op = Multiply
			// d(f(x) ^g(x))/dx = f^g    *    [ g' *ln(f) + g*f'/f ]
			// f = this->left;
			// g = this->right;
			derivRoot->op = OperatorType::Multiply;
			// treating derivRoot->left
			derivRoot->left = std::make_shared<EqNode>(OperatorType::Power);
			derivRoot->left->left = this->left;
			derivRoot->left->right = this->right; // ok
			// treating derivRoot->right : g' *ln(f) + g*f'/f
			derivRoot->right = std::make_shared<EqNode>(OperatorType::Add);
			// treating derivRoot->right->left : g' *ln(f)
			derivRoot->right->left = std::make_shared<EqNode>(OperatorType::Multiply);
			this->right->derive(var, derivRoot->right->left->left);
			derivRoot->right->left->right = std::make_shared<EqNode>(OperatorType::Ln);
			derivRoot->right->left->right->left = this->left; //ok
			// treating derivRoot->right->right : g*f'/f
			derivRoot->right->right = std::make_shared<EqNode>(OperatorType::Multiply);
			derivRoot->right->right->left = this->right;
			derivRoot->right->right->right = std::make_shared<EqNode>(OperatorType::Divide);
			this->left->derive(var, derivRoot->right->right->right->left);
			derivRoot->right->right->right->right = this->left; // ok
			break;
		}
		case OperatorType::Exp:
		{
			// DerivRoot->op = Multiply
			// derivRoot->left = derive(this->left)
			// derivRoot->right = exp(this->left)
			derivRoot->op = OperatorType::Multiply;
			// Dealing with derivRoot->left
			this->left->derive(var, derivRoot->left);
			// Dealing with derivRoot->right
			derivRoot->right = std::make_shared<EqNode>(OperatorType::Exp);
			derivRoot->right->left = this->left;
			break;
		}
		case OperatorType::Ln:
		{
			// DerivRoot->op = Divide
			// derivRoot->left = derive(this->left)
			// derivRoot->right = this->left
			// d(ln(f(x))/dx = f'/f
			// f = this->left
			derivRoot->op = OperatorType::Divide;
			// Dealing with derivRoot->left
			this->left->derive(var, derivRoot->left);
			// Dealing with derivRoot->right
			derivRoot->right = this->left;
			break;
		}
		case OperatorType::Log10:
		{
			// DerivRoot->op = Divide
			// derivRoot->left = derive(this->left)
			// derivRoot->right = this->left
			// d(log10(f(x))/dx = (f'/f ) / ln(10)
			// f = this->left
			derivRoot->op = OperatorType::Divide;
			// Dealing with derivRoot->left
			derivRoot->left = std::make_shared<EqNode>(OperatorType::Divide);
			this->left->derive(var, derivRoot->left->left);
			derivRoot->left->right = this->left;
			// Dealing with derivRoot->right
			derivRoot->right = std::make_shared<EqNode>(std::log(10.0));
			break;
		}
		case OperatorType::Sin:
		{
			// DerivRoot->op = Multiply
			// derivRoot->left = derive(this->left)
			// derivRoot->right = cos(this->left)
			derivRoot->op = OperatorType::Multiply;
			// Dealing with derivRoot->left
			this->left->derive(var, derivRoot->left);
			// Dealing with derivRoot->right
			derivRoot->right = std::make_shared<EqNode>(OperatorType::Cos);
			derivRoot->right->left = this->left;
			break;
		}
		case OperatorType::Cos:
		{
			// DerivRoot->op = Multiply
			// derivRoot->left = (-1.0) * derive(this->left)
			// derivRoot->right = sin(this->left)
			derivRoot->op = OperatorType::Multiply;
			// Dealing with derivRoot->left
			derivRoot->left = std::make_shared<EqNode>(OperatorType::Multiply);
			this->left->derive(var, derivRoot->left->left);
			derivRoot->left->right = std::make_shared<EqNode>(-1.0);
			// Dealing with derivRoot->right
			derivRoot->right = std::make_shared<EqNode>(OperatorType::Sin);
			derivRoot->right->left = this->left;
			break;
		}
		} // end of switch
}

bool EqNode::hasUpperBound() const noexcept
{
	return m_hasUpperBound;
}

bool EqNode::hasLowerBound() const noexcept
{
	return m_hasLowerBound;
}

double EqNode::getUpperBound() const noexcept
{
	return m_upper;
}

double EqNode::getLowerBound() const noexcept
{
	return m_lower;
}

// Returns true if current node is a leaf node (terminal node)
bool EqNode::isLeaf() const noexcept
{
	return left == nullptr && right == nullptr;
}

bool EqNode::isOperator() const noexcept
{
	if (this->isLeaf())
		return false;

	switch (this->op) 
	{
	case OperatorType::Variable:
	case OperatorType::Parameter:
	case OperatorType::Number:
	case OperatorType::Equal:
		return false;
	default:
		return true;
	}
}

bool EqNode::isNumber() const noexcept
{
	return this->op == OperatorType::Number;
}

bool EqNode::areEqual(const double& a, const double& b, const double& tol) const noexcept
{
	return abs(a - b) < tol;
}

void EqNode::setUpperBound(const double& upper)
{
	m_hasUpperBound = true;
	m_upper = upper;
}

void EqNode::setLowerBound(const double& lower)
{
	m_hasLowerBound = true;
	m_lower = lower;
}

bool EqNode::isInBoundaries() const
{
	return (this->v >= m_lower && this->v <= m_upper);
}

void EqNode::correctValueInsideBoundaries()
{
	this->v = m_hasLowerBound ? (v < m_lower ? m_lower : v) : v;
	this->v = m_hasUpperBound ? (v > m_upper ? m_upper : v) : v;
}

void EqNode::simplify()
{
	if (!isLeaf()) {
		if (left) left->simplify();
		if (right) right->simplify();
		if (left && right &&
			left->op == OperatorType::Number &&
			right->op == OperatorType::Number
			) {
			this->v = this->getValue();
			this->op = OperatorType::Number;
			left = nullptr;
			right = nullptr;
		}
	}
}
