#pragma once

#ifdef HYDROMOELS_DLL
	#ifdef  HYDROMODELS_UIAPI_EXPORTS 
	/*Enabled as "export" while compiling the dll project*/
	#define UIAPI __declspec(dllexport)  
	#else
	/*Enabled as "import" in the Client side for using already created dll file*/
	#define UIAPI __declspec(dllimport)  
	#endif
#else
	#define UIAPI 
#endif

#include <string>
#include <vector>
#include <memory>
#include <map>


extern "C" {
	struct HydroModelsObserver {
		virtual void UIAPI update() = 0;
	};
}

extern "C" {
	class HydroModelsUIAPI
	{
	public:
		// == constructors ==
		UIAPI HydroModelsUIAPI();
		UIAPI ~HydroModelsUIAPI();
		UIAPI HydroModelsUIAPI(const HydroModelsUIAPI& other) = delete;
		UIAPI HydroModelsUIAPI& operator=(const HydroModelsUIAPI& other) = delete;
		// == methods ==
		// sets inputs file
		void UIAPI setInputFile(const std::string& str);
		// perform calculations and update fields
		void UIAPI calculate();
		// get standard formatted string
		std::string UIAPI getStandardFormattedString() const;
		// get vector of model names
		std::vector<std::string> UIAPI getModelsName() const;
		// get vector of output headers
		std::vector<std::string> UIAPI getOutputHeaders() const;
		// get vector of output values
		std::map<std::string, std::vector<double>> UIAPI getModelOutputValues(const std::string& model_name) const;
		// subscribe observer
		void UIAPI subscribeObserver(HydroModelsObserver* observer);
		// remove observer
		void UIAPI removeObserver(HydroModelsObserver* observer);
		// notify observers
		void UIAPI notifyObservers() const;
	private:
		// Pimpl
		class HydroModelsUIAPI_Impl;
		std::unique_ptr<HydroModelsUIAPI_Impl> m_Impl;
	};

}
