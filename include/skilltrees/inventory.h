/*
 * Skill inventory implementation for chiventure
 */

#ifndef INCLUDE_INVENTORY_H_
#define INCLUDE_INVENTORY_H_

#include "skilltrees/stdst.h"
#include "skilltrees/skill.h"

/* ================================= */
/* === INVENTORY DATA STRUCTURES === */
/* ================================= */
/* ALL the skills belonging to a player */
typedef struct skill_inventory {
    // An array of active skills belonging to a player
    skill_t** active;

    // The number of active skills belonging to a player
    unsigned int num_active;

    // The maximum number of active skills a player can possess
    // (This field helps to enforce skill tree balancing)
    unsigned int max_active;

    // An array of passive skills belonging to a player
    skill_t** passive;

    // The number of passive skills belonging to a player
    unsigned int num_passive;

    // The maximum number of passive skills a player can possess
    // (This field helps to enforce skill tree balancing)
    unsigned int max_passive;

} skill_inventory_t;

/*
 * Allocates a new (empty) skill inventory in the heap.
 *
 * Parameters:
 *  - max_active: The maximum number of active skills a player can possess
 *  - max_passive: The maximum number of passive skills a player can possess
 *
 * Returns:
 *  - A pointer to the skill inventory, or NULL if the skill inventory cannot be
 *    allocated
 */
skill_inventory_t* inventory_new(unsigned int max_active,
                                 unsigned int max_passive);

/*
 * Frees the resources associated with a skill inventory.
 *
 * Parameters:
 *  - inventory: A skill inventory. Must point to skill inventory allocated with
 *               inventory_new
 *
 * Returns:
 *  - Always returns 0
 */
int inventory_free(skill_inventory_t* inventory);

/*
 * Adds a skill to a player's skill inventory.
 *
 * Parameters:
 *  - inventory: A skill inventory
 *  - skill: A skill
 *
 * Returns:
 *  - 0 on success, 1 if an error occurs
 */
int inventory_skill_add(skill_inventory_t* inventory, skill_t* skill);

/*
 * Searches for a skill in a player's skill inventory.
 *
 * Parameters:
 *  - inventory: A skill inventory
 *  - sid: A skill ID
 *  - type: The skill type
 *
 * Returns:
 *  - The position of the skill in the inventory, -1 if the skill is not in the
 *    inventory
 */
int inventory_has_skill(skill_inventory_t* inventory, sid_t sid,
                        skill_type_t type);

/*
 * Removes a skill from a player's skill inventory.
 *
 * Parameters:
 *  - inventory: A skill inventory
 *  - skill: A skill
 *
 * Returns:
 *  - 0 on success, 1 if an error occurs
 */
int inventory_skill_remove(skill_inventory_t* inventory, skill_t* skill);

/*
 * Returns all names of skills currently in the inventory as a string.
 *
 * Parameters:
 *  - inventory: A skill inventory
 *
 * Returns:
 *  - A string formatted nicely to print out in the chiventure screen.
char* current_skills_as_strings(skill_inventory_t* inventory);

#endif /* INCLUDE_INVENTORY_H_ */
