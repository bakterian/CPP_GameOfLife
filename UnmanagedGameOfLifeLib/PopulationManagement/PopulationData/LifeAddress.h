/*
 * LifeAddress.h
 */

#ifndef LIFE_ADDRESS_H_
#define LIFE_ADDRESS_H_

#include <windows.h>

/**
	* \Class LifeAddress
	* Specifies the single coordinates of a life entity
	*/
class __declspec(dllexport) LifeAddress
{
	public:
		/**
		* \brief CTOR
		*/
		LifeAddress(int ixCoordinate, int iyCoordinate);

		/**
		* \brief DTOR
		*/
		~LifeAddress();

		/**
		* \brief States the equlity of the LifeAddress
		*/
		bool operator==(LifeAddress &arg);

		/**
		* \brief Provides information of the given addres is in the immediate neighbourhood
		*/
		bool isThisANeighbour(LifeAddress &arg);

		/**
		* \brief Provides the x coordinate of the Address.
		*/
		int getXCoordinate();

		/**
		* \brief Provides the y coordinate of the Address.
		*/
		int getYCoordinate();

	private:
		int m_ixCoordinate;
		int m_iyCoordinate;
};


#endif/* LIFE_ADDRESS_H_ */