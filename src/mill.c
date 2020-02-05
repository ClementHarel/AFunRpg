/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Mill moving on map 1
*/

#include "my.h"
#include "config.h"

void	drawing_plzzz(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 3 && win->quest_on == 1)
		sfRenderWindow_drawSprite(win->render_window,
				sprite->necklace, NULL);
	if (win->map_number == 6) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc6, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc7, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc8, NULL);
	}
	if (win->map_number == 0)
		draw_map_one_m(win, sprite);
}

void	drawing_plz(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 7) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc9, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc10, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc11, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc12, NULL);
	}
	if (win->map_number == 8) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->delchior, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->melgor, NULL);
	}
	draw_elendia(win, sprite);
	sfRenderWindow_drawSprite(win->render_window, sprite->map_masque, NULL);
}

float	get_float(int target, player_t *player, window_t *win)
{
	float dgt;

	if (target == 0) {
		player->health -= player->e_attack - player->def;
		dgt = (double)player->health / (double)player->max_health;
	}
	if (target == 1) {
		player->m_health -= player->e_attack - player->m_def;
		dgt = (double)player->m_health / (double)player->m_max_health;
	}
	if (dgt < 0) {
		player->battle = FALSE;
		player->cursor_pos = 0;
		dgt = 0;
		win->repeat = 3;
	}
	if (dgt > 1)
		dgt = 1;
	return (dgt);
}

void	controller_bis(window_t *win, player_t *player, sprite_t *sprite)
{
	if (win->dialogue_nb == 6 || win->dialogue_nb == 9)
		win->block_forest = 0;
	if (win->dialogue_nb == 10) {
		win->melgor_encounter = 1;
		battle(player, sprite, win);
	}
	if (win->dialogue_nb == 11) {
		win->melgor_after_battle = 1;
		win->repeat = 1;
		win->flags++;
	}
	if (win->dialogue_nb == 12) {
		win->map_number = 3;
		new_map(sprite, win, 30 * SQUARE_SIZE,
				(SQUARE_SIZE * 21) - 16);
		win->oxydia_attack = 1;
		win->flags++;
	}
}

void	mill_move(sprite_t *sprite)
{
	static sfIntRect	fire;
	static int i	= 0;

	sfSprite_rotate(sprite->mill, 3);
	i++;
	if (i >= 3)
		i = 0;
	else
		return;
	fire.width = 1280;
	fire.height = 769;
	fire.top = 0;
	fire.left += 1280;
	if (fire.left >= 1280 * 4)
		fire.left = 0;
	sfSprite_setTextureRect(sprite->fire, fire);
}
