#include "Game.h"
#include "../../ADT/Configuration/Configuration.h"
#include "../../ADT/Player/Player.h"
#include <stdio.h>
#include <string.h>

int playersPlaying = 0;
boolean isEndGame = false;
player players[4];

void GameView(int opsi) {
    setConfigFile();
    loadConfig();
    if (opsi == 1) { //New Game
        NewGame();
    } else { //Load Game
        LoadGame();
    }
    printf("\n Let's Start The Game!\n");
    StartGame();
    ExitGame();
}

void NewGame() {
    printf("Starting game...\n");
    printf("Hello new players!, welcome to Uler tenggi \n");
    printf("How many are playing today (minimum 2, max 4) ? : ");
    scanf("%d", &playersPlaying);
    //Setup how many players are playing
    if (playersPlaying < 1 || playersPlaying > 4) {
        NewGame();
    } else {
        for (int i = 0; i < playersPlaying; i++) {
            player temp;
            printf("Player %d name :",i+1);
            setPlayer(&temp);
            printf("\n");
            players[i] = temp;
        }
    }
}

void LoadGame() {

}

// The Game
void StartGame() {
    int exitGame = 0;
    //Loop per ronde
    while (!isEndGame) {
        for (int i = 0; i < playersPlaying; i++) {

        }
    }
}

void ExitGame() {
    freeTeleporters();
    if (isEndGame == 1) {
        //sort user based on position
    } else {
        // Save progress
    }
}