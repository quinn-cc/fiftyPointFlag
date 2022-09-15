/*
 Custom flag: Fifty Point (+FP)
 Each shot earns you fifty points. The recipient loses 50 points too.
 
 Extra notes:
 - works in parallel with avengerFlag plugin, however that plugin is not needed
   for this one to run. If you shoot an Avenger with Fifty Point, you lose 50 points
   and the Avenger gains 50.
 
 Copyright 2022 Quinn Carmack
 May be redistributed under either the LGPL or MIT licenses.
 
 ./configure --enable-custom-plugins=fiftyPointFlag
*/

#include "bzfsAPI.h"
#include "plugin_utils.h"

class FiftyPointFlag : public bz_Plugin
{
    virtual const char* Name()
	{
		return "Fifty Point Flag";
	}
	virtual void Init(const char*);
	virtual void Event(bz_EventData*);
	~FiftyPointFlag();

	virtual void Cleanup(void)
	{
		Flush();
	}
};

BZ_PLUGIN(FiftyPointFlag)

void FiftyPointFlag::Init (const char*)
{
	bz_RegisterCustomFlag("FP", "Fifty Point", "One shot to make fifty points.", 0, eGoodFlag);
    Register(bz_ePlayerDieEvent);
}

FiftyPointFlag::~FiftyPointFlag() {}

void FiftyPointFlag::Event(bz_EventData *eventData)
{
	if (eventData->eventType == bz_ePlayerDieEvent)
	{
		bz_PlayerDieEventData_V2 *data = (bz_PlayerDieEventData_V2*) eventData;
		
		if (data->flagKilledWith == "FP")
		{
			bz_ApiString flagHeldWhenKilled = bz_getFlagName(data->flagHeldWhenKilled);
			// Shot myself
			if (data->killerID == data->playerID)
			{
				bz_incrementPlayerLosses(data->killerID, 49);
			}
			// Have Avenger while hit with Fifty Point
			else if (flagHeldWhenKilled == "AV")
			{
				bz_incrementPlayerWins(data->playerID, 50);
				bz_incrementPlayerLosses(data->killerID, 50);
			}
			// Hit with Fifty Point regularly
			else
			{
				bz_incrementPlayerWins(data->killerID, 49);
				bz_incrementPlayerLosses(data->playerID, 49);
			}
		}
	}
}
