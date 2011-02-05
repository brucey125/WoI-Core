#include "ScriptPCH.h"
#include <time.h>

class tele_npc_vote : public CreatureScript
{
public:
	tele_npc_vote() : CreatureScript("tele_npc_vote") { }

	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		bool votecheck = pPlayer->HasVoted();
		if (!votecheck)
			ChatHandler(pPlayer).PSendSysMessage(LANG_TELE_VOTE_CHECK_FAILED);

		// remove stealth
		if (pPlayer->HasAura(1784))
			pPlayer->RemoveAura(1784);
		// remove vanish
		if (pPlayer->HasAura(26889))
			pPlayer->RemoveAura(26889);
		// remove prowl
		if (pPlayer->HasAura(5215))
			pPlayer->RemoveAura(5215);
    

		// Main Menu for Alliance
		if (pPlayer->GetTeam() == ALLIANCE)
		{
			pPlayer->ADD_GOSSIP_ITEM( 7, "Alliance Town ->"                 , GOSSIP_SENDER_MAIN, 1000);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Neutral Town ->"                  , GOSSIP_SENDER_MAIN, 3000);
			if (votecheck)
			{
				pPlayer->ADD_GOSSIP_ITEM( 7, "Dungeons ->"                  , GOSSIP_SENDER_MAIN, 5000);
				pPlayer->ADD_GOSSIP_ITEM( 7, "Player Tools ->"              , GOSSIP_SENDER_MAIN, 4000);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Alliance vs Horde PvP"        , GOSSIP_SENDER_MAIN, 3500);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Guild House Menu"             , GOSSIP_SENDER_MAIN, 10010);
			}
		}
		else // Main Menu for Horde
		{
			pPlayer->ADD_GOSSIP_ITEM( 7, "Horde Town ->"                    , GOSSIP_SENDER_MAIN, 2000);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Neutral Town ->"                  , GOSSIP_SENDER_MAIN, 3000);
			if (votecheck)
			{
				pPlayer->ADD_GOSSIP_ITEM( 7, "Dungeons ->"                  , GOSSIP_SENDER_MAIN, 5000);
				pPlayer->ADD_GOSSIP_ITEM( 7, "Player Tools ->"              , GOSSIP_SENDER_MAIN, 4000);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Alliance vs Horde PvP"        , GOSSIP_SENDER_MAIN, 3500);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Guild House Menu"             , GOSSIP_SENDER_MAIN, 10010);
			}
		}

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

	return true;
	}

	void SendDefaultMenu_TeleNPCVote(Player* pPlayer, Creature* pCreature, uint32 action)
	{
	bool votecheck = pPlayer->HasVoted();
	// Not allow in combat
	if (pPlayer->isInCombat())
	{
		pPlayer->CLOSE_GOSSIP_MENU();
		pCreature->MonsterSay("You are in combat!", LANG_UNIVERSAL, NULL);
		return;
	}

	switch(action)
	{

	case 1000: //Alliance Town
			pPlayer->ADD_GOSSIP_ITEM( 5, "Darnassus"                    , GOSSIP_SENDER_MAIN, 1001);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Exodar"                       , GOSSIP_SENDER_MAIN, 1005);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Ironforge"                    , GOSSIP_SENDER_MAIN, 1010);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Stormwind"                    , GOSSIP_SENDER_MAIN, 1015);
			pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                 , GOSSIP_SENDER_MAIN, 5005);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 2000: //Horde Town
			pPlayer->ADD_GOSSIP_ITEM( 5, "Orgrimmar"                    , GOSSIP_SENDER_MAIN, 2001);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Silvermoon"                   , GOSSIP_SENDER_MAIN, 2005);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Thunder Bluff"                , GOSSIP_SENDER_MAIN, 2010);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Undercity"                    , GOSSIP_SENDER_MAIN, 2015);
			pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                 , GOSSIP_SENDER_MAIN, 5005);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 3000: //Neutral Town
			pPlayer->ADD_GOSSIP_ITEM( 5, "Booty Bay"                    , GOSSIP_SENDER_MAIN, 3001);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Dalaran"                      , GOSSIP_SENDER_MAIN, 3005);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Everlook"                     , GOSSIP_SENDER_MAIN, 3010);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Gadgetzan"                    , GOSSIP_SENDER_MAIN, 3015);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Mudsprocket"                  , GOSSIP_SENDER_MAIN, 3020);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Ratchet"                      , GOSSIP_SENDER_MAIN, 3025);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Shattrath City"               , GOSSIP_SENDER_MAIN, 3030);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Isle Of Quel'Danas"           , GOSSIP_SENDER_MAIN, 3035);
			pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                 , GOSSIP_SENDER_MAIN, 5005);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5000: //Dungeons
			pPlayer->ADD_GOSSIP_ITEM( 7, "Kalimdor ->"                  , GOSSIP_SENDER_MAIN, 5010);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Eastern Kingdoms ->"          , GOSSIP_SENDER_MAIN, 5015);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Outland ->"                   , GOSSIP_SENDER_MAIN, 5025);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Northrend ->"                 , GOSSIP_SENDER_MAIN, 5030);
			pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                 , GOSSIP_SENDER_MAIN, 5005);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5005: //Back To Main Menu
		// Main Menu for Alliance
		if (pPlayer->GetTeam() == ALLIANCE)
		{
			pPlayer->ADD_GOSSIP_ITEM( 7, "Alliance Town ->"                 , GOSSIP_SENDER_MAIN, 1000);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Neutral Town ->"                  , GOSSIP_SENDER_MAIN, 3000);
			if (votecheck)
			{
				pPlayer->ADD_GOSSIP_ITEM( 7, "Dungeons ->"                  , GOSSIP_SENDER_MAIN, 5000);
				pPlayer->ADD_GOSSIP_ITEM( 7, "Player Tools ->"              , GOSSIP_SENDER_MAIN, 4000);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Alliance vs Horde PvP"        , GOSSIP_SENDER_MAIN, 3500);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Take me to my Guild House"    , GOSSIP_SENDER_MAIN, 10010);
			}
		}
		else // Main Menu for Horde
		{
			pPlayer->ADD_GOSSIP_ITEM( 7, "Horde Town ->"                    , GOSSIP_SENDER_MAIN, 2000);
			pPlayer->ADD_GOSSIP_ITEM( 7, "Neutral Town ->"                  , GOSSIP_SENDER_MAIN, 3000);
			if (votecheck)
			{
				pPlayer->ADD_GOSSIP_ITEM( 7, "Dungeons ->"                  , GOSSIP_SENDER_MAIN, 5000);
				pPlayer->ADD_GOSSIP_ITEM( 7, "Player Tools ->"              , GOSSIP_SENDER_MAIN, 4000);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Alliance vs Horde PvP"        , GOSSIP_SENDER_MAIN, 3500);
				pPlayer->ADD_GOSSIP_ITEM( 9, "Take me to my Guild House"    , GOSSIP_SENDER_MAIN, 10010);
			}
		}

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5010: //Kalimdor
		pPlayer->ADD_GOSSIP_ITEM( 5, "Blackfathom Deeps"                    , GOSSIP_SENDER_MAIN, 6001);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Caverns of Time"                      , GOSSIP_SENDER_MAIN, 6005);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Dire Maul"                            , GOSSIP_SENDER_MAIN, 6010);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Maraudon"                             , GOSSIP_SENDER_MAIN, 6015);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Onyxia's Lair"                        , GOSSIP_SENDER_MAIN, 6020);
		if (pPlayer->GetTeam() == HORDE)
			pPlayer->ADD_GOSSIP_ITEM( 5, "Ragefire Chasm"                   , GOSSIP_SENDER_MAIN, 6025);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Razorfen Downs"                       , GOSSIP_SENDER_MAIN, 6030);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Razorfen Kraul"                       , GOSSIP_SENDER_MAIN, 6035);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Ruins of Ahn'Qiraj"                   , GOSSIP_SENDER_MAIN, 6040);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Temple of Ahn'Qiraj"                  , GOSSIP_SENDER_MAIN, 6045);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Wailing Caverns"                      , GOSSIP_SENDER_MAIN, 6050);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Zul'Farrak"                           , GOSSIP_SENDER_MAIN, 6055);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- Back"                              , GOSSIP_SENDER_MAIN, 5000);
    
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5015: //Eastern Kingdoms 1
		pPlayer->ADD_GOSSIP_ITEM( 5, "Blackrock Depths"                     , GOSSIP_SENDER_MAIN, 7001);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Blackrock Spire"                      , GOSSIP_SENDER_MAIN, 7005);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Blackwing Lair"                       , GOSSIP_SENDER_MAIN, 7010);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Deadmines"                            , GOSSIP_SENDER_MAIN, 7015);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Gnomeregan"                           , GOSSIP_SENDER_MAIN, 7020);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Isle Of Quel'Danas"                   , GOSSIP_SENDER_MAIN, 7025);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Karazhan"                             , GOSSIP_SENDER_MAIN, 7030);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Molten Core"                          , GOSSIP_SENDER_MAIN, 7035);
		pPlayer->ADD_GOSSIP_ITEM( 7, "More ->"                              , GOSSIP_SENDER_MAIN, 5020);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- Back"                              , GOSSIP_SENDER_MAIN, 5000);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5020: //Eastern Kingdoms 2
		pPlayer->ADD_GOSSIP_ITEM( 5, "Scarlet Monastery"                    , GOSSIP_SENDER_MAIN, 7040);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Scholomance"                          , GOSSIP_SENDER_MAIN, 7045);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Shadowfang Keep"                      , GOSSIP_SENDER_MAIN, 7050);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Stratholme"                           , GOSSIP_SENDER_MAIN, 7055);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Sunken Temple"                        , GOSSIP_SENDER_MAIN, 7060);
		if (pPlayer->GetTeam() == ALLIANCE)
			pPlayer->ADD_GOSSIP_ITEM( 5, "The Stockade"                     , GOSSIP_SENDER_MAIN, 7065);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Uldaman"                              , GOSSIP_SENDER_MAIN, 7070);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Zul'Aman"                             , GOSSIP_SENDER_MAIN, 7075);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Zul'Gurub"                            , GOSSIP_SENDER_MAIN, 7080);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- Back"                              , GOSSIP_SENDER_MAIN, 5015);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                         , GOSSIP_SENDER_MAIN, 5005);
    
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5025: //Outland	
		pPlayer->ADD_GOSSIP_ITEM( 5, "Auchindoun"                       , GOSSIP_SENDER_MAIN, 8001);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Black Temple"                     , GOSSIP_SENDER_MAIN, 8005);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Coilfang Reservoir"               , GOSSIP_SENDER_MAIN, 8010);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Gruul's Lair"                     , GOSSIP_SENDER_MAIN, 8015);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Hellfire Citadel"                 , GOSSIP_SENDER_MAIN, 8020);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Tempest Keep"                     , GOSSIP_SENDER_MAIN, 8025);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- Back"                          , GOSSIP_SENDER_MAIN, 5000);
    
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 5030: //Northrend	
		pPlayer->ADD_GOSSIP_ITEM( 5, "Ahn'Kahet"                        , GOSSIP_SENDER_MAIN, 9001);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Azjol-Nerub"                      , GOSSIP_SENDER_MAIN, 9005);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Drak'Tharon Keep"                 , GOSSIP_SENDER_MAIN, 9010);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Gun'Drak"                         , GOSSIP_SENDER_MAIN, 9015);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Icecrown Citadel"                 , GOSSIP_SENDER_MAIN, 9020);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Naxxramas"                        , GOSSIP_SENDER_MAIN, 9025);
		pPlayer->ADD_GOSSIP_ITEM( 5, "The Nexus"                        , GOSSIP_SENDER_MAIN, 9030);
		pPlayer->ADD_GOSSIP_ITEM( 5, "The Obsidian Sanctum"             , GOSSIP_SENDER_MAIN, 9035);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Utgarde Keep"                     , GOSSIP_SENDER_MAIN, 9040);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Utgarde Pinnacle"                 , GOSSIP_SENDER_MAIN, 9045);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Ulduar"                           , GOSSIP_SENDER_MAIN, 9050);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Violet Hold"                      , GOSSIP_SENDER_MAIN, 9055);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Vault of Archavon"                , GOSSIP_SENDER_MAIN, 9060);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- Back"                          , GOSSIP_SENDER_MAIN, 5000);
    
		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 4000: // Player Tools
		pPlayer->ADD_GOSSIP_ITEM( 5, "Heal Me!"                         , GOSSIP_SENDER_MAIN, 10030);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Reset Talent Points"              , GOSSIP_SENDER_MAIN, 4010);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Reset Pet Talent Points"          , GOSSIP_SENDER_MAIN, 4015);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Remove Resurrect Sickness"		, GOSSIP_SENDER_MAIN, 4020);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Reset Instance Locks Cost: [2 VP]", GOSSIP_SENDER_MAIN, 10015);
		pPlayer->ADD_GOSSIP_ITEM( 5, "Reset Cooldowns Cost: [100 Gold]" , GOSSIP_SENDER_MAIN, 10025);
		pPlayer->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                   , GOSSIP_SENDER_MAIN, 5005);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 10010: // Guild House Menu
		if (pPlayer->GetGuildHouseMask() > 1)
		{
			pPlayer->ADD_GOSSIP_ITEM( 5, "Guild Hall"                   , GOSSIP_SENDER_MAIN, 10035);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Guild Arena"					, GOSSIP_SENDER_MAIN, 10040);
			pPlayer->ADD_GOSSIP_ITEM( 5, "Summit Course"				, GOSSIP_SENDER_MAIN, 10045);
			pPlayer->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"               , GOSSIP_SENDER_MAIN, 5005);

			pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
		}
		else
		{
			pPlayer->CLOSE_GOSSIP_MENU();
			ChatHandler(pPlayer).PSendSysMessage(LANG_NO_GUILD_HOUSE);
		}
	break;

	//////////////////////////////////////////////////ALLIANCE///////////////////////////////////////////////////////////////

	case 1001: // Darnassus
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
    
	break;

	case 1005: // Exodar
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, -3954.20f, -11656.54f, -138.69f, 0.0f);
    
	break;

	case 1010: // Ironforge
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
    
	break;

	case 1015: // Stormwind
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -8960.14f, 516.266f, 96.3568f, 0.0f);
    
	break;

	//////////////////////////////////////////////////HORDE///////////////////////////////////////////////////////////////

	case 2001: // Orgrimmar
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, 1552.5f, -4420.66f, 8.94802f, 0.0f);
    
	break;

	case 2005: // Silvermoon
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 9338.74f, -7277.27f, 13.7895f, 0.0f);
    
	break;

	case 2010: // Thunder Bluff
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -1290.0f, 147.033997f, 129.682007f, 4.919000f);
    
	break;

	case 2015: // Undercity
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, 1819.71f, 238.79f, 60.5321f, 0.0f);
    
	break;

	//////////////////////////////////////////////////NEUTRAL///////////////////////////////////////////////////////////////

	case 3001:// Booty Bay
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -14438.2f, 472.22f, 15.32f, 0.65f);
    
	break;

	case 3005: //Dalaran
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 5819.08f, 643.99f, 647.80f, 3.32f);
    
	break;

	case 3010: //Everlook
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, 6724.77f, -4610.68f, 720.78f, 4.78f);
    
	break;

	case 3015: //Gadgetzan
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -7173.26f, -3785.60f, 8.37f, 6.13f);
    
	break;

	case 3020: //Mudsprocket
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -4564.79f, -3172.38f, 33.93f, 3.21f);
    
	break;

	case 3025: //Ratchet
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -956.664f, -3754.71f, 5.33239f, 0.996637f);
    
	break;

	case 3030:// Shattrath City
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, -1850.209961f, 5435.821777f, -10.961435f, 3.403913f);
    
	break;

	case 3035:// Isle Of Quel'Danas
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 12947.4f,-6893.31f,5.68398f,3.09154f);
    
	break;

	//////////////////////////////////////////////////KALIMDOR///////////////////////////////////////////////////////////////

	case 6001:// Blackfathom Deeps
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, 4248.72f, 744.35f, -24.67f, 1.34f);
    
	break;
  
	case 6005:// Caverns of Time
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -8173.66f, -4746.36f, 33.84f, 4.94f);
    
	break;

	case 6010:// Dire Maul
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -3960.95f, 1130.64f, 161.05f, 0.0f);
    
	break;

	case 6015:// Maraudon
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -1431.33f, 2962.34f, 98.23f, 4.74f);
    
	break;

	case 6020:// Onyxia's Lair
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
    
	break;

	case 6025:// Ragefire Chasm
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, 1814.47f, -4419.46f, -18.78f, 5.28f);
    
	break;

	case 6030:// Razorfen Downs
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -4657.88f, -2525.59f, 81.4f, 4.16f);
    
	break;
    
	case 6035:// Razorfen Kraul
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -4463.6f, -1664.53f, 82.26f, 0.85f);
    
	break;

	case 6040:// Ruins of Ahn'Qiraj
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -8413.33f, 1501.27f, 29.64f, 2.61f);
    
	break;

	case 6045:// Temple of Ahn'Qiraj
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
    
	break;

	case 6050:// Wailing Caverns
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -722.53f,-2226.30f,16.94f,2.71f);
    
	break;

	case 6055:// Zul'Farrak
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(1, -6801.9f, -2890.22f, 8.88f, 6.25f);
    
	break;

	//////////////////////////////////////////////////EASTERN KINGDOMS///////////////////////////////////////////////////////////////

	case 7001:// Blackrock Depths
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -7180.57f, -920.04f, 165.49f, 5.02f);
    
	break;

	case 7005:// Blackrock Spire
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -7526.77f, -1225.64f, 285.73f, 5.31f);
    
	break;

	case 7010:// Blackwing Lair
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(469, -7672.61f, -1107.21f, 396.65f, 3.75f);
    
	break;

	case 7015:// Deadmines
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -11208.2f, 1675.92f, 24.57f, 1.48f);
    
	break;

	case 7020:// Gnomeregan
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -5163.32f, 927.18f, 257.158f, 1.44f);
    
	break;
 
	case 7025:// Isle Of Quel'Danas
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 13010.00f, -6907.64f, 9.58f, 4.58f);
    
	break;

	case 7030:// Karazhan
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -11119.6f, -2011.42f, 47.09f, 0.65f);
    
	break;

	case 7035:// Molten Core
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(230, 1114.85f, -457.76f, -102.81f, 3.83f);
    
	break;

	case 7040:// Scarlet Monastery
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, 2843.89f,-693.74f,139.32f,5.11f);
    
	break;

	case 7045:// Scholomance
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, 1273.06f, -2574.01f, 92.66f, 2.06f);
    
	break;

	case 7050:// Shadowfang Keep
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -239.54f, 1550.8f, 76.89f, 1.18f);
    
	break;

	case 7055:// Stratholme
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, 3370.76f, -3343.63f, 142.26f, 5.23f);
    
	break;

	case 7060:// Sunken Temple
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
    
	break;

	case 7065:// The Stockade
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -8766.89f, 844.6f, 88.43f, 0.69f);
    
	break;
 
	case 7070:// Uldaman
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -6070.72f, -2955.33f, 209.78f, 0.05f);
    
	break;

	case 7075:// Zul'Aman
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 6851.09f, -7979.71f, 183.54f, 4.72f);
    
	break;

	case 7080:// Zul'Gurub
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(0, -11916.4f, -1216.23f, 92.28f, 4.75f);
    
	break;

	//////////////////////////////////////////////////OUTLAND///////////////////////////////////////////////////////////////

	case 8001:// Auchindoun
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, -3322.92f, 4931.02f, -100.56f, 1.86f);
    
	break;

	case 8005:// Black Temple
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, -3649.1f, 317.33f, 35.19f, 2.97f);
    
	break;

	case 8010:// Coilfang Reservoir
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 721.08f, 6846.77f, -68.75f, 0.34f);
    
	break;

	case 8015:// Gruul's Lair
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 3539.01f, 5082.36f, 1.69f, 0.0f);
    
	break;

	case 8020:// Hellfire Citadel
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, -292.71f, 3146.77f, 31.60f, 2.05f);
    
	break;

	case 8025:// Tempest Keep
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(530, 3087.62f, 1376.27f, 184.8f, 4.63f);
    
	break;

	//////////////////////////////////////////////////NORTHREND///////////////////////////////////////////////////////////////

	case 9001:// Ahn'Kahet
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 3646.76f, 2045.17f, 1.79f, 4.37f);
    
	break;

	case 9005:// Azjol-Nerub
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 3675.43f, 2169.00f, 35.90f, 2.29f);
    
	break;

	case 9010:// Drak'Tharon Keep
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 4450.86f, -2045.25f, 162.83f, 0.00f);
    
	break;

	case 9015:// Gun'Drak
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 6937.54f, -4455.98f, 450.68f, 1.00f);
    
	break;

	case 9020:// Icecrown Citadel
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 6139.24f, 2233.72f, 510.79f, 3.56f);
    
	break;

	case 9025:// Naxxramas
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 3668.72f, -1262.46f, 243.622f, 4.785f);
    
	break;

	case 9030:// The Nexus
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 3789.95f, 6961.48f, 104.23f, 0.28f);
    
	break;

	case 9035:// The Obsidian Sanctum
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 3625.78f, 280.4f, -120.14f, 3.25f);
    
	break;

	case 9040:// Ulduar
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 1219.72f, -4865.28f, 41.25f, 0.31f);
    
	break;

	case 9045:// Utgarde Keep
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 1245.69f, -4856.59f, 216.86f, 3.45f);
    
	break;

	case 9050:// Utgarde Pinnacle
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 8976.24f, -1281.33f, 1059.01f, 0.58f);
    
	break;

	case 9055:// Violet Hold
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 5679.82f, 486.80f, 652.40f, 4.08f);
    
	break;

	case 9060:// Vault of Archavon
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(571, 5440.11f, 2840.76f, 420.42f, 0.01f);
    
	break;

	//////////////////////////////////////////Player Tools////////////////////////////////////////////////////////

	case 4005:// Innkeeper Bind your new Home
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->SetBindPoint(pCreature->GetGUID());
	break;

	case 4010:// Reset Talent Points
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->SendTalentWipeConfirm(pCreature->GetGUID());
	break;

	case 4015:// Reset Pet Talent Points
		pPlayer->CLOSE_GOSSIP_MENU();
		if(pPlayer->GetPet())
			pPlayer->ResetPetTalents();
		else
			pCreature->MonsterWhisper("You don't have a pet.", pPlayer->GetGUID());
	break;

	case 4020://Remove Res Sickness
		if(!pPlayer->HasAura(15007,0))
		{
			pCreature->MonsterWhisper("You don't have resurrection sickness.", pPlayer->GetGUID());
			OnGossipHello(pPlayer, pCreature);
			return;
		}

		pCreature->CastSpell(pPlayer,38588,false); // Healing effect
		pPlayer->RemoveAurasDueToSpell(15007);
		pPlayer->CLOSE_GOSSIP_MENU();
	break;

	 pPlayer->CLOSE_GOSSIP_MENU();

	//////////////////////////////////////////TOOLS////////////////////////////////////////////////////////

	case 3500:// Alliance vs Horde PvP
		pPlayer->CLOSE_GOSSIP_MENU();
		if (pPlayer->GetTeam() == ALLIANCE) // Razor Hill PvP For Alliance
			pPlayer->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
		else // Goldshire PvP For Horde
			pPlayer->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
	break;

	case 10015: // Player Tools
		pPlayer->ADD_GOSSIP_ITEM( 5, "Yes, at a Cost of 2 VP."              , GOSSIP_SENDER_MAIN, 10020);
		pPlayer->ADD_GOSSIP_ITEM( 5, "No, Return to Main Menu."             , GOSSIP_SENDER_MAIN, 5005);

		pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
	break;

	case 10020: // Player Tools
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->UnbindAllInst();
	break;

	case 10025:
		if (pPlayer->GetMoney() < 1000000)
		{
			ChatHandler(pPlayer).PSendSysMessage("You do not have enough gold.", pPlayer->GetGUID());
		}
		else
		{
			pPlayer->ModifyMoney(-1000000);
			pPlayer->RemoveAllSpellCooldown();
			ChatHandler(pPlayer).PSendSysMessage("Your cooldowns have been reset.");
		}
		pPlayer->CLOSE_GOSSIP_MENU();
	break;

	case 10030:
		if (!pPlayer->isInCombat())
			pPlayer->ResurrectPlayer(1.0f);
		else
			ChatHandler(pPlayer).PSendSysMessage("You cannot heal in combat.");
		pPlayer->CLOSE_GOSSIP_MENU();
	break;

	case 10035:// Guild Hall
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(37, 1009.9f, 284.2f, 328.96f, 0.17f);
	break;

	case 10040:// Guild Arena
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(37, 779.7f, 152.2f, 269.5f, 1.770f);
	break;

	case 10045:// Summit Course
		pPlayer->CLOSE_GOSSIP_MENU();
		pPlayer->TeleportTo(37, 486.89f, 58.80f, 262.38f, 3.875f);
	break;
    
	break;

	}
	}

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
	{
		// Main menu
		pPlayer->PlayerTalkClass->ClearMenus();
		if (uiSender == GOSSIP_SENDER_MAIN)
		SendDefaultMenu_TeleNPCVote(pPlayer, pCreature, uiAction);

	return true;
	}
};

void AddSC_tele_npc_vote()
{
    new tele_npc_vote();
}