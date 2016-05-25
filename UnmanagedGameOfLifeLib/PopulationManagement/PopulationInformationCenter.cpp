/*
 * PopulationInformationCenter.cppp
 */

#include "PopulationInformationCenter.h"
#include <limits.h>

PopulationInformationCenter::PopulationInformationCenter(std::vector<LifeEntity> &rLifeContainer):
IPopulationInformationCenter(),
m_rLifeContainer(rLifeContainer)
{ 

}

PopulationInformationCenter::~PopulationInformationCenter() 
{ 

};

std::vector<LifeEntity> PopulationInformationCenter::getPopulation()
{
	return m_rLifeContainer;
}

unsigned int PopulationInformationCenter::getPopulationCount()
{
	return m_rLifeContainer.size();
}
		
bool PopulationInformationCenter::isLifePresent(LifeEntity cLifeEntity)
{
	bool bLifeFound = false;

	for(unsigned int uLoop = 0; ((uLoop < m_rLifeContainer.size()) && (bLifeFound == false)); ++uLoop)
	{
		if(m_rLifeContainer[uLoop].getLifeAddress() == cLifeEntity.getLifeAddress())
		{
			bLifeFound = true;
		}
	}

	return bLifeFound;
};

int PopulationInformationCenter::getNeighboursCount(LifeEntity cLifeEntity)
{	   
	int iNeighboursCount = 0;

	for(unsigned int uLoop = 0; uLoop < m_rLifeContainer.size() ; ++uLoop)
	{
		if(true == m_rLifeContainer[uLoop].getLifeAddress().isThisANeighbour(cLifeEntity.getLifeAddress()))
		{
			++iNeighboursCount;
		}
	}

	return iNeighboursCount;
}


PopulationInformationCenter::PopulationAddressRange PopulationInformationCenter::getPopulationAdressRange()
{
	PopulationAddressRange cPopAdressRange = {INT_MAX, INT_MIN, INT_MAX, INT_MIN};

	for(unsigned int uLoop = 0; uLoop < m_rLifeContainer.size() ; ++uLoop)
	{
		auto cLifeAddres =  m_rLifeContainer[uLoop].getLifeAddress();

		if(cLifeAddres.getXCoordinate() > cPopAdressRange.iMaxXAdress) cPopAdressRange.iMaxXAdress = cLifeAddres.getXCoordinate();
		if(cLifeAddres.getXCoordinate() < cPopAdressRange.iMinXAdress) cPopAdressRange.iMinXAdress = cLifeAddres.getXCoordinate();
		if(cLifeAddres.getYCoordinate() > cPopAdressRange.iMaxYAdress) cPopAdressRange.iMaxYAdress = cLifeAddres.getYCoordinate();
		if(cLifeAddres.getYCoordinate() < cPopAdressRange.iMinYAdress) cPopAdressRange.iMinYAdress = cLifeAddres.getYCoordinate();
	}

	return cPopAdressRange;
}