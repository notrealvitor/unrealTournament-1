// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "PartyGameState.h"
#include "UTPartyGameState.generated.h"

enum class EMatchmakingCompleteResult : uint8;

UENUM(BlueprintType)
enum class EUTPartyState : uint8
{
	/** In the menus */
	Menus = 0,
	/** Actively matchmaking, no destination yet */
	Matchmaking,
	/** Destination found and beyond (attempting to join, lobby, game, etc) */
	PostMatchmaking
};

/**
 * Party game state that contains all information relevant to the communication within a party
 * Keeps all players in sync with the state of the party and its individual members
 */
UCLASS(config=Game, notplaceable)
class UNREALTOURNAMENT_API UUTPartyGameState : public UPartyGameState
{
	GENERATED_UCLASS_BODY()
	
	/**
	 * Delegate fired when a party state changes
	 * 
	 * @param NewPartyState current state object containing the changes
	 */
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnClientPartyStateChanged, EUTPartyState /* NewPartyState */);

	/**
	 * Delegate fired when a matchmaking state changes
	 * 
	 * @param Result result of the last matchmaking attempt by the leader
	 */
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnClientMatchmakingComplete, EMatchmakingCompleteResult /* Result */);

private:
	/** Passenger view related delegates prior to joining a lobby/game */
	FOnClientPartyStateChanged ClientPartyStateChanged;
	FOnClientMatchmakingComplete ClientMatchmakingComplete;

public:
	FOnClientPartyStateChanged& OnClientPartyStateChanged() { return ClientPartyStateChanged; }
	FOnClientMatchmakingComplete& OnClientMatchmakingComplete() { return ClientMatchmakingComplete; }
};