#ifndef BATTLE_LOGIC_H
#define BATTLE_LOGIC_H

#include <stdlib.h>
#include <stdio.h>
#include "battle/battle_structs.h"
#include "battle/battle_state.h"

/*
 * Checks the targets of a move to see if they exist and are targetable
 *
 * Parameters:
 * - b: information about the battle
 * - target: name of the person
 * Returns:
 * - 0 for if targetable and 1 for not being targetable/not found
 */
int check_target(battle_t *b, char *target);

/*
 * Determines if a battle has reached its conclusion
 *
 * Parameters:
 * - p: information about the player
 * - e: information about the enemy
 * Returns:
 * - 0 for game still in play
 * - 1 for game over due to enemy
 * - 2 for game over due to player
 * - -1 for an error with not passing conditions
 */
int battle_over(combatant_t *p, combatant_t *e);

/* Function detemines what player goes first
 *
 *  Inputs: 
 *      difficulty: difficulty level of the game
 *  Outputs:
 *      -1 - invalid input
 *      0 - user goes first
 *      1 - enemy goes first    */
int goes_first(double p_speed, double e_speed);

/* Uses the item with the given ID on the player
 *
 *  Inputs: 
 *      p - the player using the item
 *      ID - the ID of the item
 *  Outputs:
 *      returns item used    */
item_t *player_use_item(combatant_t *p, int ID);

/* Awards xp to the player 
 * Parameters:
 *  - stats: stats of the player
 *  - xp: amount of xp to be rewarded
 * Returns:
 *  0 for success
 */
int award_xp(stat_t *stats, double xp);

#endif