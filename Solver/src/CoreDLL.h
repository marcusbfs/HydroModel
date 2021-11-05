#pragma once

#ifdef SOLVER_DLL
	#ifdef SOLVER_DLL_EXPORT 
		/*Enabled as "export" while compiling the dll project*/
		#define SOLVERAPI __declspec(dllexport)  
	#else
		/*Enabled as "import" in the Client side for using already created dll file*/
		#define SOLVERAPI __declspec(dllimport)  
	#endif
#else
		#define SOLVERAPI
#endif
