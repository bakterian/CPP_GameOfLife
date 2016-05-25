/*
 * IPopulationChangeListener.h
 */

#ifndef IPOPULATION_CHANGE_LISTENER_H_
#define IPOPULATION_CHANGE_LISTENER_H_

#include <Windows.h>
#include "../../Utils/Utils.h"

/**
	* \Class IPopulationChangeListener
	*  Listner Interface to be implemented by all classes which need be notificated after a population change 
	*/
class __declspec(dllexport) IPopulationChangeListener
{
	public:
		/**
		* \brief CTOR
		*/
		IPopulationChangeListener(){ };

		/**
		* \brief DTOR
		*/
		virtual ~IPopulationChangeListener() { };

		/**
		* \brief Called if a population change is taking place
		*/
		virtual void externalPopulationChange(POPULATION_CHANGE_TYPE ePopChangeType) { };
};

#endif/* IPOPULATION_CHANGE_LISTENER_H_ */