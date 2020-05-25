/*
 * Skill inventory implementation for chiventure
 */

#ifndef INCLUDE_INVENTORY_H_
#define INCLUDE_INVENTORY_H_

#include "skilltrees/stdst.h"

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
inventory_t* inventory_new(unsigned int max_active, unsigned int max_passive);

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
int inventory_free(inventory_t* inventory);

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
int inventory_skill_add(inventory_t* inventory, skill_t* skill);

/*
 * Searches for a skill in a player's skill inventory.
 *
 * Parameters:
 *  - inventory: A skill inventory
 *  - skill: A skill
 *
 * Returns:
 *  - The position of the skill in the inventory, -1 if the skill is not in the
 *    inventory
 */
int inventory_has_skill(inventory_t* inventory, sid_t sid, skill_type_t type);

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
int inventory_skill_remove(inventory_t* inventory, skill_t* skill);

#endif /* INCLUDE_INVENTORY_H_ */
