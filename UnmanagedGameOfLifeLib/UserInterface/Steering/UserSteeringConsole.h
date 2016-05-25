/*
 * UserSteeringConsole.h
 */

#ifndef USER_STEERING_CONSOLE_H_
#define USER_STEERING_CONSOLE_H_

#include "WorkDeployment\IUserGameManager.h"
#include "WorkDeployment\IUserPopulationRegistration.h"
#include "IUserSteeringConsole.h"

/**
	* \Class UserSteeringConsole
	* Class providing the user with game steering options
	*/
class __declspec(dllexport) UserSteeringConsole : public IUserSteeringConsole
{
	public:

		/**
		* \brief Class configuration
		*/
		struct Configuration
		{
			IUserGameManager* const pUserGameManager;
			IPopulationRegistration* const pPopulationRegistration;
		};
		/**
		* \brief CTOR
		*/
		UserSteeringConsole(Configuration& rConfiguration);

		/**
		* \brief DTOR
		*/
		virtual ~UserSteeringConsole();

		/**
		* \brief Provides pointer to Game Steering interface
		*/
		virtual IUserGameManager* const getGameSteering();

		/**
		* \brief Provides pointer to the Population management interface
		*/
		virtual IPopulationRegistration* const getPopulationManagment();

	private:
		Configuration m_rConfiguration;
};

#endif/* USER_STEERING_CONSOLE_H_ */