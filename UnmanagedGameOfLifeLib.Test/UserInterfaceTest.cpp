/*
 * UserInterfaceTest.cpp
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationInformationCenter.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationRegistration.h"
#include "../UnmanagedGameOfLifeLib/GameManagement/Listeners/IPopulationChangeListener.h"
#include "../UnmanagedGameOfLifeLib/GameManagement/GameManager.h"
#include "../UnmanagedGameOfLifeLib/UserInterface/Steering/UserSteeringConsole.h"
#include "../UnmanagedGameOfLifeLib/UserInterface/GatheringData/UserInfoCenter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnmanagedGameOfLifeLibTest
{		
	TEST_CLASS(UserInterfaceTest)
	{
	public:

		TEST_METHOD(TestUserSteering)
		{
			LifeAddress cLifeAddress(10,10);
			LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

			std::vector<LifeEntity> cPopulationContainer;
			cPopulationContainer.push_back(cLifeEntity);

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

			//can the inital life be found?
			Assert::IsTrue(cUserInfoCenter.getPopInfoCenter()->isLifePresent(cLifeEntity));
			Assert::IsTrue(1 == cUserInfoCenter.getPopInfoCenter()->getPopulationCount());
			
			cUserSteeringConsole.getGameSteering()->startLifeCycle();

			//did the population decrease as was expected?
			Assert::IsTrue(0 == cUserInfoCenter.getPopInfoCenter()->getPopulationCount());
			Assert::IsFalse(cUserInfoCenter.getPopInfoCenter()->isLifePresent(cLifeEntity));
		}
	};
}