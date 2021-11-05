#include "SolverLog.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace Solver {

	std::shared_ptr<spdlog::logger> s_SolverLogger;

	void Log::Init()
	{
		s_SolverLogger = spdlog::basic_logger_mt("solver_logger", "solverlogger.txt");
		s_SolverLogger->set_level(spdlog::level::trace);
	}
}

