#include "mesin_kata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while (CC == BLANK){
        ADV();
    }
}

void STARTKATA(){
    START(fileName);
    IgnoreBlank();
    if (CC == MARK){
        EndKata = 1;
    } else {
        EndKata = 0;
        ADVKATA();
    }
}

void ADVKATA(){
    IgnoreBlank();
    if (CC == MARK && !EndKata){
        EndKata = 1;
    } else{
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata(){
    int i = 0;
    while ((CC != MARK) && (CC != BLANK) && i != NMax) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = (i < NMax) ? i : NMax;
}