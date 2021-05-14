#include <a_samp>

static __usingAndroidClient[MAX_PLAYERS];

// Taken from: https://github.com/pawn-lang/YSI-Includes/YSI_Core/y_master/y_rconfix.inc
stock rconfix_Load()
{
	// It is.  Create the file.
	if (!fexist("callbackfix.amx"))
	{
		/*
			native CallRemoteFunction(const function[], const format[], {Float,_}:...);
			forward OnRconCommand(const cmd[]);
			public OnRconCommand(const cmd[]) return 0;
			forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);
			public OnClientCheckResponse(playerid, actionid, memaddr, retndata) return CallRemoteFunction("FIXES_OnClientCheckResponse\0\0\0", "iiii", playerid, actionid, memaddr, retndata);
		*/
		static
			lRCFixCode[] = {
				0x000000F0, 0x0808F1E0, 0x00080014, 0x0000008C,
				0x000000F0, 0x00000180, 0x00004180, 0xFFFFFFFF,
				0x00000038, 0x00000048, 0x00000050, 0x00000050,
				0x00000050, 0x00000050, 0x00000014, 0x00000052,
				0x00000008, 0x00000068, 0x00000000, 0x00000076,
				0x6E4F001F, 0x65696C43, 0x6843746E, 0x526B6365,
				0x6F707365, 0x0065736E, 0x63526E4F, 0x6F436E6F,
				0x6E616D6D, 0x61430064, 0x65526C6C, 0x65746F6D,
				0x636E7546, 0x6E6F6974, 0x00000000, 0x2E007880,
				0x2E305980, 0x81180581, 0x05811405, 0x0C058110,
				0x277C8027, 0x80182700, 0x1C2C007B, 0x80468030,
				0x80588049, 0x80538045, 0x804F805F, 0x8043806E,
				0x8069806C, 0x806E8065, 0x80438074, 0x80658068,
				0x806B8063, 0x80658052, 0x80708073, 0x806E806F,
				0x00658073, 0x80000000, 0x80698069, 0x00698069
			};
		new
			File:fs = fopen("callbackfix.amx", io_write);

		if (fs)
		{
			fblockwrite(fs, lRCFixCode);
			fclose(fs);
		}
	}
	if (fexist("callbackfix.amx"))
	{
		SendRconCommand("loadfs ../scriptfiles/callbackfix");
	}
}

forward FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata);
public FIXES_OnClientCheckResponse(playerid, actionid, memaddr, retndata) 
{
	if (actionid == 0x48) 
	{
		__usingAndroidClient[playerid] = false;
	}
	return 1;
}

public OnGameModeInit()
{
	// load the callbackfix
	#if !defined y_rconfix_Load && !defined _INC_SAMP_Community_fixes
		rconfix_Load();
	#endif

	#if defined xLib_OnGameModeInit
		return xLib_OnGameModeInit();
	#else
		return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit xLib_OnGameModeInit
#if defined xLib_OnGameModeInit
	forward xLib_OnGameModeInit();
#endif


public OnPlayerConnect(playerid)
{
	// must reset at OnPlayerConnect and then fires new checks
	__usingAndroidClient[playerid] = true;
	SendClientCheck(playerid, 0x48, 0, 0, 2);
	#if defined xLib_OnPlayerConnect
		return xLib_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect xLib_OnPlayerConnect
#if defined xLib_OnPlayerConnect
	forward xLib_OnPlayerConnect(playerid);
#endif

stock IsPlayerUsingAndroid(playerid) 
{
	return __usingAndroidClient[playerid];
}

// SendClientCheck example script by evgen1137
// thanks to MTA devs for structs
