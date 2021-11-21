#include "Game.h"
#include "../../ADT/Configuration/Configuration.h"
#include "../../ADT/Progress/Progress.h"
#include "../../ADT/MesinKarKat/mesin_kata.h"
#include "../../ADT/Round/Round.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int playersPlaying = 0;
boolean isEndGame = false;
roundData data;


void showPlayerPosition(int position) {
    for (int i = 0; i < mapLenght; i++) {
        if (i == position) {
            printf("%c",'*');
        } else {
            printf("%c",map[i]);
        }
    }
    printf(" %d \n",position+1);
}

void GameView(int opsi) {
    if (opsi == 1) { //New Game
        NewGame();
    } else { //Load Game
        LoadGame();
    }
    setConfigFile();
    loadConfig();

    displayGameRule();
    // click enter to continue type of shit
    printf("\n Let's Start The Game!\n");
    displayMap();
    StartGame();
    if (isEndGame) {
        displayRank();
    }
    ExitGame();
}

void NewGame() {
    printf("Starting game...\n");
    printf("Hello new players!, welcome to Uler tenggi \n");
    printf("How many are playing today (minimum 2, max 4) ? : ");
    scanf("%d", &playersPlaying);
    //Setup how many players are playing
    if (playersPlaying < 2 || playersPlaying > 4) {
        printf("Looks like you put the wrong number, re-starting the game... \n");
        NewGame();
    } else {
        for (int i = 0; i < playersPlaying; i++) {
            player temp;
            printf("Player %d name :",i+1);
            setPlayer(&temp);
            printf("\n");
            data.players[i] = temp;
        }
    }
}

void LoadGame() {
//     progressName();
//     loadProgress();
//     int line = 1;
//     int idx = 0;
//     while (!EndKata) {
//         if (line == 1) {
//             sscanf(fileName, "%s", CKata.TabKata);
//         }
//         else if (line == 2) {
//             playersPlaying = atoi(CKata.TabKata);
//         }
//         else {
// //WIP
//         }
//     }
}

void displayGameRule() {

}
void showPlayerCommand() {
    printf("Your commands : \n");
    printf("[1] role dice\n");
    printf("[2] use skill\n");
    printf("[3] show position\n");
    printf("[4] undo\n");
    printf("[0] exit game\n");
}

// The Game
void StartGame() {
    boolean exitGame = false;
    int round = 1;
    int opsi = -9;
    // stack rondenya
    Ronde rounde;
    //
    CreateRondeEmpty(&rounde);
    data.rondeKeberapa = 1;
    PushRonde(&rounde,data);
    boolean didRoleDice = false;
    //Loop per ronde

    //sistem undo jalan, do not touch
    while (!isEndGame) {
        data = CurrRonde(rounde);
        printf("Round %d\n",round);
        data.rondeKeberapa = round;
        for (int i = 0; i < playersPlaying; i++) {
            //clear screen
            while (!didRoleDice){ 
                printf("It's %s turn! \n",CurrRonde(rounde).players[i].name);
                showPlayerCommand();
                printf("Select your move : ");
                opsi = playerOption();
                if (opsi == 1) {
                    playerRoleDice(&data.players[i],maxDiceRole);
                    ifCanTeleport(&data.players[i]);
                    didRoleDice = true;
                }
                else if (opsi == 2) {
                    printf("use skill \n");
                }
                else if (opsi == 3) {
                    showPlayerPosition(data.players[i].position);
                }
                else if (opsi == 4) {
                    if (data.rondeKeberapa == 1){
                        printf("Undo skill is unavailable \n");
                    } else {
                        PopRonde(&rounde,&data);
                        data = CurrRonde(rounde);
                    }
                }
                else if (opsi == 0) {
                    exitGame = true;
                    break;
                }
            }

            PushRonde(&rounde,data);
            if (exitGame) { break ;}
            didRoleDice = false;
            isEndGame = checkIsEndGame(CurrRonde(rounde).players[i].position);
            if (isEndGame) break;
        }
        if (exitGame) { break ;}
        round++;
    }
    free(rounde.TOP);
}

void ExitGame() {
    freeTeleporters();
    if (isEndGame == 1) {
        //sort user based on position
        printf("Congratulation, you've reach the end game!\n");
    } else {
        // Save progress
        printf("Saving progress.....\n");
    }
}

void displayRank() {
    for (int i = 0; i < playersPlaying; i++) {
       // printf("Rank #%d : %s \n",i+1,players[i].name);
    }
}

void displayMap() {
    printf("Game map :\n");
    printf("%s\n",map);
}

boolean checkIsEndGame(int position) {
    return position >= mapLenght;
}
