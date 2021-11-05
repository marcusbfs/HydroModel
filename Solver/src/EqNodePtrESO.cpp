#include "EqNodePtrESO.h"

EqNodePtrESO::EqNodePtrESO(std::vector<EqNodePtr>* eqns, std::vector<EqNodePtr>* vars)
{
	m_eqns = eqns;
	m_vars = vars;
	m_num_eqns = m_eqns->size();
	m_num_vars = m_vars->size();
}

unsigned long EqNodePtrESO::GetNumVars() const
{
	return static_cast<unsigned long>(m_num_vars);
}

unsigned long EqNodePtrESO::GetNumEqns() const
{
	return static_cast<unsigned long>(m_num_eqns);
}

void EqNodePtrESO::SetAllVariables(const double* const vars)
{
	for (unsigned int i = 0; i < m_num_vars; ++i)
		(*m_vars)[i]->v = vars[i];
}

void EqNodePtrESO::GetAllVariables(double* vars)
{
	for (unsigned int i = 0; i < m_num_vars; ++i)
		vars[i] = (*m_vars)[i]->v;
}

void EqNodePtrESO::GetAllResiduals(double* res) const
{
	for (unsigned int i = 0; i < m_num_eqns; ++i)
		res[i] = (*m_eqns)[i]->getValue();
}

// Stored in row major order. Supossing Jacobian matrix with N rows and M columns Jacobian(N, M):
// Jacobian[i, j]  = i*(N-1) + j
void EqNodePtrESO::getAllJacobianValues(double* jacvals) const
{
	for (unsigned int i = 0; i < m_num_eqns; ++i)
		for (unsigned int j = 0; j < m_num_vars; ++j) {
			jacvals[i * (m_num_vars)+j] =
				(*m_eqns)[i]->getDerValue(*(*m_vars)[j]);
		}
}

void EqNodePtrESO::GetAllLowerBounds(double* l) const
{
	for (unsigned int i = 0; i < m_num_vars; ++i)
		l[i] = (*m_vars)[i]->getLowerBound();
}
void EqNodePtrESO::GetAllUpperBounds(double* u) const
{
	for (unsigned int i = 0; i < m_num_vars; ++i)
		u[i] = (*m_vars)[i]->getUpperBound();
}

void EqNodePtrESO::correctBoundaries()
{
	for (const auto& var : *m_vars)
		var->correctValueInsideBoundaries();
}

void EqNodePtrESO::GetFiDiffXj(const int& i, const int& j, double* ans) const
{
	*ans = (*m_eqns)[i]->getDerValue(*(*m_vars)[j]);
}
