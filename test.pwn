#include <a_samp>
#include "android-check.inc"

main() {}


public OnGameModeInit() 
{
	printf("Loading...");
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	new szMessages[64];
	format(szMessages, sizeof(szMessages), "Menggunakan %s", (IsPlayerUsingAndroid(playerid)) ? ("Android") : ("PC"));
	SendClientMessage(playerid, -1, szMessages);
	return 1;
}