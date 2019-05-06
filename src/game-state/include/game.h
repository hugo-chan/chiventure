#include <stdio.h>
#include <stdlib.h>
// #include "small_modules.h" (ONCE ACTIVE)

#ifndef GAME_H
#define GAME_H

/* The game struct is built to contain all the relevant information
for anyone who needs to work the game

*/
typedef struct room {
  // room;
} room_t;

//list of rooms prototype
typedef struct rlist {
    room_t *curr;
    rlist_t *rest;
} rlist_t;

typedef struct player {
    //holds levels
    //health
    //inventory
    //experience
    //objectives : 1 or 0 if complete
} player_t;

//adja
struct G_Rooms {
    room_t *curr;
    //list of all rooms
    rlist_t *list;
};

typedef struct game {
    // list of players, the expected value is 1 but this can change
    player_t *players;

    //rooms: rooms should be a graph struct w/ directed edges
    //assuming rooms form a network/graphs we can just store the current room
    //store graph of rooms
    
    //pointer to all rooms struct (current room + list of all rooms)
    struct G_Rooms *Rooms;

    //TIME STARTED
    int time_start;
} game_t;

//loads game. If given file is empty start new game, else load
game_t *init_game(FILE *f);

//saves game, bool if success 
//(SHOULD be able to select new save location - depends on CLI)
int save_game(game_t *game, FILE *f);

//given a new room, changes the current room in game-state
//this should only check if the room is in the list of adjacent rooms
//expecting a legal move
void move_room(game_t *game, room_t *new_room);

//exit game
//echo "ctrl-g"
//troll post pls dont hate
void exit_game(game_t *game);

//free game
//assuming fxnalities being x-built
void free_game(game_t *game);





#endif

