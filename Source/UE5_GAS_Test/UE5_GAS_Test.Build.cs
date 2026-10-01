// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_GAS_Test : ModuleRules
{
	public UE5_GAS_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks",
            "Slate",
            "SlateCore"
        });

		PublicIncludePaths.AddRange(new string[] {
			"UE5_GAS_Test",
			"UE5_GAS_Test/Variant_Platforming",
			"UE5_GAS_Test/Variant_Platforming/Animation",
			"UE5_GAS_Test/Variant_Combat",
			"UE5_GAS_Test/Variant_Combat/AI",
			"UE5_GAS_Test/Variant_Combat/Animation",
			"UE5_GAS_Test/Variant_Combat/Gameplay",
			"UE5_GAS_Test/Variant_Combat/Interfaces",
			"UE5_GAS_Test/Variant_Combat/UI",
			"UE5_GAS_Test/Variant_SideScrolling",
			"UE5_GAS_Test/Variant_SideScrolling/AI",
			"UE5_GAS_Test/Variant_SideScrolling/Gameplay",
			"UE5_GAS_Test/Variant_SideScrolling/Interfaces",
			"UE5_GAS_Test/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
