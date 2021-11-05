#include "ESOSolverFactory.h"
#include "ESO.h"

#include "SimpleESOSolver.h"
#include "NewtonModifiedESOSolver.h"
#include "nloptESOSolver.h"

NLAESOSolver* ESOSolverFactory::getESOSolver(const Solver& solver, ESO* const eso)
{
	switch (solver) {
	case Solver::simple:
		return new SimpleESOSolver(eso);
	case Solver::newton_mod:
		return new NewtonModifiedESOSolver(eso);
	case Solver::nlopt:
		return new nloptESOSolver(eso);
	default:
		return nullptr;
	}
}
