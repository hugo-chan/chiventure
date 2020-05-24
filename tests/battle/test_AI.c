#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../src/battle/src/AI.c"
#include "../../include/battle/AI.h"

move_t *create_move(int ID, item_t* item, bool attack, int damage, int defense)
 {
     move_t* move = (move_t*) calloc(1, sizeof(move_t));

     move->ID = ID;

     move->item = item;

     move->attack = attack;
     move->damage = damage;
     move->defense = defense;

     return move;
 }

 item_t *create_item(int id, int quantity, int durability, char* description,
            bool battle, int attack, int defense, int hp)
 {
     item_t* item = (item_t*) calloc(1, sizeof(item_t));

     item->id = id;
     item->quantity = quantity;
     item->durability = durability;
     item->description = description;
     item->battle = battle;
     item->attack = attack;
     item->hp = hp;
     item->defense = defense;

     return item;
 }

stat_t* create_enemy_stats()
{
    stat_t* test_stats = malloc(sizeof(stat_t));

    test_stats->speed = 50;
    test_stats->defense = 20;
    test_stats->strength = 150;
    test_stats->dexterity = 10;
    test_stats->hp = 200;
    test_stats->max_hp = 200;
    test_stats->xp = 0;
    test_stats->level = 5; 

    return test_stats;
}

stat_t* create_player_stats()
{
    stat_t* test_stats = malloc(sizeof(stat_t));

    test_stats->speed = 50;
    test_stats->defense = 30;
    test_stats->strength = 200;
    test_stats->dexterity = 10;
    test_stats->hp = 150;
    test_stats->max_hp = 150;
    test_stats->xp = 0;
    test_stats->level = 1;

    return test_stats;
}

item_t* create_player_items()
{
    item_t *head, *dagger, *tea_leaves, *medicine;
    head = NULL;
    dagger = create_item(1, 1, 20, "A hearty dagger sure to take your breath away... for good",
	true, 20, 5, 0);
	tea_leaves = create_item(2, 1, 1, "Make yourself a warm cup of tea to heal your wounds!", true,
	0, 0, 10);
	medicine = create_item(3, 1, 1, "A first aid kit, straight from your doctor!", true, 0, 0, 30);
	DL_APPEND(head, dagger);
    DL_APPEND(head, tea_leaves);
    DL_APPEND(head, medicine);
    return head;
}

item_t* create_enemy_items()
{
    item_t *head, *mace, *diamond_sword, *force_shield;
    head = NULL;
    mace = create_item(4, 1, 20, "Temporary blindness leaves you quite vulnerable...", true, 
        0, -30, 0);
	diamond_sword = create_item(5, 1, 50, "Brings quick death to those who dare battle you...", 
        true, 20, 0, 0);
	force_shield = create_item(6, 1, 30, "Rest comfortably as this shield protects you for 1 move", 
        true, 0, 30, 5);
    DL_APPEND(head, mace);
    DL_APPEND(head, diamond_sword);
    DL_APPEND(head, force_shield);
    return head;
}

move_t* create_enemy_moves()
{
    move_t *head, *earthquake, *poke, *rock_throw;
    head = NULL;
    earthquake = create_move(1, NULL, true, 100, 20);
	poke = create_move(2, NULL, true, 1, 1);
	rock_throw = create_move(3, NULL, true, 300, 20);
    DL_APPEND(head, earthquake);
    DL_APPEND(head, poke);
    DL_APPEND(head, rock_throw);
    return head;
}

move_t* create_player_moves()
{
    move_t *head, *fire_blast, *punch, *burn;
    head = NULL;
    fire_blast = create_move(4, NULL, true, 100, 50);
	punch = create_move(5, NULL, true, 20, 20);
	burn = create_move(6, NULL, true, 1, 2);
    DL_APPEND(head, fire_blast);
    DL_APPEND(head, punch);
    DL_APPEND(head, burn);
    return head;
}

//creates the example moves
move_t* expected_move_hard()
{
    move_t* rock_throw = create_move(3, NULL, true, 300, 50);
    return rock_throw;
}

move_t* expected_move_easy()
{
    move_t* poke = create_move(2, NULL, true, 1, 1);
    return poke;
}

move_t* expected_move_random()
{
    move_t* rock_throw = create_move(3, NULL, true, 300, 50);
    return rock_throw;
}

combatant_t* new_enemy()
{
    char* name = "Skeleton";
    bool is_friendly = false;
    class_t class = bard;
    stat_t *stats = create_enemy_stats();
    move_t *moves = create_enemy_moves();
    item_t *items = create_enemy_items();
    struct combatant *next = NULL;
    struct combatant *prev = NULL;
    return combatant_new(name, is_friendly, stats, moves, items);

}

combatant_t* new_player()
{
    char* name = "Steve";
    bool is_friendly = true;
    class_t class = bard;
    stat_t *stats = create_player_stats();
    move_t *moves = create_player_moves();
    item_t *items = create_player_items();
    struct combatant *next = NULL;
    struct combatant *prev = NULL;
    return combatant_new(name, is_friendly, stats, moves, items);
}

void check_give_move(int difficulty, combatant_t* player, combatant_t* enemy, move_t* expected)
{
    move_t *actual_move, *expected_move;
    actual_move = give_move(difficulty, player, enemy);

    cr_assert_eq(actual_move->ID, expected->ID, "give_move did not return expected move!");
}

Test(AI, give_move_easy)
{
    check_give_move(1, 
            new_player(),
            new_enemy(),
            expected_move_easy());
}

Test(AI, give_move_medium)
{
    check_give_move(2,   
            new_player(),
            new_enemy(),
            expected_move_random());
}

Test(AI, give_move_hard)
{
    check_give_move(3,   
            new_player(),
            new_enemy(),
            expected_move_hard());
}

Test(AI, easy_move)
{
    combatant_t *player, *enemy;
    move_t *expected_move, *actual_move;

    player = new_player();
    enemy = new_enemy();

    expected_move = expected_move_easy();
    actual_move = easy_move(player, enemy);

    cr_assert_not_null(player, "combatant_new() failed");
    cr_assert_not_null(enemy, "combatant_new() failed");

    cr_assert_eq(actual_move->ID, expected_move->ID, "easy_move did not return easiest move!");
}

Test(AI, medium_move)
{
    combatant_t *player, *enemy;
    move_t *expected_move, *actual_move;

    player = new_player();
    enemy = new_enemy();

    expected_move = expected_move_random();
    actual_move = medium_move(player, enemy);

    cr_assert_not_null(player, "combatant_new() failed");
    cr_assert_not_null(enemy, "combatant_new() failed");

    cr_assert_eq(actual_move->ID, expected_move->ID, "medium_move did not return random move!");
}

Test(AI, hard_move)
{
    combatant_t *player, *enemy;
    move_t *expected_move, *actual_move;

    player = new_player();
    enemy = new_enemy();

    expected_move = expected_move_hard();
    actual_move = hard_move(player, enemy);

    cr_assert_not_null(player, "combatant_new() failed");
    cr_assert_not_null(enemy, "combatant_new() failed");

    cr_assert_eq(actual_move->ID, expected_move->ID, "hard_move did not return hardest move!");
}

Test(AI, find_easy)
{
    combatant_t *player, *enemy;
    move_t *expected_move, *actual_move;

    player = new_player();
    enemy = new_enemy();

    expected_move = expected_move_easy();
    actual_move = find_easy(player, enemy);

    cr_assert_not_null(player, "combatant_new() failed");
    cr_assert_not_null(enemy, "combatant_new() failed");


    cr_assert_eq(actual_move->ID, expected_move->ID, "find_easy did not find the easiest move! actual = %d|expected = %d", actual_move->ID, expected_move->ID);
}

Test(AI, find_hard)
{
    combatant_t *player, *enemy;
    move_t *expected_move, *actual_move;

    player = new_player();
    enemy = new_enemy();

    expected_move = expected_move_hard();
    actual_move = find_hard(player, enemy);

    cr_assert_not_null(player, "combatant_new() failed");
    cr_assert_not_null(enemy, "combatant_new() failed");

    cr_assert_eq(actual_move->ID, expected_move->ID, "find_hard did not find the hardest move!");
}


Test(AI, damage)
{
    combatant_t *player, *enemy;
    move_t* move;

    player = new_player();
    enemy = new_enemy();
    move = expected_move_hard();

    double expected = 64.0;
    double actual = damage(player, move, enemy);

    cr_assert_not_null(player, "combatant_new() failed");
    cr_assert_not_null(enemy, "combatant_new() failed");

    cr_assert_float_eq(actual, expected, 1E-6);
}