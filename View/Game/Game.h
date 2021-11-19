//
//  GAME.h
//  AlstrukDat
//
//  Created by Farhandika Zahrir Mufti guenia on 31/08/21.
//

#ifndef GAME_h
#define GAME_h
#include "../ADT/boolean.h"

// how many players are playing
extern int playersPlaying;

// if someone win then isEndGame
extern boolean isEndGame;

void GameView(int opsi);
void NewGame();
void LoadGame();
void StartGame();
void ExitGame();

#endif /* GAME_h */