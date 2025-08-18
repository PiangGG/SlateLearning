// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateLearning.h"

#include "RequiredProgramMainCPPInclude.h"
#include "SlateApplication.h"
#include "StandaloneRenderer.h"

DEFINE_LOG_CATEGORY_STATIC(LogSlateLearning, Log, All);

IMPLEMENT_APPLICATION(SlateLearning, "SlateLearning");

// int WINAPI WinMain( _In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow )
// {
// 	GEngineLoop.PreInit(GetCommandLineW());
// 	
// 	UE_LOG(LogSlateLearning, Display, TEXT("SlateLearning:Start"));
// 	
// 	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
//
// 	FSlateApplication::InitHighDPI(true);
// 	
// 	TSharedRef<SWindow> Window = SNew(SWindow)
// 	.ClientSize(FVector2D(200.f, 200.f))
// 	[
// 		SNullWidget::NullWidget
// 	];
// 	
// 	FSlateApplication::Get().AddWindow(Window);
// 	
// 	while (!IsEngineExitRequested())
// 	{
// 		BeginExitIfRequested();
// 		
// 		FSlateApplication::Get().PumpMessages();
// 		FSlateApplication::Get().Tick();
// 	}
// 	
// 	FSlateApplication::Shutdown();
//
// 	GEngineLoop.AppPreExit();
// 	GEngineLoop.AppExit();
//
// 	return 0;
// }

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	GEngineLoop.PreInit(ArgC, ArgV);

	UE_LOG(LogSlateLearning, Display, TEXT("SlateLearning:Start"));

	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
	
	FSlateApplication::InitHighDPI(true);

	const TSharedPtr<SWindow> MainWindow = SNew(SWindow).ClientSize(FVector2D(800, 600));

	FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());

	while (!IsEngineExitRequested())
	{
		BeginExitIfRequested();
		FSlateApplication::Get().PumpMessages();
		FSlateApplication::Get().Tick();
	}

	UE_LOG(LogSlateLearning, Display, TEXT("SlateLearning:End"));
	
	FSlateApplication::Shutdown();
	
	GEngineLoop.AppPreExit();
	
	GEngineLoop.AppExit();
	return 0;
}
