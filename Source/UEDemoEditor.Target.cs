// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UEDemoEditorTarget : TargetRules
{
	public UEDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		bLegacyParentIncludePaths = false;
		CppStandard = CppStandardVersion.Default;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		WindowsPlatform.bStrictConformanceMode = true;
		bValidateFormatStrings = true;
		ExtraModuleNames.Add("UEDemo");
	}
}
