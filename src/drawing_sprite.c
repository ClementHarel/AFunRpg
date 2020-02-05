/*
** EPITECH PROJECT, 2018
** Draw sprite. (One function = One map)
** File description:
** My RPG
*/

#include "my.h"

void	loading(window_t *win, sprite_t *sprite, player_t *player)
{
	win->repeat = 1;
	if (win->load == FALSE)
		while (sfRenderWindow_isOpen(win->render_window)
				&& (choose_name(win, player) != 1));
	create_map(sprite, win);
	if (win->load == TRUE)
		load(win, player, sprite);
}

void	draw_map_four(window_t *win, sprite_t *sprite)
{
	if (win->melgor_after_battle == 0)
		sfRenderWindow_drawSprite(win->render_window,
				sprite->melgor, NULL);
	if (win->melgor_encounter == 0)
		sfRenderWindow_drawSprite(win->render_window,
				sprite->mob, NULL);
}

void	draw_map_three(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window, sprite->npc3, NULL);
}

void	draw_map_two(window_t *win, sprite_t *sprite)
{
	if (win->melgor_encounter == 0) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc1, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc2, NULL);
	}
	else
		sfRenderWindow_drawSprite(win->render_window,
				sprite->melgor, NULL);
}

void	draw_map_one(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window, sprite->npc0, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->npc4, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->npc5, NULL);
}
