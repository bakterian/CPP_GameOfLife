/*
 * UserSteeringConsoleM.h
 */

#ifndef USER_STEERING_CONSOLEM_H_
#define USER_STEERING_CONSOLEM_H_

#include "../UnmanagedGameOfLifeLib/UnmanagedGameOfLifeLib.h"
#include "TranslationData.h"
#include <windows.h>
#include <array>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedGameOfLifeLib 
{
	public ref class UserSteeringConsoleM
	{
	public:
		/**
		* \brief CTOR
		*/
		UserSteeringConsoleM();

		/**
		* \brief DTOR
		*/
		~UserSteeringConsoleM();
		
		/**
		* \brief DTOR
		*/
		!UserSteeringConsoleM();

		/**
		* \brief Called to initiate a new life cycle
		*/
		void StartLifeCycle();

		/**
		* \brief Called to create one single life
		*/
		ERROTYPEM CreateLife(LifeAddressM^ pcLifeAdress);

		/**
		* \brief Called to create one single life
		*/
		ERROTYPEM CreateLife(List<LifeAddressM^>% pcLifeAdressList);

		/**
		* \brief Called to remove one single life
		*/
		ERROTYPEM RemoveLife(LifeAddressM^ pcLifeAdress);

		/**
		* \brief Called to remove multiple lifes
		*/
		ERROTYPEM RemoveLife(List<LifeAddressM^>% pcLifeAdressList);
	
		/**
		* \brief Called to replace multiple lifes
		*/
		ERROTYPEM RemoveAllLife();

		/**
		* \brief Called to replace multiple lifes
		*/
		ERROTYPEM ReplaceLife(List<LifeAddressM^>% pcLifeAdressList);

	private:
		UnmanagedGameOfLifeLib* m_pUnmanagedGameOfLifeLib;
	};
}

#endif /* USER_STEERING_CONSOLEM_H_ */