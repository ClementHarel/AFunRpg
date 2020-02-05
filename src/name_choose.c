/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Choosing the player name
*/

#include "my.h"
#include "config.h"

sfText	*create_text_player(sfVector2f position,
	window_t *win, char *font)
{
	sfColor color = { 0, 0, 0, 255 };
	sfText*	text;

	win->font = sfFont_createFromFile(font);
	text = sfText_create();
	sfText_setFont(text, win->font);
	sfText_setCharacterSize(text, TEXT_SIZE * 3);
	sfText_setColor(text, color);
	sfText_setPosition(text, position);
	sfText_setStyle(text, sfTextBold);
	return (text);
}

int	update_string(char string[8], window_t *win)
{
	static int rank = 0;

	if (win->event.key.code == 58 && rank == 0)
		return (0);
	if (win->event.key.code == 59 && rank >= 0) {
		rank--;
		string[rank] = '_';
		return (0);
	}
	if (rank > 0 && win->event.key.code == 58)
		return (1);
	if (rank == 8)
		return (0);
	string[rank] = win->event.key.code + 97;
	if (rank == 0)
		string[rank] = win->event.key.code + 97 - 32;
	rank++;
	return (0);
}

int	poll_event_player(window_t *win, char string[8])
{
	while (sfRenderWindow_pollEvent(win->render_window, &win->event)) {
		if ((win->event.type == sfEvtKeyReleased
				&& win->event.key.code >= 0
				&& win->event.key.code <= 25)
				|| (win->event.key.code == 59
			&& win->event.type == sfEvtKeyReleased)
			|| (win->event.key.code == 58
			&& win->event.type == sfEvtKeyReleased)) {
			if (update_string(string, win) == 1)
				return (1);
			if (win->event.type == sfEvtClosed)
				sfRenderWindow_close(win->render_window);
		}
	}
	return (0);
}

int	loop(window_t *win, player_t *player,
		sfText* player_name, sfSprite *back)
{
	static char string[9] = "________";
	int i = my_strlen(string) - 1;

	sfRenderWindow_clear(win->render_window, sfBlack);
	fade(win);
	if (poll_event_player(win, string) == 1) {
		while (string[i] == '_')
			i--;
		string[i + 1] = '\0';
		player->name = string;
		return (1);
	}
	sfText_setString(player_name, string);
	sfRenderWindow_drawSprite(win->render_window, back, NULL);
	sfRenderWindow_drawText(win->render_window, win->text, NULL);
	sfRenderWindow_drawText(win->render_window, player_name, NULL);
	sfRenderWindow_drawSprite(win->render_window, win->white, NULL);
	sfRenderWindow_display(win->render_window);
	return (0);
}

int	choose_name(window_t *win, player_t *player)
{
	sfText*	player_name;
	sfTexture* tmp = sfTexture_createFromFile("ressources/sprite/name_"
			"font.png", NULL);
	sfSprite* background = sfSprite_create();
	sfSprite_setTexture(background, tmp, sfTrue);

	player_name = create_text_player((sfVector2f){500, 300}, win,
				"ressources/font/moon_get-Heavy.ttf");
	create_text((sfVector2f) {50, 100}, win, "ressources/font/arial.ttf");
	update_text("Choose the name of your character with the keyboard.\n\n"
			"            Press enter to validate. \n", win);
		while (sfRenderWindow_isOpen(win->render_window) && (loop(win,
				player, player_name, background) != 1));
	update_text("", win);
	init_player(win, player);
	text_create(win, player);
	generate_colision(win);
	return (1);
}
