#include "Player.h"
#include <stdio.h>

void setPlayer(player *thePlayer) {
    thePlayer->position = 0;
    STARTKATA(2);
    while (!EndKata){
        thePlayer->name = CKata;
        ADVKATA();
    }
    printf("Player name : ");
    printKata(thePlayer->name);
}