// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "Slate/SlateGameResources.h"
#include "../SUWPanel.h"
#include "../SUWindowsStyle.h"

#if !UE_SERVER

#include "SWebBrowser.h"

class UNREALTOURNAMENT_API SUTWebBrowserPanel : public SUWPanel
{
	SLATE_BEGIN_ARGS(SUTWebBrowserPanel)
	: _ShowControls(true)
	, _ViewportSize(FVector2D(1920, 1080))
	, _AllowScaling(false)
	{}

	SLATE_ARGUMENT(bool, ShowControls)
	SLATE_ARGUMENT(FVector2D, ViewportSize)
	SLATE_ARGUMENT(bool, AllowScaling)

	/** Called when a custom Javascript message is received from the browser process. */
	SLATE_EVENT(FOnJSQueryReceivedDelegate, OnJSQueryReceived)

	/** Called when a pending Javascript message has been canceled, either explicitly or by navigating away from the page containing the script. */
	SLATE_EVENT(FOnJSQueryCanceledDelegate, OnJSQueryCanceled)

	SLATE_END_ARGS()
	
public:
	void Construct(const FArguments& InArgs, TWeakObjectPtr<UUTLocalPlayer> InPlayerOwner);

	virtual void ConstructPanel(FVector2D ViewportSize);
	virtual void Browse(FString URL);

	virtual void OnShowPanel(TSharedPtr<SUWindowsDesktop> inParentWindow);
	virtual void OnHidePanel();

	virtual void ExecuteJavascript(const FString& JS) { WebBrowserPanel->ExecuteJavascript(JS); }

protected:

	FVector2D DesiredViewportSize;
	bool bAllowScaling;

	TSharedPtr<SVerticalBox> WebBrowserContainer;
	// The Actual Web browser panel.
	TSharedPtr<SWebBrowser> WebBrowserPanel;
	
	/** A delegate that is invoked when render process Javascript code sends a query message to the client. */
	FOnJSQueryReceivedDelegate OnJSQueryReceived;

	/** A delegate that is invoked when render process cancels an ongoing query. Handler must clean up corresponding result delegate. */
	FOnJSQueryCanceledDelegate OnJSQueryCanceled;

	float GetReverseScale() const;
	bool ShowControls;
};

#endif