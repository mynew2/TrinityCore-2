#include "ScriptPCH.h"
#include "Language.h"
#include "Config.h"

int TRENADOR_ORIGINAL = 1; // 1 = Sumona Treinador e o segue. Nao requer script multitreiner. 2 = abre Menu Treinador original. Requer script multitrainer 

enum
{
	TSUPREMO = 19910,
	SAIR = 19920,
	RESETAR__TALENTOS = 19930,
	DUAL_ESPECIALIZACAO = 19940,
	TREINADOR_ORIGINAL_SPELLSUMMON = 19950,
	TREINADOR_MENU_ORIGINAL = 19960,
	GLYPH_NPC_VENDOR = 19970
};


uint32 SI[] = {
	64380, 23885, 23880, 44461, 25346, 10274, 10273, 8418, 8419, 7270, 7269, 7268, 54648, 12536, 24530, 70909,
	12494, 57933, 24224, 27095, 27096, 27097, 27099, 32841, 56131, 56160, 56161, 48153, 34754, 64844, 64904, 48085,
	33110, 48084, 28276, 27874, 27873, 7001, 49821, 53022, 47757, 47750, 47758, 47666, 53001, 52983, 52998, 52986,
	52987, 52999, 52984, 53002, 53003, 53000, 52988, 52985, 42208, 42209, 42210, 42211, 42212, 42213, 42198, 42937,
	42938, 12484, 12485, 12486, 44461, 55361, 55362, 34913, 43043, 43044, 38703, 38700, 27076, 42844, 42845, 64891,
	25912, 25914, 25911, 25913, 25902, 25903, 27175, 27176, 33073, 33074, 48822, 48820, 48823, 48821, 20154, 25997,
	20467, 20425, 67, 26017, 34471, 53254, 13812, 14314, 14315, 27026, 49064, 49065, 60202, 60210, 13797, 14298,
	14299, 14300, 14301, 27024, 49053, 49054, 52399, 1742, 24453, 53548, 53562, 52016, 26064, 35346, 57386, 57389,
	57390, 57391, 57392, 57393, 55509, 35886, 43339, 45297, 45298, 45299, 45300, 45301, 45302, 49268, 49269, 8349,
	8502, 8503, 11306, 11307, 25535, 25537, 61650, 61654, 63685, 45284, 45286, 45287, 45288, 45289, 45290, 45291,
	45292, 45293, 45294, 45295, 45296, 49239, 49240, 26364, 26365, 26366, 26367, 26369, 26370, 26363, 26371, 26372,
	49278, 49279, 32176, 32175, 21169, 47206, 27285, 47833, 47836, 42223, 42224, 42225, 42226, 42218, 47817, 47818,
	42231, 42232, 42233, 42230, 48466, 44203, 44205, 44206, 44207, 44208, 48444, 48445, 33891, 52374, 57532, 59921,
	52372, 49142, 52375, 47633, 47632, 52373, 50536, 27214, 47822, 11682, 11681, 5857, 1010, 24907, 24905, 53227,
	61391, 61390, 61388, 61387, 64801, 5421, 9635, 1178, 20186, 20185, 20184, 20187, 25899, 24406, 50581, 30708,
	8946, 42459, 23455, 48076
};
uint32 SR[][99]
{		// Warrior 
	{ 3127, 264, 266, 5011, 15590, 200, 227, 2567, 674, 750, 12678 },
		//DK 
	{ 198, 199, 3714, 53323, 53331, 53341, 53342, 53343, 53344, 54446, 54447, 62158, 70164 },
	//Druid
	{ 15590, 200, 5225, 20719, 62600 },
	// Hunter 
	{ 674, 42459, 8737, 15590, 2567, 227, 266, 5011, 200, 201, 1462, 3127, 6197, 19885 },
	// mage
	{ 1180, 201, /*Alliance->*/ 3562, 3561, 3565, 11416, 11419, 32266, 32271, 33690, 33691, 49359, 49360, /*Horde->*/ 3563, 3566, 3567, 11417, 11418, 11420, 32272, 35715, 35717, 32267, 49358, 49361 },
	//==Fim spell Mage======================================================================
	// paladin
	{ 750, 200, 196, 197, 3127 },
	//Rogue
	{ 264, 15590, 5011, 201, 196, 198, 3127, 2836 },
	//Shaman
	{ 8737, 1180, 15590, 196, 197, 199, 6196, 66842, 66843, 66844 },
	//Warlock
	{ 201, 5500, 5784, 29858, 33388, 47836 },
};

std::vector<uint32> SpellsIguinorar = std::vector<uint32>(SI, SI + sizeof(SI) / sizeof(SI[0]));

bool GetIguinorarSpells(uint32 IDspell)
{
	for (std::vector<uint32>::const_iterator itr = SpellsIguinorar.begin(); itr != SpellsIguinorar.end(); ++itr)
	if (IDspell == (*itr))
		return true;
	return false;
}
bool SpellRestantes(Player* player, uint32 SpellClasses)
{
	uint8 pLevel = player->getLevel() + 1;
	switch (SpellClasses = player->getClass())
	{
	case CLASS_WARRIOR:
		for (int i = 0; i < 11; i++)
		{
			player->LearnSpell(SR[0][i], false);
		}
		if (player->HasSpell(12294))
			player->LearnSpell(47486, false);

		if (player->HasSpell(20243))
			player->LearnSpell(47498, false);

		break;
	case CLASS_DEATH_KNIGHT:
		for (int i = 0; i < 13; i++)
		{
			player->LearnSpell(SR[1][i], false);
		}
		if (player->HasSpell(55050)) //Heart Strike Rank 1
			player->LearnSpell(55262, false);

		if (player->HasSpell(49143)) //Frost Strike Rank 1
			player->LearnSpell(55268, false);

		if (player->HasSpell(49184)) //Howling Blast Rank 1
			player->LearnSpell(51411, false);

		if (player->HasSpell(55090)) //Scourge Strike Rank 1
			player->LearnSpell(55271, false);

		if (player->HasSpell(49158)) //Corpse Explosion Rank 1
			player->LearnSpell(51328, false);

		if (player->GetFreeTalentPoints() == +25){
			player->CastSpell(player, 26410, false);
			player->ResetTalents();
			player->SetFreeTalentPoints(71);
			player->SendTalentsInfoData(false);
		}
		break;
	case CLASS_DRUID:
		for (int i = 0; i < 5; i++)
		{
			player->LearnSpell(SR[2][i], false);
		}
		if (player->HasSpell(50516)) //Typhoon Rank 1
			player->LearnSpell(61384, false);

		if (player->HasSpell(48505)) //Starfall Rank 1
			player->LearnSpell(53201, false);

		if (player->HasSpell(5570)) //Insect Swarm Rank 1
			player->LearnSpell(48468, false);

		if (player->HasSpell(48438)) //Wild Growth Rank 1
			player->LearnSpell(53251, false);

		if (player->HasSpell(33876) && player->HasSpell(33878) && player->HasSpell(33917))
		{
			player->LearnSpell(48564, false);
			player->LearnSpell(48566, false);
		}
		if (player->HasSpell(5487))
			player->LearnSpell(9634, false);
		break;
	case CLASS_HUNTER:
		for (int i = 0; i < 14; i++)
		{
			player->LearnSpell(SR[3][i], false);
		}
		if (player->HasSpell(19386)) //Wyvern String Rank 1
			player->LearnSpell(49012, false);

		if (player->HasSpell(53301)) //Explosive Shot Rank 1
			player->LearnSpell(60053, false);

		if (player->HasSpell(19306)) //Conter Attack Rank 1
			player->LearnSpell(48999, false);

		if (player->HasSpell(19434)) //Aimed Shot Rank 1
			player->LearnSpell(49050, false);
		break;
	case CLASS_MAGE:
		for (int i = 0; i < 25; i++)
		{
			SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SR[4][i]);
			if (!spellInfo)	continue;
			if (!(pLevel > spellInfo->SpellLevel)) continue;

			if (!player->GetSession()->GetPlayer()->IsSpellFitByClassAndRace(SR[4][i])) continue;

			player->LearnSpell(SR[4][i], false);
		}
		if (player->HasSpell(44425)) //Arcane Barrage Rank 1
			player->LearnSpell(44781, false);

		if (player->HasSpell(11113)) //Blast Wave Rank 1
			player->LearnSpell(42945, false);

		if (player->HasSpell(31661)) //Dragon Breath  Rank 1
			player->LearnSpell(42950, false);

		if (player->HasSpell(44457)) //Living Bomb Rank 1
			player->LearnSpell(55360, false);

		if (player->HasSpell(11366)) //Pyroblast Rank 1
			player->LearnSpell(42891, false);

		if (player->HasSpell(11426)) //Ice Barrier Rank 1
			player->LearnSpell(43039, false);

		break;
	case CLASS_PALADIN:
		for (int i = 0; i < 5; i++)
		{
			player->LearnSpell(SR[5][i], false);
		}
		if (player->GetTeam() == ALLIANCE) // spell so para alliance
		{
			player->LearnSpell(31801, false);
			player->LearnSpell(13819, false);
			player->LearnSpell(23214, false);
		}
		else{ // spell so para Horde
			player->LearnSpell(53736, false);
			player->LearnSpell(34769, false);
			player->LearnSpell(34767, false);
		}
		if (player->HasSpell(20925)) //Holy Shield Rank 1
			player->LearnSpell(48952, false);

		if (player->HasSpell(20473)) //Holy Shock Rank 1
			player->LearnSpell(48825, false);

		if (player->HasSpell(31935)) //Avengers Shield Rank 1
			player->LearnSpell(48827, false);

		if (player->HasSpell(20911)) //Blessing of Sanctuary Rank 1
			player->LearnSpell(25899, false);

		/* Devido ao bug de paladin nesta nova core que tem duas [Seal of Righteousness] 
		Nao achei outra  forma de resolver este bug dessa nova core 11/09/2014.
		Esta spell abaixo e somente para remover o bug dessa core 11/09/2014. As cores anteriores nao tem este bug.
		*/		// Remover Bug: [Seal of Righteousness]
		player->RemoveSpell(20154, true); // este comando dever ser retirada se aplica este script em outras cores.
		break;
	case CLASS_PRIEST:
		if (player->HasSpell(34914)) //Vampiric Touch Rank 1
			player->LearnSpell(48160, false);

		if (player->HasSpell(47540)) //Penance Rank 1
			player->LearnSpell(53007, false);

		if (player->HasSpell(724)) //LightWell Rank 1
			player->LearnSpell(48087, false);

		if (player->HasSpell(19236)) //Desperate Prayer Rank 1
			player->LearnSpell(48173, false);

		if (player->HasSpell(34861)) //Circle Of healing Rank 1
			player->LearnSpell(48089, false);

		if (player->HasSpell(15407)) //Mind Flay Rank 1
			player->LearnSpell(48156, false);

		player->LearnSpell(1180, false); // Weapon Daggers
		break;
	case CLASS_ROGUE:
		for (int i = 0; i < 6; i++)
		{
			player->LearnSpell(SR[6][i], false);
		}
		if (player->HasSpell(16511)) //Hemorrhage Rank 1
			player->LearnSpell(48660, false);

		if (player->HasSpell(1329)) //Mutilate Rank 1
			player->LearnSpell(48666, false);
		break;
	case CLASS_SHAMAN:
		for (int i = 0; i < 10; i++)
		{
			player->LearnSpell(SR[7][i], false);
		}
		if (player->GetTeam() == ALLIANCE)
		{
			player->LearnSpell(32182, false);
		}
		else{ // Horde
			player->LearnSpell(2825, false);
		}
		if (player->HasSpell(61295)) //Riptide Rank 1
			player->LearnSpell(61301, false);

		if (player->HasSpell(974)) //Earth Shield Rank 1
			player->LearnSpell(49284, false);

		if (player->HasSpell(30706)) //Totem of Wrath Rank 1
			player->LearnSpell(57722, false);

		if (player->HasSpell(51490)) //TunderStorm Rank 1
			player->LearnSpell(59159, false);
		break;
	case CLASS_WARLOCK:
		for (int i = 0; i < 6; i++)
		{
			player->LearnSpell(SR[8][i], false);
		}
		if (player->HasSpell(17877)) //ShadowBurn Rank 1
			player->LearnSpell(47827, false);

		if (player->HasSpell(30283)) //ShadowFury Rank 1
			player->LearnSpell(47847, false);

		if (player->HasSpell(50796)) //Chaos Bolt Rank 1
			player->LearnSpell(59172, false);

		if (player->HasSpell(30108)) //Unstable Affliction Rank 1
			player->LearnSpell(47843, false);

		if (player->HasSpell(48181)) //Spell Haunt Rank 1
			player->LearnSpell(59164, false);

		if (player->HasSpell(18220)) //Dark Pact Rank 1
			player->LearnSpell(59092, false);
		break;
	default:
		break;
	}
	return true;
}

bool TreinadorSupremo(Player* player, uint8 plevelup)
{
	if (plevelup == player->getLevel() + 1)
		return true;
	ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(player->GetSession()->GetPlayer()->getClass());
	if (!classEntry)
		return true;
	uint32 family = classEntry->spellfamily;

	for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
	{
		SkillLineAbilityEntry const* entry = sSkillLineAbilityStore.LookupEntry(i);
		if (!entry)
			continue;

		SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(entry->spellId);
		if (!spellInfo)	continue;

		// skip server-side/triggered spells
		if (spellInfo->SpellLevel == 0)	continue;

		// skip wrong class/race skills
		if (!player->GetSession()->GetPlayer()->IsSpellFitByClassAndRace(spellInfo->Id)) continue;

		// skip other spell families
		if (spellInfo->SpellFamilyName != family) continue;

		// Pulas spells nao validas ou spell de talentos que nao poder ser treinado de imediato 
		// OBS: Lembre de quando distripuir seus talentos volte no npc para treinar as spell de talentos... 
		if (GetIguinorarSpells(spellInfo->Id))	continue;

		// skip spells with first rank learned as talent (and all talents then also)
		if (GetTalentSpellCost(spellInfo->GetFirstRankSpell()->Id) > 0)	continue;

		// skip broken spells
		if (!SpellMgr::IsSpellValid(spellInfo, player->GetSession()->GetPlayer(), false)) continue;

		// Spell Restante e Spell de Talentos
		if (!SpellRestantes(player, plevelup)) continue;
				
		// Nao inclui Teleports, mounts and other spells.
		if ((spellInfo->AttributesEx7 & SPELL_ATTR7_HORDE_ONLY && player->GetTeam() != HORDE)
			|| (spellInfo->AttributesEx7 & SPELL_ATTR7_ALLIANCE_ONLY && player->GetTeam() != ALLIANCE)) continue;

		// Add spell de acordo com o level. Skip spell level invalido
		if (spellInfo->BaseLevel != plevelup && sSpellMgr->IsSpellValid(spellInfo, player)) continue;

		bool validarAbilidades = false;
		SkillLineAbilityMapBounds Limitador = sSpellMgr->GetSkillLineAbilityMapBounds(spellInfo->Id);
		for (SkillLineAbilityMap::const_iterator itr = Limitador.first; itr != Limitador.second; ++itr)
		{
			if (itr->second->spellId == spellInfo->Id && itr->second->racemask == 0 && itr->second->AutolearnType == 0)
			{
				validarAbilidades = true;
				SpellInfo const* prevSpell = spellInfo->GetPrevRankSpell();
				if (prevSpell && !player->HasSpell(prevSpell->Id))
				{
					validarAbilidades = false;
					break;
				}
				if (GetTalentSpellPos(itr->second->spellId))
				if (!prevSpell || !player->HasSpell(prevSpell->Id) || spellInfo->GetRank() == 1)
					validarAbilidades = false;
				break;
			}
		} 
		if (validarAbilidades){ 
			if (player->HasSpell(spellInfo->Id)) continue;
			player->GetSession()->GetPlayer()->LearnSpell(spellInfo->Id, false);
		}
	}
	TreinadorSupremo(player, ++plevelup); // Add spell de acordo com o level
	player->SaveToDB();

	player->CastSpell(player, 47445, false); // Spell so para visual		
	return true;
}

// Tempo para summonar a proxima vez
std::map<uint32, uint32> MemoriaTempo;
uint32 Minutos = 3;
uint32 CalculateMinutos(uint32 m_time)
{
	if (m_time <= 60000)
		Minutos = 1;
	else if (m_time <= 120000)
		Minutos = 2;
	else if (m_time <= 180000) // 180000 = 3 minutes
		Minutos = 3;

return Minutos;
}

// Nao requer MultiTrainer nem MultiVendor
void SumonarTrainerOriginais(Player* player, Creature* _creature, uint32 TreinadorClasses)
{
	bool SumonarEM = true;
	if (!MemoriaTempo.empty())
	{
		std::map<uint32, uint32>::iterator itr = MemoriaTempo.find(player->GetGUIDLow());
		if (itr != MemoriaTempo.end())
		if (GetMSTimeDiffToNow(itr->second) < 60000) // 3 minutos = 180000 | 2 minutos = 120000  | 1 minutos = 60000  e etc.
		{
			ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000Espere %u minuto(s) para poder summonar novamente.|r", CalculateMinutos(GetMSTimeDiffToNow(itr->second)));
			SumonarEM = false;
		}
		else
		{
			MemoriaTempo.erase(player->GetGUIDLow());
			SumonarEM = true;
		}
	}
	// Tempo em que o npc fica sumonado e te seguinto
	uint32 TEMPO__SUMMON = 60000; // 3 minutos = 180000 | 2 minutos = 120000  | 1 minutos = 60000  e etc.

	float x, y, z;
	player->GetPosition(x, y, z);
 
#define summDruid player->SummonCreature(26324, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summHunter player->SummonCreature(26325, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summMage player->SummonCreature(26326, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summPaladin player->SummonCreature(26327, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summPriest player->SummonCreature(26328, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summRogue player->SummonCreature(26329, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summShaman player->SummonCreature(26330, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summWarlock player->SummonCreature(26331, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summWarrioR player->SummonCreature(26332, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define summDK player->SummonCreature(28474, x, y-1, z, +1, TEMPSUMMON_TIMED_DESPAWN, TEMPO__SUMMON)
#define MeSeguir GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, _creature->GetFollowAngle() + 8)

	player->PlayerTalkClass->ClearMenus();
	if (SumonarEM){
		MemoriaTempo[player->GetGUIDLow()] = getMSTime();

		switch (TreinadorClasses = player->getClass())
		{
		case CLASS_WARRIOR:
			summWarrioR->MeSeguir;			
			_creature->CastSpell(player, 44328, false); 
			break;
		case CLASS_PALADIN:
			summPaladin->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_DEATH_KNIGHT:
			summDK->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_DRUID:
			summDruid->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_HUNTER:
			summHunter->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_MAGE:
			summMage->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_PRIEST:
			summPriest->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_ROGUE:
			summRogue->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_WARLOCK:
			summWarlock->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;
		case CLASS_SHAMAN:
			summShaman->MeSeguir;
			_creature->CastSpell(player, 44328, false);
			break;

		default:
			return;
		}
	}
	return;
	/*
	player->CastSpell(player, 47359, false); // Trenador Druid
	player->CastSpell(player, 47360, false); // Trenador Hunter
	player->CastSpell(player, 47361, false); // Tranador Mage
	player->CastSpell(player, 47362, false); // Tranador Paladin
	player->CastSpell(player, 47363, false); // Tranador Priest
	player->CastSpell(player, 47364, false); // Tranador Rogue
	player->CastSpell(player, 47365, false); // Tranador Shaman
	player->CastSpell(player, 47366, false); // Tranador Warlock
	player->CastSpell(player, 47367, false); // Trenador WarrioR
	*/
}
// Menu Trenadores Originais: Requer MultiTrainer
/*
void TrenadoresOriginais(Player* player, Creature* creature, uint8 TrainerClass)
{
	uint8 GetRace = player->GetTeam() == ALLIANCE;

	switch (TrainerClass = player->getClass())
	{
	case CLASS_WARRIOR:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 914);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 3408);
		break;
	case CLASS_PALADIN:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 5491);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 23128);
		break;
	case CLASS_DEATH_KNIGHT:
		player->GetSession()->SendTrainerList(creature->GetGUID(), 28474);// Todos
		break;
	case CLASS_DRUID:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 5504);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 16655);
		break;
	case CLASS_HUNTER:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 5515);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 3352);
		break;
	case CLASS_MAGE:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 5498);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 5885);
		break;
	case CLASS_PRIEST:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 5489);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 6018);
		break;
	case CLASS_ROGUE:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 13283);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 3328);
		break;
	case CLASS_SHAMAN:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 20407);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 3344);
		break;
	case CLASS_WARLOCK:
		if (GetRace)
			player->GetSession()->SendTrainerList(creature->GetGUID(), 5496);//Alliance
		player->GetSession()->SendTrainerList(creature->GetGUID(), 3325);
		break;
	}
	return;
}
// Glyphs_Vendedor: Requer MultiVendor 
bool VendedorGlyphs(Player* player, Creature* creature, uint32 PguidClass)
{
	switch (PguidClass = player->getClass())
	{
	case CLASS_WARRIOR:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99901);
		break;
	case CLASS_PALADIN:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99902);
		break;
	case CLASS_MAGE:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99903);
		break;
	case CLASS_HUNTER:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99904);
		break;
	case CLASS_DRUID:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99905);
		break;
	case CLASS_WARLOCK:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99906);
		break;
	case CLASS_PRIEST:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99907);
		break;
	case CLASS_ROGUE:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99908);
		break;
	case CLASS_DEATH_KNIGHT:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99909);
		break;
	case CLASS_SHAMAN:
		player->GetSession()->SendListInventory(creature->GetGUID(), 99910);
		break;
	}
	return true;
}
*/
class npc_treinador_supremo : public CreatureScript
{
public:
	npc_treinador_supremo() : CreatureScript("npc_treinador_supremo") {}

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->PlayerTalkClass->ClearMenus();
		creature->CastSpell(creature, 44342, false); //visual
		if (player->IsInCombat())
		{
			player->CLOSE_GOSSIP_MENU();
			ChatHandler(player->GetSession()).SendSysMessage("|cffFF0000Voce esta em combate!|r");
		}
		else{			
			player->ADD_GOSSIP_ITEM(3, "|cff008B8B|TInterface\\icons\\INV_Sigil_UlduarAll:30|tTreinar Spell|r", GOSSIP_SENDER_MAIN, TSUPREMO);

			if (TRENADOR_ORIGINAL == 1)
				player->ADD_GOSSIP_ITEM(3, "|cffFF0000|TInterface\\icons\\INV_Sigil_Mimiron:30|t  Treinadores Originais SetSumm|r", GOSSIP_SENDER_MAIN, TREINADOR_ORIGINAL_SPELLSUMMON); //nao requer script muitTrainer

			if (TRENADOR_ORIGINAL == 2)
				player->ADD_GOSSIP_ITEM(3, "|cffFF0000|TInterface\\icons\\Ability_Vehicle_LaunchPlayer:30|t Trenadores Originais SetMenu|r", GOSSIP_SENDER_MAIN, TREINADOR_MENU_ORIGINAL); //requer script muitTrainer

			player->ADD_GOSSIP_ITEM_EXTENDED(3, "|cffCD2626|TInterface\\icons\\Ability_DualWield:30|t Especializacao Talentos Duplos|r", GOSSIP_SENDER_MAIN, DUAL_ESPECIALIZACAO, "Voce tem certesa que quer compra\nEspecializacao Telentos Duplos\n", 3 * GOLD, false);
	//		player->ADD_GOSSIP_ITEM(3, "|cffFF0000|TInterface\\icons\\INV_Inscription_MinorGlyph20:30|t Comprar Glyphs|r", GOSSIP_SENDER_MAIN, GLYPH_NPC_VENDOR); //Requer script MultiVendor
			player->ADD_GOSSIP_ITEM(4, "|cffFF0000|TInterface\\icons\\Achievement_BG_hld4bases_EOS:40|t Resetar Talentos|r", GOSSIP_SENDER_MAIN, RESETAR__TALENTOS);

			player->ADD_GOSSIP_ITEM(8, "|cffFF0000|TInterface\\icons\\Ability_Hunter_MarkedForDeath:20|t Sair", GOSSIP_SENDER_MAIN, SAIR);
			player->SEND_GOSSIP_MENU(1, creature->GetGUID());
			player->PlayerTalkClass->SendGossipMenu(11110, creature->GetGUID());
		}
		return true;		
	}
	bool OnGossipSelect(Player* player, Creature* _creature, uint32 uiSender, uint32 action)
	{
		switch (action)
		{
		case TSUPREMO:
			_creature->CastSpell(player, 26410, false); // Spell so para visual
			TreinadorSupremo(player, action);
			player->CLOSE_GOSSIP_MENU();
			break;
		case TREINADOR_MENU_ORIGINAL:
			//	TrenadoresOriginais(player, _creature, action);
			ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000 Requer Script MultiTrainer|r");
			break;
		case TREINADOR_ORIGINAL_SPELLSUMMON:
			SumonarTrainerOriginais(player, _creature, action);
			player->CLOSE_GOSSIP_MENU();
			break;
		case GLYPH_NPC_VENDOR:
		//	VendedorGlyphs(player,_creature, action);
			ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000 Requer Script MultiVendor|r");
			player->CLOSE_GOSSIP_MENU();
			break;
		case RESETAR__TALENTOS:
			if (player->GetFreeTalentPoints() == +player->CalculateTalentsPoints()){
				ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000Seus talentos ja estam resetados!|r");
				player->CLOSE_GOSSIP_MENU();
			}
			else
			{												
				// ResetPetTalents();
				if (player->getClass() == CLASS_DEATH_KNIGHT)
				{						// == 80
					if (player->getLevel() == sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)){
						player->ResetTalents();
						player->SetFreeTalentPoints(71);
						player->SendTalentsInfoData(false);
						player->CLOSE_GOSSIP_MENU();
					}
					else{
						player->ResetTalents();
						player->SetFreeTalentPoints(player->CalculateTalentsPoints());
						ChatHandler(player->GetSession()).PSendSysMessage("|cff00FF00Talentos resetados com sucesso!|r");
						player->SendTalentsInfoData(false);
						_creature->CastSpell(player, 17251, false);
					}
				}
				else{
					player->ResetTalents();
					player->SetFreeTalentPoints(player->CalculateTalentsPoints());
					ChatHandler(player->GetSession()).PSendSysMessage("|cff00FF00Talentos resetados com sucesso!|r");
					player->SendTalentsInfoData(false);
					_creature->CastSpell(player, 17251, false);
				}
				player->SaveToDB();
				player->CLOSE_GOSSIP_MENU();
			}
			break;
		case DUAL_ESPECIALIZACAO:
			if (player->GetSpecsCount() == 1)
			{
				if (player->getLevel() >= sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))
				{
					if (player->GetMoney() >= 3 * GOLD){ // 30.000 = 3k
						player->CastSpell(player, 63680, false, NULL, NULL, player->GetGUID()); //63651 para tirar
						player->CastSpell(player, 63624, true, NULL, NULL, player->GetGUID());
						player->CLOSE_GOSSIP_MENU();
						ChatHandler(player->GetSession()).PSendSysMessage("|cffFFFFFFEspecializacao Talentos Duplos adiquirida com sucesso!|r");
						player->SaveToDB();
					}
					else
					{
						ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000Voce presisa de|r %u |cffFF0000de GOLD  para comprar Especializacao Talentos Duplos|r", 3 * GOLD);
						player->CLOSE_GOSSIP_MENU();
					}
				}
				else
				{
					ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000Voce so pode pegar Especializacao Talentos Duplos apartido level|r %u", sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL));
					player->CLOSE_GOSSIP_MENU();
				}
			}
			else
			{
				ChatHandler(player->GetSession()).PSendSysMessage("|cffFF0000Voce ja tem Especializacao Talentos Duplos|r");
				player->CLOSE_GOSSIP_MENU();
			}
			break;		
		case SAIR:
			player->CLOSE_GOSSIP_MENU();
			break;
			return true;
		}
	

		return true;
	}


};
void UpdateCreatureTrainerSummon(){
	uint32 UpdateCreature[][2] =
	{
		{ 4475, 26324 }, // druid
		{ 4474, 26325 }, // hunter
		{ 4484, 26326 }, //mage
		{ 4469, 26327 }, // paladin
		{ 4467, 26328 }, //priest
		{ 5061, 26329 }, // rogue
		{ 8110, 26330 }, //shaman
		{ 4504, 26331 }, //warlock
		{ 4475, 26332 }, // warrior
		{ 9693, 28474 }, // Dk
	};
	for (uint8 i = 0; i < 10; i++)
	{
		WorldDatabase.PExecute("UPDATE `creature_template` SET `modelid1` = '18998', `gossip_menu_id` = '%u', `scale` = '0.1' WHERE `entry` = '%u'", UpdateCreature[i][0], UpdateCreature[i][1]);
	} // TC_LOG_INFO("server.loading", "Atualizando creature trainer...");
}
class npc_treinador_supremo_WorldScript : public WorldScript
{
public:
	npc_treinador_supremo_WorldScript() : WorldScript("npc_treinador_supremo_WorldScript") { }
	
	void LoadDataFromDataBase()
	{
		UpdateCreatureTrainerSummon();
	}

	void OnConfigLoad(bool)
	{
		LoadDataFromDataBase();
	}
};

void AddSC_npc_treinador_supremo()
{
	new npc_treinador_supremo();
	new npc_treinador_supremo_WorldScript();	
}