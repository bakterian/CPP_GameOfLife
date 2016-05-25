/*
 * LifeEntity.cpp
 */

#include "LifeEntity.h"

LifeEntity::LifeEntity(LifeAddress cLifeAddress, LifeState eLifeState):
	m_eLifeAddress(cLifeAddress),
	m_eLifeState(eLifeState)
{

}

LifeEntity::~LifeEntity()
{

}

void LifeEntity::setLifeState(LifeState eNewLifeState)
{
	m_eLifeState = eNewLifeState;
}

LifeAddress LifeEntity::getLifeAddress()
{
	return m_eLifeAddress;
}
	
LifeState LifeEntity::getLifeState()
{
	return m_eLifeState;
}

