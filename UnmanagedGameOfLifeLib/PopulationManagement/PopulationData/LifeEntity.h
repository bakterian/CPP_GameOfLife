/*
 * LifeEntity.h
 */

#ifndef LIFE_ENTITY_H_
#define LIFE_ENTITY_H_

#include "../../Utils/Utils.h"
#include "LifeAddress.h"

/**
	* \Class LifeEntity
	* Specifies the single life entity
	*/
class __declspec(dllexport) LifeEntity
{
	public:
		/**
		* \brief CTOR
		*/
		LifeEntity(LifeAddress cLifeAddress, LifeState eLifeState);

		/**
		* \brief DTOR
		*/
		~LifeEntity();

		/**
		* \brief Provides the Address of the LifeEntity
		*/
		LifeAddress getLifeAddress();

		/**
		* \brief Provides the new life state
		*/
		void setLifeState(LifeState eNewLifeState);

		/**
		* \brief Provides the state of the LifeEntity
		*/
		LifeState getLifeState();

	private:
		LifeAddress		m_eLifeAddress;
		LifeState		m_eLifeState;
};

#endif/* LIFE_ENTITY_H_ */