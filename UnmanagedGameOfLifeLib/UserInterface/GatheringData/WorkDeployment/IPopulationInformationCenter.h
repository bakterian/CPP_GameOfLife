/*
 * IPopulationInformationCenter.h
 */

#ifndef IPOPULATION_INFORMATION_CENTER_H_
#define IPOPULATION_INFORMATION_CENTER_H_

#include <vector>
#include "../../../PopulationManagement/PopulationData/LifeEntity.h"

/**
	* \Class IPopulationInformationCenter
	* Interface providing information on the entire game of life population
	*/
class __declspec(dllexport) IPopulationInformationCenter
{
	public:

		/**
		* \brief CTOR
		*/
		IPopulationInformationCenter(){ };

		/**
		* \brief DTOR
		*/
		virtual ~IPopulationInformationCenter() { };

		/**
		* \brief Provides a vector conntaing all life entities
		*/
		virtual std::vector<LifeEntity> getPopulation() = 0;

		/**
		* \brief Provides a population count
		*/
		virtual unsigned int getPopulationCount() = 0;
		
		/**
		* \brief Provides a population count
		*/
		virtual bool isLifePresent(LifeEntity cLifeEntity) = 0;
};

#endif/* IPOPULATION_INFORMATION_CENTER_H_ */