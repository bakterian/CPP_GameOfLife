/*
 * IUserSteeringConsole.h
 */

#ifndef IUSER_STEERING_CONSOLE_H_
#define IUSER_STEERING_CONSOLE_H_

#include "WorkDeployment\IUserGameManager.h"
#include "WorkDeployment\IUserPopulationRegistration.h"

/**
	* \Class IUserSteeringConsole
	* Interface providing the user with game steering options
	*/
class __declspec(dllexport) IUserSteeringConsole
{
	public:

		/**
		* \brief CTOR
		*/
		IUserSteeringConsole() { };

		/**
		* \brief DTOR
		*/
		virtual ~IUserSteeringConsole() { };

		/**
		* \brief Provides pointer to Game Steering interface
		*/
		virtual IUserGameManager* const getGameSteering() = 0;

		/**
		* \brief Provides pointer to the Population management interface
		*/
		virtual IPopulationRegistration* const getPopulationManagment() = 0;
};

#endif/* IUSER_STEERING_CONSOLE_H_ */