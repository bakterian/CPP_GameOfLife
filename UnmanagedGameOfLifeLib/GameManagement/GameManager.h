/*
 * GameManager.h
 */

#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <vector>
#include "../UserInterface/Steering/WorkDeployment/IUserGameManager.h"
#include "../PopulationManagement/PopulationInformationCenter.h"
#include "../PopulationManagement/PopulationRegistration.h"
#include "../Utils/Utils.h"

/**
	* \Class IPopoulationRegistration
	* Interface providing ways to manipulate lifes
	*/
class __declspec(dllexport) GameManager : public IUserGameManager
{
	public:

		/**
		* \brief Class Configuration
		*/
		struct Configuration 
		{
			PopulationRegistration&			rPopulationRegistration;
			PopulationInformationCenter&	rPopulationInfoCenter;
		};

		/**
		* \brief CTOR
		*/
		GameManager(Configuration& rConfiguration);

		/**
		* \brief DTOR
		*/
		virtual ~GameManager();

		/**
		* \brief Called to initiate a new life cycle
		*/
		virtual void startLifeCycle();

	protected:
		/**
		* \brief Perform a life cycle on the current population
		*/
		void handleExistingLife();

		/**
		* \brief Search for new life in the current population
		*/
		void searchForNewLife();

		/**
		* \brief Update population with the deaths and births
		*/
		void updatePopulation();

		/**
		* \brief Provides information on entity life expectation based on the number of neigbhours
		* \return true - will live another day
		* \return false - will die due to overcrowding or loneliness
		*/
		bool willTheEntityLiveOn(int iNeighbourCount);

	private:
		Configuration &m_rConfiguration;
		std::vector<LifeEntity> m_LifesToKill;
		std::vector<LifeEntity> m_LifesToCreate;
};

#endif/* GAME_MANAGER_H_ */