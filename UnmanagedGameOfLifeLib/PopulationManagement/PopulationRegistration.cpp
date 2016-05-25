/*
 * PopulationRegistration.cpp
 */

#include "PopulationRegistration.h"
#include <iostream>

PopulationRegistration::PopulationRegistration(Configuration& rConfiguration):
	IPopulationRegistration(),
	m_rConfiguration(rConfiguration)
{

}

PopulationRegistration::~PopulationRegistration()
{

}

ERRORTYPE PopulationRegistration::createLife(LifeEntity cLifeEntity)
{
	ERRORTYPE eRet = ET_INVALID_ARGUMENT;

	if(true == isTheAddressFree(cLifeEntity.getLifeAddress()))
	{
		m_rConfiguration.rLifeContainer.push_back(cLifeEntity);
		eRet = ET_OK;
	}

	if(ET_OK == eRet)
	{
		notifyListeners(POPULATION_CHANGE_TYPE::ADDED_LIFE);
	}
	
	return eRet;
}

ERRORTYPE PopulationRegistration::createLife(std::vector<LifeEntity> cLifeContainer)
{
	ERRORTYPE eRet = ET_OK;

	for(unsigned int uLoop = 0; ((uLoop < cLifeContainer.size()) && (ET_OK == eRet)); ++uLoop)
	{
		eRet = createLife(cLifeContainer[uLoop]);
	}

	return eRet;
}

ERRORTYPE PopulationRegistration::replacePopulation(std::vector<LifeEntity> cLifeContainer)
{
	ERRORTYPE eRet = ET_OK;

	if(cLifeContainer.size() == 0 )
	{
		eRet = ET_INVALID_ARGUMENT;
	}
	else
	{
		m_rConfiguration.rLifeContainer = cLifeContainer;
		notifyListeners(POPULATION_CHANGE_TYPE::REPLACED_LIFE);
	}

	return eRet;
}

ERRORTYPE PopulationRegistration::removeAllLife()
{
	if( m_rConfiguration.rLifeContainer.size() > 0 )
	{
		m_rConfiguration.rLifeContainer.clear();
		notifyListeners(POPULATION_CHANGE_TYPE::REMOVED_LIFE);
	}

	return (ET_OK);
}

ERRORTYPE PopulationRegistration::removeLife(LifeEntity cLifeEntity)
{
	ERRORTYPE eRet = ET_INVALID_ARGUMENT;

	for(unsigned int uLoop = 0; uLoop < m_rConfiguration.rLifeContainer.size(); ++uLoop)
	{
		if(m_rConfiguration.rLifeContainer[uLoop].getLifeAddress() == cLifeEntity.getLifeAddress())
		{
			m_rConfiguration.rLifeContainer.erase(m_rConfiguration.rLifeContainer.begin() + uLoop);
			eRet = ET_OK;
		}
	}

	if(ET_OK == eRet)
	{
		notifyListeners(POPULATION_CHANGE_TYPE::REMOVED_LIFE);
	}
	
	return eRet;
}

ERRORTYPE PopulationRegistration::removeLife(std::vector<LifeEntity> cLifeContainer)
{
	ERRORTYPE eRet = ET_OK;

	for(unsigned int uLoop = 0; ((uLoop < cLifeContainer.size()) && (eRet == ET_OK)); ++uLoop)
	{
		eRet = removeLife(cLifeContainer[uLoop]);
	}

	return eRet;
}

void PopulationRegistration::notifyListeners(POPULATION_CHANGE_TYPE eChangeType)
{
	for(unsigned int uLoop = 0; uLoop < m_rConfiguration.rPopulationChangeListeners.size();  ++uLoop)
	{
		m_rConfiguration.rPopulationChangeListeners[uLoop].externalPopulationChange(eChangeType);
	}
}

bool PopulationRegistration::isTheAddressFree(LifeAddress cLifeAddress)
{
	bool bAdressIsAvailable = true;

	for(unsigned int uLoop = 0; ((uLoop < m_rConfiguration.rLifeContainer.size()) && (bAdressIsAvailable)); ++uLoop)
	{
		if(m_rConfiguration.rLifeContainer[uLoop].getLifeAddress() == cLifeAddress)
		{
			bAdressIsAvailable = false;
		}
	}

	return bAdressIsAvailable;
}