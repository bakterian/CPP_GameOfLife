/*
 * IPopulationRegistration.h
 */

#ifndef IPOPULATION_REGISTRATION_H_
#define IPOPULATION_REGISTRATION_H_

#include <vector>
#include "../../../Utils/Utils.h"
#include "../../../PopulationManagement/PopulationData/LifeEntity.h"

/**
	* \Class IPopulationRegistration
	* Interface providing ways to manipulate lifes
	*/
class __declspec(dllexport) IPopulationRegistration
{
	public:

		/**
		* \brief CTOR
		*/
		IPopulationRegistration() { };

		/**
		* \brief DTOR
		*/
		virtual ~IPopulationRegistration() { };

		/**
		* \brief Creates a single life entity
		* \return ET_OK if life was created
		*/
		virtual ERRORTYPE createLife(LifeEntity cLifeEntity) = 0;

		/**
		* \brief Creates multiple life entitys
		* \return ET_OK if all life entitys were created
		*/
		virtual ERRORTYPE createLife(std::vector<LifeEntity> cLifeContainer) = 0;

		/**
		* \brief Replace the entire population with the given vector
		* \return ET_OK if the population was replaced
		*/
		virtual ERRORTYPE replacePopulation(std::vector<LifeEntity> cLifeContainer) = 0;

		/**
		* \brief Removes all life entitys
		* \return ET_OK if all lifes were removed
		*/
		virtual ERRORTYPE removeAllLife() = 0;

		/**
		* \brief Removes a single life entity
		* \return ET_OK if life was found and removed
		*/
		virtual ERRORTYPE removeLife(LifeEntity cLifeEntity) = 0;

		/**
		* \brief Removes multiple life entitys
		* \return ET_OK if all lifes were found and removed
		*/
		virtual ERRORTYPE removeLife(std::vector<LifeEntity> cLifeContainer) = 0;
};

#endif/* IPOPULATION_REGISTRATION_H_ */