/*
 * UserInfoCenter.cpp
 */

#include "UserInfoCenter.h"

UserInfoCenter::UserInfoCenter(Configuration& rConfiguration):
	IUserInfoCenter(),
	IPopulationChangeListener(),
	m_rConfig(rConfiguration)
{

}

UserInfoCenter::~UserInfoCenter()
{

}

IPopulationInformationCenter* const UserInfoCenter::getPopInfoCenter()
{
	return m_rConfig.pPopulationInfoCenter;
}


void UserInfoCenter::externalPopulationChange(POPULATION_CHANGE_TYPE ePopChangeType)
{
	//TODO notify listeners
}
