/*
 * IUserInfoCenter.h
 */

#ifndef IUSER_INFO_CENTER_H_
#define IUSER_INFO_CENTER_H_

#include "WorkDeployment\IPopulationInformationCenter.h"

/**
	* \Class IUserInfoCenter
	* Interface providing the user with information regarding the population
	*/
class __declspec(dllexport) IUserInfoCenter
{
	public:

		/**
		* \brief CTOR
		*/
		IUserInfoCenter() { };

		/**
		* \brief DTOR
		*/
		virtual ~IUserInfoCenter() { };

		/**
		* \brief Provides pointer to a population information center object
		*/
		virtual IPopulationInformationCenter* const getPopInfoCenter() = 0;
};

#endif/* IUSER_INFO_CENTER_H_ */