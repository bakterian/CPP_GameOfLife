/*
 * UserInfoCenter.h
 */

#ifndef USER_INFO_CENTER_H_
#define USER_INFO_CENTER_H_

#include "WorkDeployment\IPopulationInformationCenter.h"
#include "IUserInfoCenter.h"
#include "../../GameManagement/Listeners/IPopulationChangeListener.h"

/**
* \Class UserInfoCenter
* Class providing the user with information regarding the population and hhandling notifications
*/
class __declspec(dllexport) UserInfoCenter : public IUserInfoCenter, IPopulationChangeListener
{
	public:

		/**
		* \brief Class configuration
		*/
		struct Configuration
		{
			IPopulationInformationCenter* const pPopulationInfoCenter;
		};

		/**
		* \brief CTOR
		*/
		UserInfoCenter(Configuration& rConfiguration);

		/**
		* \brief DTOR
		*/
		virtual ~UserInfoCenter();

		/**
		* \brief Provides pointer to a population information center object
		*/
		virtual IPopulationInformationCenter* const getPopInfoCenter();

		/**
		* \brief Called if a population change is taking place
		*/
		virtual void externalPopulationChange(POPULATION_CHANGE_TYPE ePopChangeType);

	private:
		Configuration m_rConfig;
};

#endif/* IUSER_INFO_CENTER_H_ */