/*
 * LifeAddress.cpp
 */

#include "LifeAddress.h"

LifeAddress::LifeAddress(int ixCoordinate, int iyCoordinate):
	m_ixCoordinate(ixCoordinate),
	m_iyCoordinate(iyCoordinate)
{

}

LifeAddress::~LifeAddress()
{

}

bool LifeAddress::operator==(LifeAddress &arg)
{
	bool bRet = true;

	if((arg.getXCoordinate() != this->getXCoordinate()) ||
	   (arg.getYCoordinate() != this->getYCoordinate()))
	{
		bRet = false;
	}
			
	return bRet;
}

bool LifeAddress::isThisANeighbour(LifeAddress &arg)
{
	bool bRet = false;

	if(((m_ixCoordinate == arg.getXCoordinate()) && ((m_iyCoordinate == arg.m_iyCoordinate + 1) || (m_iyCoordinate == arg.m_iyCoordinate - 1)))
		 || ((m_ixCoordinate == arg.getXCoordinate() + 1) && (m_iyCoordinate == arg.m_iyCoordinate || m_iyCoordinate == arg.m_iyCoordinate + 1 || m_iyCoordinate == arg.m_iyCoordinate - 1))
         || ((m_ixCoordinate == arg.getXCoordinate() - 1) && (m_iyCoordinate == arg.m_iyCoordinate || m_iyCoordinate == arg.m_iyCoordinate + 1 || m_iyCoordinate == arg.m_iyCoordinate - 1)))
	{
		bRet = true;
	}
		
	return bRet;
}

int LifeAddress::getXCoordinate()
{
	return m_ixCoordinate;
}

int LifeAddress::getYCoordinate()
{
	return m_iyCoordinate;
}