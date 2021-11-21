//
//  GAME.h
//  AlstrukDat
//
//  Created by Farhandika Zahrir Mufti guenia on 31/08/21.
//

#ifndef GAME_h
#define GAME_h
#include "../../ADT/boolean.h"
#include "../../ADT/Player/Player.h"

// how many players are playing
extern int playersPlaying;

// if someone win then isEndGame
extern boolean isEndGame;

void GameView(int opsi);

void NewGame();

void LoadGame();

void StartGame();

void ExitGame();

void displayMap();
// sort player based on their position
void rankPlayers(player *players[4]);
// display player rank
void displayRank();
// display game rule
void displayGameRule();

// show the position of the player
void showPlayerPosition(int position);

// show player command

void showPlayerCommand();

//check if it's the end of the game
boolean checkIsEndGame(int position);


#endif /* GAME_h */ 
