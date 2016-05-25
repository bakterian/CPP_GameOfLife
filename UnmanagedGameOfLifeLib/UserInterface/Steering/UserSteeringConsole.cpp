/*
 * UserSteeringConsole.cpp
 */
#include "UserSteeringConsole.h"

UserSteeringConsole::UserSteeringConsole(Configuration& rConfiguration):
	IUserSteeringConsole(),
	m_rConfiguration(rConfiguration)
{ 

};

 UserSteeringConsole::~UserSteeringConsole() 
 {

 };

IUserGameManager* const UserSteeringConsole::getGameSteering()
{
	return m_rConfiguration.pUserGameManager;
}

IPopulationRegistration* const UserSteeringConsole::getPopulationManagment()
{
	return m_rConfiguration.pPopulationRegistration;
}
