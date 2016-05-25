// UnmanagedGameOfLifeLib.cpp : Defines the exported functions for the DLL application.
//
#include <Windows.h>
#include "UnmanagedGameOfLifeLib.h"

LifeAddress cLifeAddress(10,10);
LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

std::vector<LifeEntity> cPopulationContainer;

std::vector<IPopulationChangeListener> cPopChangeListeners;
PopulationRegistration::Configuration sPopRegConf = 
{
	cPopulationContainer,
	cPopChangeListeners
};

PopulationInformationCenter cPopulationInfoCenter(cPopulationContainer);
PopulationRegistration cPopulationRegistration(sPopRegConf);
GameManager::Configuration GameMenegerConf =
{
	cPopulationRegistration,
	cPopulationInfoCenter,
};

GameManager cGameManager(GameMenegerConf);

UserInfoCenter::Configuration UserInfoCenterCfg =
{
	&cPopulationInfoCenter
};
UserInfoCenter cUserInfoCenter(UserInfoCenterCfg);

UserSteeringConsole::Configuration cUserSteeringConCfg =
{
	&cGameManager,
	&cPopulationRegistration
};
UserSteeringConsole cUserSteeringConsole(cUserSteeringConCfg);

UnmanagedGameOfLifeLib::UnmanagedGameOfLifeLib(void)
{

}

UnmanagedGameOfLifeLib::~UnmanagedGameOfLifeLib(void)
{

}
	
UserInfoCenter* const UnmanagedGameOfLifeLib::getUserInfoCenter()
{
	return &cUserInfoCenter;
}

UserSteeringConsole* const UnmanagedGameOfLifeLib::getUserSteeringConsole()
{
	return &cUserSteeringConsole;
}

