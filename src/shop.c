/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Shop
*/

#include "config.h"
#include "my.h"

void	action_next(window_t *win)
{
	switch (win->cursor_pos_shop) {
	case (3):
		if (win->money >= 10 && win->mana_potion < 9) {
			win->money -= 10;
			win->mana_potion++;
		}
		break;
	case (4):
		if (win->money >= 50) {
			win->money -= 50;
			win->heavy_armor = TRUE;
		}
		break;
	case (5):
		win->shop_loop = FALSE;
		break;
	}
}

void	action(window_t *win)
{
	switch (win->cursor_pos_shop) {
	case (1):
		if (win->money >= 20 && win->health_potion < 9) {
			win->money -= 20;
			win->health_potion++;
		}
		break;
	case (2):
		if (win->money >= 70) {
			win->money -= 70;
			win->long_sword = TRUE;
		}
		break;
	}
	action_next(win);
}

void	poll_event_loop(window_t *win)
{
	while (sfRenderWindow_pollEvent(win->render_window, &win->event)) {
		if (win->event.type == sfEvtKeyReleased) {
			if (win->event.key.code == 36)
				win->shop_loop = FALSE;
			if ((win->event.key.code == DOWN
					|| win->event.key.code == RIGHT)
					&& win->cursor_pos_shop < 5)
				win->cursor_pos_shop++;
			if ((win->event.key.code == UP
					|| win->event.key.code == LEFT)
					&& win->cursor_pos_shop > 1)
				win->cursor_pos_shop--;
			if (win->event.key.code == ENTER)
				action(win);
		}
	}
}

void	shop_loop_next(window_t *win, sprite_t *sprite)
{
	switch (win->cursor_pos_shop) {
	case (3) :
			sfSprite_setPosition(sprite->cursor,
					(sfVector2f) {50, 530});
	break;
	case (4) :
			sfSprite_setPosition(sprite->cursor,
					(sfVector2f) {710, 530});
	break;
	case (5) :
			sfSprite_setPosition(sprite->cursor,
					(sfVector2f) {435, 690});
	break;
	}
}

void	shop_loop(window_t *win, sprite_t *sprite)
{
	poll_event_loop(win);
	switch (win->cursor_pos_shop) {
	case (1) :
			sfSprite_setPosition(sprite->cursor,
					(sfVector2f) {50, 300});
	break;
	case (2) :
			sfSprite_setPosition(sprite->cursor,
					(sfVector2f) {710, 300});
	break;
	}
	shop_loop_next(win, sprite);
	sfRenderWindow_drawSprite(win->render_window, sprite->shop, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->cursor, NULL);
}
