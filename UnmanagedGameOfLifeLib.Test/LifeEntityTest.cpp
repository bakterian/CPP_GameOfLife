/*
 * LifeEntityTest.cpp
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../UnmanagedGameOfLifeLib/Utils/Utils.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationData/LifeAddress.h"
#include "../UnmanagedGameOfLifeLib/PopulationManagement/PopulationData/LifeEntity.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnmanagedGameOfLifeLibTest
{		
	TEST_CLASS(LifeEntityTest)
	{
	public:
		
		TEST_METHOD(TestLifeAddressCreation)
		{
			LifeAddress cLifeAddress(5,10);
			Assert::IsNotNull(&cLifeAddress);
		}

		TEST_METHOD(TestLifeCreation)
		{
			LifeAddress cLifeAddress(10,20);
			LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);
		}

		TEST_METHOD(TestLifeCoordinatesAfterInit)
		{
			int iLifeXcoordinate = 30;
			int iLifeYcoordinate = 40;

			LifeAddress cLifeAddress(iLifeXcoordinate,iLifeYcoordinate);
			LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

			Assert::IsTrue(iLifeXcoordinate == cLifeEntity.getLifeAddress().getXCoordinate());
			Assert::IsTrue(iLifeYcoordinate == cLifeEntity.getLifeAddress().getYCoordinate());
		}

		TEST_METHOD(TestLifeAddressEquality)
		{
			int iLifeXcoordinate = 30;
			int iLifeYcoordinate = 40;

			LifeAddress cLifeAddress(iLifeXcoordinate,iLifeYcoordinate);
			LifeAddress cLifeAddressTest(iLifeXcoordinate,iLifeYcoordinate);

			LifeEntity cLifeEntity(cLifeAddress, LifeState::Created);

			Assert::IsTrue(cLifeAddressTest == cLifeEntity.getLifeAddress());
		}

		TEST_METHOD(TestLifeAddressInEquality)
		{
			LifeAddress cLifeAddress1(30,40);
			LifeAddress cLifeAddress2(30,41);

			Assert::IsFalse(cLifeAddress1 == cLifeAddress2);
		}

		TEST_METHOD(TestLifeStateAfterInit)
		{
			LifeAddress				cLifeAddress(1,2);
			LifeState	eLifeState(LifeState::Created);

			LifeEntity cLifeEntity(cLifeAddress, eLifeState);

			Assert::IsTrue(eLifeState == cLifeEntity.getLifeState());
		}
	};
}