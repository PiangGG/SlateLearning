// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCompoundWidget.h"

/**
 * 
 */
class SLATELEARNING_API SCustomWidget : public SCompoundWidget
{
public:
	//我们可以在SLATE_BEGIN_ARGS这个宏中用一些构造函数风格的方法来为这些变量赋于初值
	SLATE_BEGIN_ARGS(SCustomWidget)	:_FloatValue(4.0f), _IntValue(2)
	{
		
	}
	//参数传递
	SLATE_ARGUMENT(float, FloatValue)
	SLATE_ARGUMENT(int32, IntValue)
	SLATE_END_ARGS()

	float FloatValue;
	int32 IntValue;
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
