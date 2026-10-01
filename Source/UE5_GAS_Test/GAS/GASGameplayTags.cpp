#include "GAS/GASGameplayTags.h"

namespace GASTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_Fireball, "Ability.Fireball", "Fireball ability");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Cooldown_Fireball, "Cooldown.Fireball", "Fireball cooldown");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Burn, "State.Burn", "Target is burning");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayCue_Burn, "GameplayCue.Burn", "Burn VFX cue");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Data_Damage, "Data.Damage", "SetByCaller damage magnitude");
}