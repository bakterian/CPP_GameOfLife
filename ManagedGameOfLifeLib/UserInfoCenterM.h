/*
 * UserInfoCenterM.h
 */

#ifndef USER_INFO_CENTERM_H_
#define USER_INFO_CENTERM_H_

#include "../UnmanagedGameOfLifeLib/UnmanagedGameOfLifeLib.h"
#include "TranslationData.h"
#include <windows.h>
#include <array>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedGameOfLifeLib 
{
	public ref class UserInfoCenterM
	{
	public:
		/**
		* \brief CTOR
		*/
		UserInfoCenterM();

		/**
		* \brief DTOR
		*/
		~UserInfoCenterM();
		
		/**
		* \brief DTOR
		*/
		!UserInfoCenterM();

	    /**
		* \brief Provides a vector conntaing all life entities
		*/
		virtual List<LifeAddressM^>^ getPopulation();

		/**
		* \brief Provides a population count
		*/
		virtual unsigned int getPopulationCount();
		
		/**
		* \brief Provides a population count
		*/
		virtual bool isLifePresent(LifeAddressM^ pcLifeAddressM);

	private:
		UnmanagedGameOfLifeLib* m_pUnmanagedGameOfLifeLib;
	};
}

#endif /* USER_INFO_CENTERM_H_ */