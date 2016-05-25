/*
 * UserInfoCenterM.cpp
 */

#include "stdafx.h"
#include "UserInfoCenterM.h"

namespace ManagedGameOfLifeLib
{
	UserInfoCenterM::UserInfoCenterM()
	{
		m_pUnmanagedGameOfLifeLib = new UnmanagedGameOfLifeLib();
	}

	UserInfoCenterM::~UserInfoCenterM()
	{
		this->!UserInfoCenterM();
	}
		
	UserInfoCenterM::!UserInfoCenterM()
	{
		if(m_pUnmanagedGameOfLifeLib != nullptr)
		{
			delete m_pUnmanagedGameOfLifeLib;
		}
	}

	List<LifeAddressM^>^ UserInfoCenterM::getPopulation()
	{
		auto vLifeAddressList =  gcnew List<LifeAddressM^>();
		auto vNativeLifeEntityList = m_pUnmanagedGameOfLifeLib->getUserInfoCenter()->getPopInfoCenter()->getPopulation();
		
		for(int iLoop = 0; iLoop <  this->getPopulationCount(); ++iLoop)
		{
			auto cNativeAddress = vNativeLifeEntityList[iLoop].getLifeAddress();
			LifeAddressM cLifeAddress(cNativeAddress.getXCoordinate(),cNativeAddress.getYCoordinate());
			vLifeAddressList->Add(%cLifeAddress);
		}

		return vLifeAddressList;
	}

	unsigned int UserInfoCenterM::getPopulationCount()
	{
		return m_pUnmanagedGameOfLifeLib->getUserInfoCenter()->getPopInfoCenter()->getPopulationCount();
	}

	bool UserInfoCenterM::isLifePresent(LifeAddressM^ pcLifeAddressM)
	{
		LifeAddress cLifeAddress(pcLifeAddressM->ixCoordinate, pcLifeAddressM->iyCoordinate);
		LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

		return m_pUnmanagedGameOfLifeLib->getUserInfoCenter()->getPopInfoCenter()->isLifePresent(cLifeEntity);
	}


}