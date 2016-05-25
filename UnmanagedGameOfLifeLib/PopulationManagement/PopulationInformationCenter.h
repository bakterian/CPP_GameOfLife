/*
 * PopulationInformationCenter.h
 */


#ifndef POPULATION_INFORMATION_CENTER_H_
#define POPULATION_INFORMATION_CENTER_H_

#include <vector>
#include "../UserInterface/GatheringData/WorkDeployment/IPopulationInformationCenter.h"

/**
	* \Class PopulationInformationCenter
	* Provides information on the entire game of life population
	*/
class __declspec(dllexport) PopulationInformationCenter : public IPopulationInformationCenter
{
	public:
		struct PopulationAddressRange
		{
			int iMinXAdress;
			int iMaxXAdress;
			int iMinYAdress;
			int iMaxYAdress;
		};

		/**
		* \brief CTOR
		*/
		PopulationInformationCenter(std::vector<LifeEntity> &rLifeContainer);

		/**
		* \brief DTOR
		*/
		virtual ~PopulationInformationCenter();

		/**
		* \brief Provides a vector conntaing all life entities
		*/
		virtual std::vector<LifeEntity> getPopulation();

		/**
		* \brief Provides a population count
		*/
		virtual unsigned int getPopulationCount();
		
		/**
		* \brief Provides a population count
		*/
		virtual bool isLifePresent(LifeEntity cLifeEntity);

		/**
		* \brief Provide the number of neighbours of the given life entity
		* \return number of neighbours
		*/
		int getNeighboursCount(LifeEntity cLifeEntity);

		/**
		* \brief Provide the population address range
		* \return PopulationAddressRange structure holding the adress range
		*/
		PopulationAddressRange getPopulationAdressRange();

	private:
		std::vector<LifeEntity> &m_rLifeContainer;
};

#endif/* POPULATION_INFORMATION_CENTER_H_ */