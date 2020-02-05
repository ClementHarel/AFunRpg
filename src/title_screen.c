/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** itlte
*/

#include "my.h"
#include "config.h"

int	action_title(window_t *win, player_t *player, int fd)
{
	switch (win->cursor_title_pos) {
	case (0):
		return (1);
		break;
	case (1):
		if (fd < 0)
			return (0);
		win->load = TRUE;
		text_create(win, player);
		return (1);
		break;
	case (2):
		win->htp = TRUE;
		break;
	case (3):
		sfRenderWindow_close(win->render_window);
		break;
	}
	return (0);
}

void	switch_cursor(int position, sprite_t *sprite)
{
	switch (position) {
	case (0):
		sfSprite_setPosition(sprite->title_cursor,
				(sfVector2f ) { 458, 455 });
		break;
	case (1):
		sfSprite_setPosition(sprite->title_cursor,
				(sfVector2f ) { 458, 525 });
		break;
	case (2):
		sfSprite_setPosition(sprite->title_cursor,
				(sfVector2f ) { 455, 585 });
		break;
	case (3):
		sfSprite_setPosition(sprite->title_cursor,
				(sfVector2f ) { 480, 635 });
		break;
	}
}

int	poll_event_title(window_t *win, sprite_t *sprite, player_t *player)
{
	int fd = open("save/Save.data", O_RDWR | S_IRUSR | S_IWUSR);

	while (sfRenderWindow_pollEvent(win->render_window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->render_window);
		if (win->event.type == sfEvtKeyReleased) {
			if (win->event.key.code == UP &&
					win->cursor_title_pos < 3)
				win->cursor_title_pos++;
			else if (win->event.key.code == DOWN &&
					win->cursor_title_pos > 0)
				win->cursor_title_pos--;
			switch_cursor(win->cursor_title_pos, sprite);
			if (win->event.key.code == ENTER && win->htp == FALSE)
				return (action_title(win, player, fd));
			else if (win->htp == TRUE)
				win->htp = FALSE;
		}
	}
	return (0);
}

int	title_screen(window_t *win, sprite_t *sprite, player_t *player)
{
	static int set = 0;

	if (set == 0)
		sfSprite_setPosition(sprite->title_cursor,
				(sfVector2f ) { 458, 455 });
	set = 1;
	sfRenderWindow_clear(win->render_window, sfBlack);
	fade(win);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->title_screen, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->title_cursor, NULL);
	if (win->htp == TRUE)
		sfRenderWindow_drawSprite(win->render_window,
				sprite->title_htp, NULL);
	sfRenderWindow_drawSprite(win->render_window, win->white, NULL);
	sfRenderWindow_display(win->render_window);
	return (poll_event_title(win, sprite, player));
}
