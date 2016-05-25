/*
 * UnmanagedGameOfLifeLib.h
 */

#ifndef UNMANAGED_GAME_OF_LIFE_H_
#define UNMANAGED_GAME_OF_LIFE_H_

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the UNMANAGEDGAMEOFLIFELIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// UNMANAGEDGAMEOFLIFELIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UNMANAGEDGAMEOFLIFELIB_EXPORTS
#define UNMANAGEDGAMEOFLIFELIB_API __declspec(dllexport)
#else
#define UNMANAGEDGAMEOFLIFELIB_API __declspec(dllimport)
#endif

#include <Windows.h>
#include "UserInterface/GatheringData/UserInfoCenter.h"
#include "UserInterface/Steering/UserSteeringConsole.h"
#include "PopulationManagement/PopulationInformationCenter.h"
#include "PopulationManagement/PopulationRegistration.h"
#include "GameManagement/Listeners/IPopulationChangeListener.h"
#include "GameManagement/GameManager.h"
#include "UserInterface/Steering/UserSteeringConsole.h"
#include "UserInterface/GatheringData/UserInfoCenter.h"


/**
* \Class UnmanagedGameOfLifeLib
* Class Used for wrapping the reference to one boundle which can be easy referenced in  managed code
*/
class UNMANAGEDGAMEOFLIFELIB_API UnmanagedGameOfLifeLib 
{
public:
	/**
	* \brief CTOR
	*/
	UnmanagedGameOfLifeLib(void);

	/**
	* \brief DTOR
	*/
	~UnmanagedGameOfLifeLib(void);
	
	/**
	* \brief Provides pointer to the user information center object
	*/
	virtual UserInfoCenter* const getUserInfoCenter();

	/**
	* \brief Provides pointer to the user steering console object
	*/
	virtual UserSteeringConsole* const getUserSteeringConsole();
};


#endif/* UNMANAGED_GAME_OF_LIFE_H_ */