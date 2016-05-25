/*
 * PopulationRegistration.h
 */

#ifndef POPULATION_REGISTRATION_H_
#define POPULATION_REGISTRATION_H_

#include <vector>
#include "../UserInterface/Steering/WorkDeployment/IUserPopulationRegistration.h"
#include "../GameManagement/Listeners/IPopulationChangeListener.h"

/**
	* \Class IPooulationRegistration
	* Interface providing ways to manipulate lifes
	*/
class __declspec(dllexport) PopulationRegistration : public IPopulationRegistration
{
	public:
		/**
		* \brief Class Configuration
		*/
		struct Configuration
		{
			std::vector<LifeEntity>& rLifeContainer;
			std::vector<IPopulationChangeListener>& rPopulationChangeListeners;
		};

		/**
		* \brief CTOR
		*/
		PopulationRegistration(Configuration& rConfiguration);

		/**
		* \brief DTOR
		*/
		virtual ~PopulationRegistration();

		/**
		* \brief Creates a single life entity
		* \return ET_OK if life was created
		*/
		virtual ERRORTYPE createLife(LifeEntity cLifeEntity);

		/**
		* \brief Creates multiple life entitys
		* \return ET_OK if all life entitys were created
		*/
		virtual ERRORTYPE createLife(std::vector<LifeEntity> cLifeContainer);

		/**
		* \brief Replace the entire population with the given vector
		* \return ET_OK if the population was replaced
		*/
		virtual ERRORTYPE replacePopulation(std::vector<LifeEntity> cLifeContainer);

		/**
		* \brief Removes all life entitys
		* \return ET_OK if all lifes were removed
		*/
		virtual ERRORTYPE removeAllLife();

		/**
		* \brief Removes a single life entity
		* \return ET_OK if life was found and removed
		*/
		virtual ERRORTYPE removeLife(LifeEntity cLifeEntity);

		/**
		* \brief Removes multiple life entitys
		* \return ET_OK if all lifes were found and removed
		*/
		virtual ERRORTYPE removeLife(std::vector<LifeEntity> cLifeContainer);

		/**
		* \brief Notify any listeners on population change
		* \param eChangeType informs listeners on the type of the change
		*/
		void notifyListeners(POPULATION_CHANGE_TYPE eChangeType);

	protected:
		/**
		* \brief Checks if the life address is not being used by an other life entity.
		* \param cLifeAddress - The adress that has to be checked.
		* \return true - There is someone living under this address.
		* \return false - Nobody is living under this address.
		*/
		bool isTheAddressFree(LifeAddress cLifeAddress);

	private:
		Configuration &m_rConfiguration;
};

#endif/* POPULATION_REGISTRATION_H_ */