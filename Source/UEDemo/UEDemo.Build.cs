// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEDemo : ModuleRules
{
	public UEDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","GameplayAbilities","GameplayTags","GameplayTasks" });
	}
}
