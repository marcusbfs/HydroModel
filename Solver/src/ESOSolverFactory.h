#pragma once

#include "ESO.h"
#include "NLAESOSolver.h"

#include "CoreDLL.h"

extern "C" {

	namespace ESOSolverFactory {
		enum class Solver {
			nlopt, simple, newton_mod
		};

		SOLVERAPI NLAESOSolver* getESOSolver(const Solver& solver, ESO* const eso);
	};
}
