// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomWidget.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SCustomWidget::Construct(const FArguments& InArgs)
{
	float FValue = InArgs._FloatValue;
	int32 IValue = InArgs._IntValue;
	/*
	ChildSlot
	[
		// Populate the widget
	];
	*/
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
