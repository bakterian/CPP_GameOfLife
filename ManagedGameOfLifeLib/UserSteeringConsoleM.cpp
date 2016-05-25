/*
 * UserSteeringConsoleM.cpp
 */

#include "stdafx.h"
#include "UserSteeringConsoleM.h"

namespace ManagedGameOfLifeLib
{
	UserSteeringConsoleM::UserSteeringConsoleM()
	{
		m_pUnmanagedGameOfLifeLib = new UnmanagedGameOfLifeLib();
	}

	UserSteeringConsoleM::~UserSteeringConsoleM()
	{
		this->!UserSteeringConsoleM();
	}
		
	UserSteeringConsoleM::!UserSteeringConsoleM()
	{
		if(m_pUnmanagedGameOfLifeLib != nullptr)
		{
			delete m_pUnmanagedGameOfLifeLib;
		}
	}

	void UserSteeringConsoleM::StartLifeCycle()
	{
		m_pUnmanagedGameOfLifeLib->getUserSteeringConsole()->getGameSteering()->startLifeCycle();
	}

	ERROTYPEM UserSteeringConsoleM::CreateLife(LifeAddressM^ pcLifeAdress)
	{
		LifeAddress cLifeAddress(pcLifeAdress->ixCoordinate, pcLifeAdress->iyCoordinate);
		LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

		ERROTYPEM eRet = (ERROTYPEM) m_pUnmanagedGameOfLifeLib->getUserSteeringConsole()->getPopulationManagment()->createLife(cLifeEntity);
		return eRet;
	}

	ERROTYPEM UserSteeringConsoleM::CreateLife(List<LifeAddressM^>% clifeAdressList)
	{
		ERROTYPEM eRet = ERROTYPEM::ET_OK;

		for each (LifeAddressM^ lifeAdressM in clifeAdressList)
		{
			eRet = this->CreateLife(lifeAdressM);
		}

		return eRet;
	}

	ERROTYPEM UserSteeringConsoleM::RemoveLife(LifeAddressM^ pcLifeAdress)
	{
		LifeAddress cLifeAddress(pcLifeAdress->ixCoordinate, pcLifeAdress->iyCoordinate);
		LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

		ERROTYPEM eRet = (ERROTYPEM) m_pUnmanagedGameOfLifeLib->getUserSteeringConsole()->getPopulationManagment()->removeLife(cLifeEntity);
		return eRet;
	}

	ERROTYPEM UserSteeringConsoleM::RemoveLife(List<LifeAddressM^>% pcLifeAdressList)
	{
		ERROTYPEM eRet = ERROTYPEM::ET_OK;

		for each (LifeAddressM^ pLifeAdressM in pcLifeAdressList)
		{
			eRet = this->RemoveLife(pLifeAdressM);

			if(ERROTYPEM::ET_OK != eRet) break;
		}

		return eRet;
	}
	
	ERROTYPEM UserSteeringConsoleM::RemoveAllLife()
	{
		ERROTYPEM eRet = (ERROTYPEM) m_pUnmanagedGameOfLifeLib->getUserSteeringConsole()->getPopulationManagment()->removeAllLife();
		return eRet;
	}

	ERROTYPEM UserSteeringConsoleM::ReplaceLife(List<LifeAddressM^>% pLifeAdressList)
	{
		ERROTYPEM eRet = (ERROTYPEM) m_pUnmanagedGameOfLifeLib->getUserSteeringConsole()->getPopulationManagment()->removeAllLife();

		if(ERROTYPEM::ET_OK == eRet)
		{
			for each (LifeAddressM^ pcLifeAdressM in pLifeAdressList)
			{
				eRet = this->CreateLife(pcLifeAdressM);
			}
		}

		return eRet;
	}

}