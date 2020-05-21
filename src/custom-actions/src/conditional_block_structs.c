/* 
 * Conditional block structs to be used in custom-actions implementation
 *
 * Please see "conditional_block_structs.h" for struct documentation
 */

#include <stdlib.h>
#include <stdio.h>
#include "game-state/item.h"
#include "custom-actions/conditional_branch_structs.h"

/* An enumeration type for a conditional block */
typedef enum conditional_type {
    EQ,
    LTGT,
    LTEGTE,
    IN
} conditional_type;

/* A block that returns true or false, and contains an operator and two attributes */
typedef struct conditional_block {
    enum conditional_type conditional_type;
    attribute_t* left;
    attribute_t* right;
} conditional_block_t;

