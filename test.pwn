#include <a_samp>

#define YSI_NO_HEAP_MALLOC
#define YSI_NO_OPTIMISATION_MESSAGE
#define YSI_NO_MODE_CACHE
#define YSI_NO_VERSION_CHECK

#include "android-check.inc"

main() {}

public OnGameModeInit() 
{
	printf("Loading...");
	return 1;
}

public OnClientChecked(playerid, Client:type)
{
	new szMessages[64];
	format(szMessages, sizeof(szMessages), "Menggunakan %s", (type) ? ("Android") : ("PC"));
	SendClientMessage(playerid, -1, szMessages);
	return 1;
}
