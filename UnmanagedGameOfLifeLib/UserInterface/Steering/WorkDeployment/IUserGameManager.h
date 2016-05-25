/*
 * IUserGameManager.h
 */

#ifndef IUSER_GAME_MANAGER_H_
#define IUSER_GAME_MANAGER_H_

#include <Windows.h>
#include "../../../Utils/Utils.h"

/**
	* \Class IUserGameManager
	* Interface providing game managment calls
	*/
class __declspec(dllexport) IUserGameManager
{
	public:
		/**
		* \brief CTOR
		*/
		IUserGameManager(){ };

		/**
		* \brief DTOR
		*/
		virtual ~IUserGameManager() { };

		/**
		* \brief Called to initiate a new life cycle
		*/
		virtual void startLifeCycle() = 0;
};

#endif/* IUSER_GAME_MANAGER_H_ */