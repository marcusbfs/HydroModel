#pragma once

#include <memory>
#include "CoreDLL.h"
#include <spdlog/spdlog.h>


namespace Solver {
	class SOLVERAPI Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetSolverLogger() { return s_SolverLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_SolverLogger;
	};
}
