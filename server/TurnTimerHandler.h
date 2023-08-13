/*
 * TurnTimerHandler.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */

#pragma once

VCMI_LIB_NAMESPACE_BEGIN

class PlayerColor;
struct PlayerState;

VCMI_LIB_NAMESPACE_END

class CGameHandler;

class TurnTimerHandler
{
	CGameHandler & gameHandler;
	const int turnTimePropagateFrequency = 5000;
	
public:
	TurnTimerHandler(CGameHandler &);
	
	void onGameplayStart(PlayerState & state);
	void onPlayerGetTurn(PlayerState & state);
	void onPlayerMakingTurn(PlayerState & state, int waitTime);
};
