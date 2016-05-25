/*
 * GameManagerTest.cpp
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationInformationCenter.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationRegistration.h"
#include "../UnmanagedGameOfLifeLib/GameManagement/Listeners/IPopulationChangeListener.h"
#include "../UnmanagedGameOfLifeLib/GameManagement/GameManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnmanagedGameOfLifeLibTest
{		
	TEST_CLASS(GameManagerTest)
	{
	public:

		TEST_METHOD(TestGameLoneliness)
		{
			LifeAddress cLifeAddress(10,20);
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

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity));
			Assert::IsTrue(1 == cPopulationInfoCenter.getPopulationCount());
			
			cGameManager.startLifeCycle();

			//has the life been killed by loneliness?
			Assert::IsFalse(cPopulationInfoCenter.isLifePresent(cLifeEntity));
			Assert::IsTrue(0 == cPopulationInfoCenter.getPopulationCount());
		}

		TEST_METHOD(TestGameStillLife)
		{
			LifeAddress cLifeAddress1(10,10);
			LifeEntity cLifeEntity1(cLifeAddress1, LifeState::Created);
			LifeAddress cLifeAddress2(11,10);
			LifeEntity cLifeEntity2(cLifeAddress2, LifeState::Created);
			LifeAddress cLifeAddress3(10,11);
			LifeEntity cLifeEntity3(cLifeAddress3, LifeState::Created);
			LifeAddress cLifeAddress4(11,11);
			LifeEntity cLifeEntity4(cLifeAddress4, LifeState::Created);

			std::vector<LifeEntity> cPopulationContainer;
			cPopulationContainer.push_back(cLifeEntity1);
			cPopulationContainer.push_back(cLifeEntity2);
			cPopulationContainer.push_back(cLifeEntity3);
			cPopulationContainer.push_back(cLifeEntity4);

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

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity3));
			Assert::IsTrue(4 == cPopulationInfoCenter.getPopulationCount());
			
			cGameManager.startLifeCycle();

			//there was no change in the population, as expected?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity3));
			Assert::IsTrue(4 == cPopulationInfoCenter.getPopulationCount());
		}

		TEST_METHOD(TestGameBirth)
		{
			LifeAddress cLifeAddress1(10,11);
			LifeEntity cLifeEntity1(cLifeAddress1, LifeState::Created);
			LifeAddress cLifeAddress2(10,9);
			LifeEntity cLifeEntity2(cLifeAddress2, LifeState::Created);
			LifeAddress cLifeAddress3(11,10);
			LifeEntity cLifeEntity3(cLifeAddress3, LifeState::Created);
			LifeAddress cLifeAddress4(10,10);
			LifeEntity cLifeEntity4(cLifeAddress4, LifeState::Created);

			std::vector<LifeEntity> cPopulationContainer;
			cPopulationContainer.push_back(cLifeEntity1);
			cPopulationContainer.push_back(cLifeEntity2);
			cPopulationContainer.push_back(cLifeEntity3);
			cPopulationContainer.push_back(cLifeEntity4);

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

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity3));
			Assert::IsTrue(4 == cPopulationInfoCenter.getPopulationCount());
			
			cGameManager.startLifeCycle();

			//did the population increase as was expected?
			Assert::IsTrue(7 == cPopulationInfoCenter.getPopulationCount());

			LifeAddress cNewLifeAddress(9,10);
			LifeEntity cNewLifeEntity(cNewLifeAddress, LifeState::Born);

			//is the new life present at the expected location?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cNewLifeEntity));
		}

	};
}