/*
** EPITECH PROJECT, 2018
** My_rpg
** File description:
** Norm iz good yes
*/

#include "my.h"
#include "config.h"

void	position_junk(sprite_t *sprite)
{
	sfSprite_setPosition(sprite->melgor,
			(sfVector2f) { NPC6_X * SQUARE_SIZE,
		((NPC6_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->mob,
			(sfVector2f) {(NPC6_X + 1) * SQUARE_SIZE, ((NPC6_Y
							* SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->battle_hero,
			(sfVector2f) {1059, 258});
	sfSprite_setPosition(sprite->battle_mourad,
			(sfVector2f) {1059, 442});
	sfSprite_setPosition(sprite->ennemy_battle,
			(sfVector2f) {216, 303});
	sfSprite_setPosition(sprite->hp_bar,
			(sfVector2f) {926, 193});
	sfSprite_setPosition(sprite->red_bar,
			(sfVector2f) {926 + 67, 193});
	sfSprite_setPosition(sprite->mp_bar,
			(sfVector2f) {1100, 193});
	sfSprite_setPosition(sprite->blue_bar,
			(sfVector2f) {1100, 193});
}

void	skill_junk(window_t *win)
{
	if (win->event.key.code == 25) {
		win->skill_used = 2;
	}
	else if (win->event.key.code == 16) {
		win->skill_used = 3;
	}
	else if (win->event.key.code == 18) {
		win->skill_used = 4;
	}
}

void	battle_junk(window_t *win, player_t *player, sprite_t *sprite)
{
	float mana = 0;

	if (win->melgor_encounter == FALSE)
		no_clue(win, sprite, player, mana);
	else if (win->melgor_turn != TRUE) {
		tornado(win, sprite, player, 1);
		if (player->mana < 0)
			player->mana = 0;
		if (player->m_mana < 0)
			player->m_mana = 0;
		mana = (double)player->m_mana / (double)player->m_max_mana;
		sfSprite_setScale(sprite->blue_bar_m, (sfVector2f) {mana, 1});
	}
	else
		no_clue(win, sprite, player, mana);
}

int	can_use_bis(int skill, int mana)
{
	switch (skill) {
	case (1) :
			if (mana < 50) {
				return (1);
			}
			break;
	}
	return (0);
}

int		my_nbrlen(int nbr)
{
	int result = 0;

	while (nbr / 10 > 0) {
		nbr = nbr / 10;
		result++;
	}
	return (result + 1);
}
