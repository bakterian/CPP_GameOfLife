/*
 * PopulationManagementTest.cpp
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationInformationCenter.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationRegistration.h"
#include "../UnmanagedGameOfLifeLib/GameManagement/Listeners/IPopulationChangeListener.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnmanagedGameOfLifeLibTest
{		
	TEST_CLASS(PopulationManagementTest)
	{
	public:
		
		TEST_METHOD(TestPopInfoCenterCreation)
		{
			LifeAddress cLifeAddress(10,20);
			LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);
			std::vector<LifeEntity> cPopulationContainer;
			cPopulationContainer.push_back(cLifeEntity);

			PopulationInformationCenter cPopulationInfoCenter(cPopulationContainer);
		}

		TEST_METHOD(TestPopRegistrationCreation)
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

			PopulationRegistration cPopulationRegistration(sPopRegConf);
		}

		TEST_METHOD(TestRegisterNewLife)
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

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity));
		}

		TEST_METHOD(TestAddSameLifeMultipleTimes)
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

			ERRORTYPE eRet = cPopulationRegistration.createLife(cLifeEntity);
			
			//was the invalid operation spotted?
			Assert::IsTrue(eRet == ET_INVALID_ARGUMENT);

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity));
		}

		TEST_METHOD(TestIncreasePopulation)
		{
			LifeAddress cLifeAddress1(10,20);
			LifeAddress cLifeAddress2(10,21);
			LifeEntity cLifeEntity1(cLifeAddress1, LifeState::Created);
			LifeEntity cLifeEntity2(cLifeAddress2, LifeState::Created);

			std::vector<LifeEntity> cPopulationContainer;
			cPopulationContainer.push_back(cLifeEntity1);
			std::vector<IPopulationChangeListener> cPopChangeListeners;

			PopulationRegistration::Configuration sPopRegConf = 
			{
				cPopulationContainer,
				cPopChangeListeners
			};

			PopulationInformationCenter cPopulationInfoCenter(cPopulationContainer);
			PopulationRegistration cPopulationRegistration(sPopRegConf);

			ERRORTYPE eRet = cPopulationRegistration.createLife(cLifeEntity2);
			
			//was the life created without any issues?
			Assert::IsTrue(eRet == ET_OK);

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity1));

			//can the additional life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity2));
		}

		TEST_METHOD(TestRemoveLife)
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

			//can the inital life be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity));

			ERRORTYPE eRet = cPopulationRegistration.removeLife(cLifeEntity);
			
			//was the life removed without any issues?
			Assert::IsTrue(eRet == ET_OK);

			//can the removed life no longer be found?
			Assert::IsFalse(cPopulationInfoCenter.isLifePresent(cLifeEntity));
		}

		TEST_METHOD(TestReplacePopulation)
		{
			LifeAddress cLifeAddress1(10,20);
			LifeAddress cLifeAddress2(10,21);
			LifeEntity cLifeEntity1(cLifeAddress1, LifeState::Created);
			LifeEntity cLifeEntity2(cLifeAddress2, LifeState::Created);

			std::vector<LifeEntity> cPopulationContainer1;
			cPopulationContainer1.push_back(cLifeEntity1);

			std::vector<LifeEntity> cPopulationContainer2;
			cPopulationContainer2.push_back(cLifeEntity2);

			std::vector<IPopulationChangeListener> cPopChangeListeners;
			PopulationRegistration::Configuration sPopRegConf = 
			{
				cPopulationContainer1,
				cPopChangeListeners
			};

			PopulationInformationCenter cPopulationInfoCenter(cPopulationContainer1);
			PopulationRegistration cPopulationRegistration(sPopRegConf);

			cPopulationRegistration.replacePopulation(cPopulationContainer2);

			//can the inital life not be found?
			Assert::IsFalse(cPopulationInfoCenter.isLifePresent(cLifeEntity1));

			//can the a life from the new population be found?
			Assert::IsTrue(cPopulationInfoCenter.isLifePresent(cLifeEntity2));
		}

		TEST_METHOD(TestRemovePopulation)
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
			
			auto eRet = cPopulationRegistration.removeAllLife();
			
			//was the removall off all life entities confirmed?
			Assert::IsTrue (eRet == ET_OK);

			//is the initial life  entity missing after removall?
			Assert::IsFalse(cPopulationInfoCenter.isLifePresent(cLifeEntity));
		}

		TEST_METHOD(TestGetPopulationCount)
		{
			LifeAddress cLifeAddress1(10,20);
			LifeAddress cLifeAddress2(10,21);
			LifeAddress cLifeAddress3(9,21);
			LifeEntity cLifeEntity1(cLifeAddress1, LifeState::Created);
			LifeEntity cLifeEntity2(cLifeAddress2, LifeState::Created);
			LifeEntity cLifeEntity3(cLifeAddress3, LifeState::Born);

			std::vector<LifeEntity> cPopulationContainer;
			cPopulationContainer.push_back(cLifeEntity1);
			cPopulationContainer.push_back(cLifeEntity2);
			std::vector<IPopulationChangeListener> cPopChangeListeners;

			PopulationRegistration::Configuration sPopRegConf = 
			{
				cPopulationContainer,
				cPopChangeListeners
			};

			PopulationInformationCenter cPopulationInfoCenter(cPopulationContainer);
			PopulationRegistration cPopulationRegistration(sPopRegConf);

			ERRORTYPE eRet = cPopulationRegistration.createLife(cLifeEntity3);

			//was the life added without any issues?
			Assert::IsTrue(eRet == ET_OK);

			//is the life count accurate?
			Assert::IsTrue(3U == cPopulationInfoCenter.getPopulationCount());
		}
	};
}