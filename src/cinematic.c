/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Cinematic event
*/

#include "my.h"
#include "config.h"

void	the_last_function(window_t *win, int new_val, int fd)
{
	load_qua(win, new_val, fd);
	read(fd, &new_val, sizeof(new_val));
	win->health_potion = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->mana_potion = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->long_sword = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->heavy_armor = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->adv_armor = new_val;
}

void	position_update(window_t *win, sprite_t *sprite)
{
	win->player = (int) (sfSprite_getPosition
			(sprite->player).x / SQUARE_SIZE)
			+ ((((sfSprite_getPosition(sprite->player).y)
			/ SQUARE_SIZE) + 0.5) * MAP_X);
	win->player_x = win->player % MAP_X;
}

int	cinematic_bis(window_t *win, sprite_t
		*sprite, player_t *player, int i)
{
	i = intro(win, i, sprite, player);
	block_forest(win, sprite, player);
	block_ottoman(win, sprite, player);
	melgor_encounter(win, sprite, player);
	melgor_after_battle(win, sprite, player);
	attack_oxydia(win, sprite, player);
	elendia_arrival(win, sprite, player);
	final_battle(win, sprite, player);
	ending(win, sprite, player);
	if (win->block_forest == 1 && win->event.key.code == ENTER
			&& win->event.type == sfEvtKeyReleased) {
		dialogue(win, sprite, player, 1);
	}
	if (win->event.type == sfEvtClosed)
		sfRenderWindow_close(win->render_window);
	return (i);
}

void	cinematic(window_t *win, sprite_t *sprite, player_t *player)
{
	static int cinematic0 = 0;

	position_update(win, sprite);
	if (win->event.key.code != LEFT && win->event.key.code != RIGHT)
		win->player_y = win->player / MAP_X;
	player_movement(win, sprite, player);
	while (sfRenderWindow_pollEvent(win->render_window, &win->event)) {
		if (win->debog == TRUE)
			debog(win, sprite);
		if (win->event.key.code == 59 && win->debog == FALSE)
			win->debog = TRUE;
		if (win->event.type == sfEvtKeyReleased && win->menu == TRUE)
			menu_move_cursor(win, sprite, player);
		if (win->event.key.code == 36
				&& win->event.type == sfEvtKeyReleased) {
			menu(win, player);
		}
		cinematic0 = cinematic_bis(win, sprite, player, cinematic0);
	}
}
