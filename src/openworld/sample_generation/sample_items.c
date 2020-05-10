/* Implementations of the item struct */
#include <string.h>

#include "../../../include/openworld/sample_rooms.h" 
#include "../../../include/openworld/sample_items.h"


// BASIC ITEM FUNCTIONS -------------------------------------------------------
/* see sample_items.h*/
int item_init(item_t *new_item, char *item_key)
{
	assert(new_item != NULL);
	switch (item_key) {
	case "APPLE":
		new_item->item_tag = APPLE;
		apple_t a;
		new_item->item_type = a;
		break;
	case "BOOK":
		new_item->item_tag = BOOK;
		book_t b;
		new_item->item_type = b;
		break;
	case "COW":
		new_item->item_tag = COW;
		cow_t c;
		new_item->item_type = c;
		break;
	case "DOOR":
		new_item->item_tag = DOOR;
		door_t d;
		new_item->item_type = d;
		break;
	case "WINDOW":
		new_item->item_tag = WINDOW;
		window_t w;
		new_item->item_type = w;
		break;
	}
	return SUCCESS;
}

/* see item.h */
item_t *item_new(char *item_id)
{
	item_t *new_item = (item_t*) malloc(sizeof(item_t));
	memset(new_item, 0, sizeof(item_t));

	int check = item_init(new_item, item_id);

	if (new_item == NULL || new_item->item_id == NULL ||
		new_item.item_type == NULL)
	{

		return NULL; //item struct not properly malloced

	}

	if (check != SUCCESS)
	{
		return NULL;
	}

	return new_item;

}


/* see item.h */
char *get_sdesc_item(item_t *item)
{
	if (item == NULL)
	{
		return NULL;
	}
	return item.item_type->short_desc;
}

/* see item.h */
char *get_ldesc_item(item_t *item)
{
	if (item == NULL)
	{
		return NULL;
	}
	return item.item_type->long_desc;
}


// FREEING AND DELETION FUNCTIONS ---------------------------------------------

/* See sample_items.h */
int item_free(item_t *item)
{
	free(item->item_tag);
	free(item.item_type);
	free(item);
	return SUCCESS;
}

