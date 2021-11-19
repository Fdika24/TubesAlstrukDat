//
//  Player.h
//  AlstrukDat
//
//  Created by Farhandika Zahrir Mufti guenia on 31/08/21.
//

#ifndef Player_h
#define Player_h

#include "../boolean.h"
#include "../Skill/Skill.h"
#include "../MesinKarKat/mesin_kata.h"

//Initial position is always 0

typedef struct {
    int position;
    Kata name;
    //skills
} player;


// set player properties
void setPlayer(player *thePlayer);



#endif /* Player_h */