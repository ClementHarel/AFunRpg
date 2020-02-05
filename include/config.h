/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Contains all #define
*/

//	WINDOW SIZE //

#define WINDOW_X 1280
#define WINDOW_Y 769

//	KEY VALUE //

#define ENTER 58
#define LEFT 71
#define RIGHT 72
#define DOWN 73
#define UP 74

//	ENGINE //

#define MAP_X 40
#define MAP_Y 24
#define SQUARE_SIZE 32
#define NPC_HEIGHT 48
#define GAME_SPEED  120000 // default 120000
#define	PLAYER_SPEED GAME_SPEED / 3

//	TEXT

#define TEXT_SIZE 20
#define FONT "ressources/font/arial.ttf"

// TELEPORT

#define TP_MAP0 8999
#define TP_MAP1 50

// NPC POSITION

#define NPC_NUMBER 20
#define NPC0_X 20
#define NPC0_Y 11
#define NPC0diag NPC0_X + (NPC0_Y * MAP_X)
#define NPC1_X 19
#define NPC1_Y 15
#define NPC1diag NPC1_X + (NPC1_Y * MAP_X)
#define NPC2_X 33
#define NPC2_Y 7
#define NPC2diag NPC2_X + (NPC2_Y * MAP_X)
#define NPC3_X 8
#define NPC3_Y 20
#define NPC3diag NPC3_X + (NPC3_Y * MAP_X)
#define NPC4_X 11
#define NPC4_Y 13
#define NPC4diag NPC4_X + (NPC4_Y * MAP_X)
#define NPC5_X 12
#define NPC5_Y 13
#define NPC5diag NPC5_X + (NPC5_Y * MAP_X)
#define NPC6_X 17
#define NPC6_Y 11
//#define NPC6diag NPC6a_X + (NPC6a_Y * MAP_X) // Melgor
#define NPC6a_X 11
#define NPC6a_Y 8
#define NPC6diag NPC6a_X + (NPC6a_Y * MAP_X)
#define NPC7_X 10
#define NPC7_Y 8
#define NPC7diag NPC7_X + (NPC7_Y * MAP_X)
#define NPC8_X 35
#define NPC8_Y 3
#define NPC8diag NPC8_X + (NPC8_Y * MAP_X)
#define NPC9_X 10
#define NPC9_Y 10
#define NPC9diag NPC9_X + (NPC9_Y * MAP_X)
#define NPC10_X 20
#define NPC10_Y 10
#define NPC10diag NPC10_X + (NPC10_Y * MAP_X)
#define NPC11_X 20
#define NPC11_Y 11
#define NPC11diag NPC11_X + (NPC11_Y * MAP_X)
#define NPC12_X 34
#define NPC12_Y 9
#define NPC12diag NPC12_X + (NPC12_Y * MAP_X)


//LVL 10 * (player->lvl * 2) + player->lvl + 2;
