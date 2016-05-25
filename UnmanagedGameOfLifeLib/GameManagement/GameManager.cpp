/*
 * GameManager.cpp
 */

#include "GameManager.h"

GameManager::GameManager(Configuration& rConfiguration):
	IUserGameManager(),
	m_rConfiguration(rConfiguration),
	m_LifesToKill(),
	m_LifesToCreate()
{

}

GameManager::~GameManager()
{

}

void GameManager::startLifeCycle()
{
	handleExistingLife();
	searchForNewLife();

	m_rConfiguration.rPopulationRegistration.createLife(m_LifesToCreate);
	m_rConfiguration.rPopulationRegistration.removeLife(m_LifesToKill);
	
	m_LifesToCreate.clear();
	m_LifesToKill.clear();
}

void GameManager::handleExistingLife()
{
	auto vPopulationContainer = m_rConfiguration.rPopulationInfoCenter.getPopulation();

	for(unsigned int uLoop = 0; uLoop < vPopulationContainer.size(); ++uLoop)
	{
		auto iNoOfNeighbours = m_rConfiguration.rPopulationInfoCenter.getNeighboursCount(vPopulationContainer[uLoop]);

		if( true == willTheEntityLiveOn(iNoOfNeighbours))
		{// this life entity lives on (status quo)
			/*
			m_rConfiguration.rPopulationRegistration.removeLife(vPopulationContainer[uLoop]);
			vPopulationContainer[uLoop].setLifeState(LifeState::LivesOn);
			m_rConfiguration.rPopulationRegistration.createLife(vPopulationContainer[uLoop]);
			*/
		}
		else
		{// this life entity has to die due to overcrowding or loneliness
			m_LifesToKill.push_back(vPopulationContainer[uLoop]);
		}
	}

}

void GameManager::searchForNewLife()
{
	if(m_rConfiguration.rPopulationInfoCenter.getPopulationCount() > 0)
	{
		auto cPopAdressRange = m_rConfiguration.rPopulationInfoCenter.getPopulationAdressRange();

		for (int iXCorrdinate = (cPopAdressRange.iMinXAdress - 1); iXCorrdinate <= (cPopAdressRange.iMaxXAdress + 1); ++iXCorrdinate)
        {
            for (int iYCorrdinate = (cPopAdressRange.iMinYAdress - 1); iYCorrdinate <= (cPopAdressRange.iMaxYAdress + 1); ++iYCorrdinate)
            {
                LifeAddress cPotencialLifeAddress(iXCorrdinate,iYCorrdinate);
				LifeEntity cPotencialLifeEntity(cPotencialLifeAddress, LifeState::Born);

				if(false == m_rConfiguration.rPopulationInfoCenter.isLifePresent(cPotencialLifeEntity))
                {
                    auto iNeighboursCount = m_rConfiguration.rPopulationInfoCenter.getNeighboursCount(cPotencialLifeEntity);

					if( 3 == iNeighboursCount)
					{
						m_LifesToCreate.push_back(cPotencialLifeEntity);
					}
                }
            }
        }
	}
}

bool GameManager::willTheEntityLiveOn(int iNeighbourCount)
{
	bool bRet = false;

	if((2 == iNeighbourCount) || (3 == iNeighbourCount))
	{
		bRet = true;
	}

	return bRet;
}


void GameManager::updatePopulation()
{
	m_rConfiguration.rPopulationRegistration.createLife(m_LifesToCreate);
	m_rConfiguration.rPopulationRegistration.removeLife(m_LifesToKill);
	
	m_LifesToCreate.clear();
	m_LifesToKill.clear();
}

