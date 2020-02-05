/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Skills
*/

#include "my.h"
#include "config.h"

int		can_use(int skill, player_t *player, window_t *win)
{
	if (win->melgor_encounter == FALSE) {
		return (can_use_bis(skill, player->mana));
	}
	else if (win->melgor_turn != TRUE) {
		return (can_use_bis(skill, player->m_mana));
	}
	else {
		return (can_use_bis(skill, player->mana));
	}
	return (0);
}

void	skill_event(window_t *win, player_t *player)
{
	if (player->attack > 0) {

	}
	if (win->event.type != sfEvtKeyReleased)
		return;
	if (win->event.key.code == 36)
		win->skill_loop = FALSE;
	else if (win->event.key.code == 0) {
		win->skill_used = 1;
	}
	skill_junk(win);
}

void	fire_strike(window_t *win, sprite_t *sprite, player_t *player)
{
	float dgt;

	if (win->skill_used > 2) {
		if (win->melgor_turn == 0)
			win->melgor_turn = 1;
		else if (win->melgor_turn == 1)
			win->melgor_turn = 0;
	}
	thunderbolt(win, sprite, player);
	dgt = get_damage(player, win);
	sfSprite_setScale(sprite->mob_bar_red, (sfVector2f) {dgt, 1});
	battle_junk(win, player, sprite);
	quickslash(win, sprite, player);
	win->skill_loop = FALSE;
	win->skill_used = 0;
}

void	skills_loop(window_t *win, sprite_t *sprite, player_t *player)
{
	sfRenderWindow_drawSprite(win->render_window, sprite->skills, NULL);
	if (win->skill_used < 5 && win->skill_used > 0)
		fire_strike(win, sprite, player);
	if (player->name[0] == 'a') {

	}
}

void	skills(window_t *win, player_t *player)
{
	if (win->melgor_turn == TRUE) {
		if (player->m_mana == 0)
			return;
	}
	else {
		if (player->mana == 0)
			return;
	}
	win->skill_used = 0;
	win->skill_loop = TRUE;
}
