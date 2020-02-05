/*
** EPITECH PROJECT, 2018
** My rpg
** File description:
** jpp
*/

#include "config.h"
#include "my.h"

void	update_lvl_m(char *lvl_mourad, player_t *player, int lvl_up_m)
{
	lvl_mourad[6] = player->m_lvl / 10 + '0';
	lvl_mourad[7] = player->m_lvl % 10 + '0';
	lvl_mourad[18] = player->m_exp / 100 + '0';
	lvl_mourad[19] = player->m_exp / 10 % 10 + '0';
	lvl_mourad[20] = player->m_exp % 10 + '0';
	lvl_mourad[24] = lvl_up_m / 100 + '0';
	lvl_mourad[25] = lvl_up_m / 10 % 10 + '0';
	lvl_mourad[26] = lvl_up_m % 10 + '0';
}

void	update_lvl(char *lvl_hero, player_t *player, int lvl_up)
{
	lvl_hero[6] = player->lvl / 10 + '0';
	lvl_hero[7] = player->lvl % 10 + '0';
	lvl_hero[18] = player->exp / 100 + '0';
	lvl_hero[19] = player->exp / 10 % 10 + '0';
	lvl_hero[20] = player->exp % 10 + '0';
	lvl_hero[24] = lvl_up / 100 + '0';
	lvl_hero[25] = lvl_up / 10 % 10 + '0';
	lvl_hero[26] = lvl_up % 10 + '0';
}

void	position_junk_quad(sprite_t *sprite)
{
	sfSprite_setPosition(sprite->npc12,
			(sfVector2f) {(NPC12_X) * SQUARE_SIZE, ((NPC12_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque12,
			(sfVector2f) {(NPC12_X) * SQUARE_SIZE, ((NPC12_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc10,
			(sfVector2f) {(NPC10_X) * SQUARE_SIZE, ((NPC10_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque10,
			(sfVector2f) {(NPC10_X) * SQUARE_SIZE, ((NPC10_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc11,
			(sfVector2f) {(NPC11_X) * SQUARE_SIZE, ((NPC11_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque11,
			(sfVector2f) {(NPC11_X) * SQUARE_SIZE, ((NPC11_Y
							* SQUARE_SIZE) - 16)});
}

void	position_junk_tris(sprite_t *sprite)
{
	sfSprite_setPosition(sprite->npc7,
			(sfVector2f) {(NPC7_X) * SQUARE_SIZE, ((NPC7_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque7,
			(sfVector2f) {(NPC7_X) * SQUARE_SIZE, ((NPC7_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc8,
			(sfVector2f) {(NPC8_X) * SQUARE_SIZE, ((NPC8_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque8,
			(sfVector2f) {(NPC8_X) * SQUARE_SIZE, ((NPC8_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc9,
			(sfVector2f) {(NPC9_X) * SQUARE_SIZE, ((NPC9_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque9,
			(sfVector2f) {(NPC9_X) * SQUARE_SIZE, ((NPC9_Y
							* SQUARE_SIZE) - 16)});
}

void	position_junk_bis(sprite_t *sprite)
{
	sfSprite_setPosition(sprite->hp_bar_m,
			(sfVector2f) {926, 380});
	sfSprite_setPosition(sprite->red_bar_m,
			(sfVector2f) {926 + 67, 380});
	sfSprite_setPosition(sprite->mp_bar_m,
			(sfVector2f) {1100, 380});
	sfSprite_setPosition(sprite->blue_bar_m,
			(sfVector2f) {1100, 380});
	sfSprite_setPosition(sprite->mob_bar,
			(sfVector2f) {225, 250});
	sfSprite_setPosition(sprite->mob_bar_red,
			(sfVector2f) {225, 250});
	sfSprite_setPosition(sprite->npc6,
			(sfVector2f) {(NPC6a_X) * SQUARE_SIZE, ((NPC6a_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque6,
			(sfVector2f) {(NPC6a_X) * SQUARE_SIZE, ((NPC6a_Y
							* SQUARE_SIZE) - 16)});
}
