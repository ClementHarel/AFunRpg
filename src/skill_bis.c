/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** SkillBIS
*/

#include "my.h"
#include "config.h"

void	sahakian_bis(window_t *win, player_t *player)
{
	if (win->skill_used == 1)
		player->mana -= 50;
	if (win->skill_used == 2)
		player->mana -= 75;
	if (win->skill_used == 3)
		player->mana -= 30;
	if (win->skill_used == 4)
		player->mana -= 40;
}

void	thunderbolt(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->adv_sword && sprite->blue_bar) {

	}
	if (win->skill_used == 1) {
		player->attack += 10;
		player->m_attack += 10;
	}
	if (win->skill_used == 2) {
		player->attack += 13;
		player->m_attack += 13;
	}
	if (win->skill_used == 3) {
		player->attack += 5;
		player->m_attack += 5;
	}
	if (win->skill_used == 4) {
		player->m_attack += 7;
		player->attack += 7;
	}
}

void	quickslash(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->adv_sword && sprite->blue_bar) {

	}
	if (win->skill_used == 1) {
		player->attack -= 10;
		player->m_attack -= 10;
	}
	if (win->skill_used == 2) {
		player->attack -= 13;
		player->m_attack -= 13;
	}
	if (win->skill_used == 3) {
		player->attack -= 5;
		player->m_attack -= 5;
	}
	if (win->skill_used == 4) {
		player->m_attack -= 7;
		player->attack -= 7;
	}
}

void	tornado(window_t *win, sprite_t *sprite,
		player_t *player, int sahakian)
{
	if (win->adv_sword && sprite->blue_bar) {

	}
	if (sahakian == 0)
		sahakian_bis(win, player);
	else {
	if (win->skill_used == 1)
		player->m_mana -= 50;
	if (win->skill_used == 2)
		player->m_mana -= 75;
	if (win->skill_used == 3)
		player->m_mana -= 30;
	if (win->skill_used == 4)
		player->m_mana -= 40;
	}
}
