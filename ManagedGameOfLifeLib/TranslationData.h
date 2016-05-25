/*
 * TranslationData.h
 */

#ifndef TRANSLATION_DATA_H_
#define TRANSLATION_DATA_H_

namespace ManagedGameOfLifeLib 
{
	public ref class LifeAddressM 
	{
	public:
		LifeAddressM(int xCoordinate, int yCoordinate)
		{
			ixCoordinate = xCoordinate;
			iyCoordinate = yCoordinate;
		}

		int ixCoordinate;
		int iyCoordinate;
	};

	public enum class ERROTYPEM 
	{
		ET_OK, 
		ET_NOK, 
		ET_INVALID_ARGUMENT
	};
}

#endif /* TRANSLATION_DATA_H_ */