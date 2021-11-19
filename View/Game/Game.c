#include "Game.h"
#include "../../ADT/Configuration/Configuration.h"
int playersPlaying = 0;
int isEndGame = 0;

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