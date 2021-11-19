#include "Game.h"
#include "../../ADT/Configuration/Configuration.h"
#include "../../ADT/Player/Player.h"
#include <stdio.h>

int playersPlaying = 0;
int isEndGame = 0;
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
            //MARK: BIKIN ERROR AJA ANJING
            setPlayer(&temp);
            printf("\n");
            players[i] = temp;
            printf("Player position %d",players[i].position);
            //temp = NULL;
        }
    }
}

void LoadGame() {

}

void StartGame() {
    int exitGame = 0;
    //Loop per ronde
    for (int i = 0; i < playersPlaying; i++) {

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