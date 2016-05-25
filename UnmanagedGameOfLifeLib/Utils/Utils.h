/*
 * Utils.h
 */

#ifndef UTILS_H_
#define UTILS_H_

/**
* \brief Enum which describes the state of the Life Entity
*/
enum __declspec(dllexport) LifeState
{
	Created, 
	Born, 
	LivesOn
};


/**
* \brief Enum which defines errocode response values
*/
enum __declspec(dllexport) ERRORTYPE
{
	ET_OK, 
	ET_NOK, 
	ET_INVALID_ARGUMENT
};


/**
* \brief Enum which defines a population change type
*/
enum __declspec(dllexport) POPULATION_CHANGE_TYPE
{
	ADDED_LIFE, 
	REMOVED_LIFE, 
	REPLACED_LIFE,
	UNDEFINED
};

#endif/* UTILS_H_ */