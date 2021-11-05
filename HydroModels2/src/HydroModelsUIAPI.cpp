#include "HydroModelsUIAPI.h"

#include "EqNode.h"
#include "NewtonMethodEqNode.h"
#include "HydroModelsInterpreter.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>

class HydroModelsUIAPI::HydroModelsUIAPI_Impl {
public:
	// == constructor ==
	HydroModelsUIAPI_Impl(HydroModelsUIAPI* const p)
		: parent(p)
	{
	}
	// == methods
	void calculate() {
		std::map<std::string, std::map<std::string, EqNodePtr>> modelVars;
		std::map<std::string, std::map<std::string, EqNodePtr>> modelPars;
		std::map<std::string, std::vector<EqNodePtr>> modelEquations;
		std::map<std::string, std::vector<std::string>> modelHeaders;
		std::map<std::string, std::vector<EqNodePtr>> modelValuesOutput;
		std::map<std::string, std::vector<double>> modelMultipliers;

		unsigned int n_initial, n_final;

		// reset to vectors
		outputHeaders.clear();
		modelNames.clear();

		interp.run(inputFilePath, &n_initial, &n_final,
			modelVars, modelPars,
			modelEquations, modelHeaders, modelValuesOutput, modelMultipliers,
			modelNames, outputHeaders,
			ModelOutputValues);

		//bool get_headers = true;

		//for (const auto& modelHeader : modelHeaders) {
		//	const auto& model_name = modelHeader.first;
		//	// model name
		//	modelNames.push_back(model_name);

		//	const std::vector<EqNodePtr>& modelValues = modelValuesOutput[model_name];
		//	const std::vector<double>& modelMuls = modelMultipliers[model_name];
		//	const std::vector<std::string>& modelHeaders_vec = modelHeader.second;

		//	for (size_t i = 0; i < modelValues.size(); ++i) {
		//		if (get_headers)
		//			outputHeaders.push_back(modelHeaders_vec[i]);
		//	}
		//	get_headers = false;
		//}
		return;
	} // end of calculate
	// == parameters ==
	HydroModelsUIAPI* parent = nullptr;
	std::string inputFilePath = "";
	std::vector<std::string> modelNames;
	std::vector<std::string> outputHeaders;
	std::map<std::string, std::map<std::string, std::vector<double> > > ModelOutputValues;
	HydroModelsInterpreter interp;
	std::vector< HydroModelsObserver*> observers;
};

HydroModelsUIAPI::HydroModelsUIAPI()
{
	m_Impl = std::make_unique<HydroModelsUIAPI_Impl>(this);
}

HydroModelsUIAPI::~HydroModelsUIAPI() = default;

//UIAPI void HydroModelsUIAPI::setInputFile(const std::string & inputfile)
void HydroModelsUIAPI::setInputFile(const std::string & str)
{
	m_Impl->inputFilePath = str;
}

void UIAPI HydroModelsUIAPI::calculate()
{
	m_Impl->calculate();
	// notify that calculation is done
	this->notifyObservers();
}

std::string HydroModelsUIAPI::getStandardFormattedString() const
{
	return m_Impl->interp.getOutputString();
}

std::vector<std::string> HydroModelsUIAPI::getModelsName() const
{
	return m_Impl->modelNames;
}

std::vector<std::string> HydroModelsUIAPI::getOutputHeaders() const
{
	return m_Impl->outputHeaders;
}

std::map<std::string, std::vector<double>> HydroModelsUIAPI::getModelOutputValues(const std::string & model_name) const
{
	return m_Impl->ModelOutputValues[model_name];
}

void HydroModelsUIAPI::subscribeObserver(HydroModelsObserver * observer)
{
	m_Impl->observers.push_back(observer);
}

void HydroModelsUIAPI::removeObserver(HydroModelsObserver * observer)
{
	m_Impl->observers.erase(
		std::remove(
			m_Impl->observers.begin(), m_Impl->observers.end(), observer
		),
		m_Impl->observers.end()
	);
}

void HydroModelsUIAPI::notifyObservers() const
{
	for (const auto& observer : m_Impl->observers)
		observer->update();
}
