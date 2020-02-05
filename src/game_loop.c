/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Game Loop
*/

#include "my.h"
#include "config.h"

void	poll_event(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->shop_loop == TRUE)
		return;
	teleport(win, sprite);
	if (sprite->is_animated == 0)
		cinematic(win, sprite, player);
	else
		cinematic_bis(win, sprite, player, 0);
}

void	drawing_forest(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 4)
		draw_map_four(win, sprite);
}

void	drawing_oxydia(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window, sprite->map, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->player, NULL);
	if (win->map_number == 0)
		draw_map_one(win, sprite);
	if (win->map_number == 1)
		draw_map_two(win, sprite);
	if (win->map_number == 2)
		draw_map_three(win, sprite);
	drawing_plzzz(win, sprite);
	drawing_plz(win, sprite);
	if (win->map_number == 1)
		draw_map_two_m(win, sprite);
	if (win->map_number == 2)
		draw_map_three_m(win, sprite);
	if (win->text_on == 1)
		sfRenderWindow_drawSprite
		(win->render_window, sprite->dialogue, NULL);
}

void	game_loop(window_t *win, sprite_t *sprite, player_t *player)
{
	loopy_loop(win, player, sprite);
	sfRenderWindow_drawText(win->render_window, win->text, NULL);
	sfRenderWindow_drawText(win->render_window, win->name, NULL);
	if (win->equipment_menu == TRUE)
		equipment_loop(win, sprite, player);
	if (win->inventory_menu == TRUE)
			inventory_loop(win, sprite, player);
	else if (player->battle == TRUE)
		battle_loop(player, win, sprite);
	if (win->skill_loop == TRUE)
		skills_loop(win, sprite, player);
	poll_event(win, sprite, player);
	if (win->shop_loop == TRUE)
		shop_loop(win, sprite);
	sfRenderWindow_drawSprite(win->render_window, win->white, NULL);
	sfRenderWindow_display(win->render_window);
}

void	game_setup(window_t *win, sprite_t *sprite)
{
	sfClock* clock = sfClock_create();
	sfTime time;
	player_t player;

	win->white = create_sprite("ressources/white.png", 0, sprite);
	create_all_sprite(sprite);
	init_npc_diag(win, sprite);
	win->cursor_title_pos = 0;
	win->repeat = 1;
	while (sfRenderWindow_isOpen(win->render_window)
			&& (title_screen(win, sprite, &player) != 1));
	loading(win, sprite, &player);
	while (sfRenderWindow_isOpen(win->render_window)) {
		time = sfClock_getElapsedTime(clock);
		if (time.microseconds > GAME_SPEED) {
			sfClock_restart(clock);
			game_loop(win, sprite, &player);
		}
	}
}
