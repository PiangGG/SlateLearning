// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateLearning.h"

#include "CustomWidget.h"
#include "RequiredProgramMainCPPInclude.h"
#include "SButton.h"
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

	SOverlay::FOverlaySlot* Slot;
	
	const TSharedPtr<SWindow> MainWindow = SNew(SWindow).ClientSize(FVector2D(800, 600))
	[
		SNew(SOverlay) + SOverlay::Slot().HAlign(HAlign_Left).VAlign(VAlign_Top).Expose(Slot)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(SCustomWidget).FloatValue(9.0f).IntValue(1)
			]
			// + SHorizontalBox::Slot()
			// .AutoWidth()
			// [
			// 	SNew(SButton)
			// 	.Text(NSLOCTEXT("L10N", "Key", "Button Content"))
			// 	.OnClicked(FOnClicked::CreateLambda([]()
			// 	{
			// 		UE_LOG(LogSlateLearning, Display, TEXT("SlateLearning:OnClicked"));
			// 		return FReply::Handled();
			// 	}))
			// ]
		]
		
	];
	
	SWidget& SlotWidget = Slot->GetWidget().Get();
	SHorizontalBox& HorizontalBox = static_cast<SHorizontalBox&>(SlotWidget);

	for (int i = 0; i < 5; ++i)
	{
		HorizontalBox.AddSlot()
		[
			SNew(SButton).Text(FText::Format(NSLOCTEXT("L10N", "Key", "Button{0}"), FText::AsNumber(i)))
			.OnClicked(FOnClicked::CreateLambda([i]()
			{
				UE_LOG(LogSlateLearning, Display, TEXT("SlateLearning:OnClicked{%d}"),i);
				return FReply::Handled();
			}))
		];
	}
	
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
