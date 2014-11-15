#include "ScriptPCH.h"

/* This is where custom scripts' loading functions should be declared. */
void AddSC_TW_instance_trial_of_the_champion();
void AddSC_TW_boss_grand_champions();
void AddSC_TW_boss_black_knight();
void AddSC_TW_boss_argent_challenge();
void AddSC_TW_trial_of_the_champion();

/* This is where custom scripts should be added. */
void AddSC_custom()
{
    AddSC_TW_instance_trial_of_the_champion();
    AddSC_TW_boss_argent_challenge();
    AddSC_TW_boss_black_knight();
    AddSC_TW_boss_grand_champions();
    AddSC_TW_trial_of_the_champion();
}
