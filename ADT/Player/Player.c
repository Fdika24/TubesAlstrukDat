#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Configuration/Configuration.h"

void setPlayer(player *thePlayer) {
    thePlayer->position = 0;
    scanf("%s", thePlayer->name);
}

void playerRoleDice(player* thePlayer,int maxDice) {
    int move = 0;
    move = rand() % maxDice+1;
    if (isPlayerCanMove(move,thePlayer->position,true)) {
        printf("Player can move forward %d step\n",move);
    }
    if (isPlayerCanMove(move,thePlayer->position,false)) {
        printf("Player can move backward %d step\n",move);
    }
    thePlayer->position += move;
}

void ifCanTeleport(player *thePlayer) {
    for (int i = 0; i < teleportLenght;i++){
        if (thePlayer->position == teleporters[i].startPoint) {
            playerTeleport(thePlayer,teleporters[i].endPoint);
            printf("Teleporting player from : %d to : %d \n",teleporters[i].startPoint,teleporters[i].endPoint);
        }
    }
}

void playerTeleport(player *thePlayer,int endPoint) {
    thePlayer->position = endPoint;
}

int playerOption() {
    int selection = -9;
    scanf("%d",&selection);
    return selection;
}

boolean isPlayerCanMove(int change,int position, boolean isUpward) {
    if (isUpward) {
        return map[position+change] != '#' && (position+change < mapLenght);
    }
        return map[position - change] != '#'&& (position - change > 0);
}

