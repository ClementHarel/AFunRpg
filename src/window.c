/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Create Window
*/

#include "my.h"
#include "config.h"

void	change_dir(int value, sfSprite *sprite)
{
	sfIntRect	rect;

	rect.left = 0;
	rect.width = 32;
	rect.height = 48;
	switch (value) {
	case (RIGHT):
		rect.top = NPC_HEIGHT * 2;
		break;
	case (LEFT):
		rect.top = NPC_HEIGHT;
		break;
	case (DOWN):
		rect.top = NPC_HEIGHT * 3;
		break;
	case (UP):
		rect.top = 0;
		break;
	}
	sfSprite_setTextureRect(sprite, rect);
}

void invert_fade(window_t *win, sfColor color)
{
	int fd = open("save/Save.data", O_RDONLY);
	sfText* text = sfText_create();
	sfFont* font = sfFont_createFromFile("ressources/font/aachenn.ttf");
	sfVector2f position = { 200, 192 };

	sfText_setString(text, "Thanks for Playing !");
	if (win->repeat == 3)
		sfText_setString(text, "You died.\n\n Loading save file...");
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 100);
	sfText_setPosition(text, position);
	color.a = 0;
	non(color, win, fd, text);
	if (win->repeat == 3 && fd > 0) {
		win->repeat = -1;
		return;
	}
		sfRenderWindow_close(win->render_window);
}

void	fade(window_t *win)
{
	static sfColor color = { 0, 0, 0, 255};

	if (win->repeat == 1)
		color.a += 255;
	if (win->repeat == 3)
		color.r = 255;
	if (color.a >= 255)
		win->repeat = 0;
	if (color.a > 0 && win->repeat == 0)
		color.a -= 51;
	if (win->repeat >= 2)
		invert_fade(win, color);
	else
		sfSprite_setColor(win->white, color);
}

void	init_var(window_t *win)
{
	char buffle[1];
	int fd = open("/dev/urandom", O_RDONLY);

	win->block_ottoman = 0;
	win->menu = FALSE;
	win->debog = FALSE;
	win->player_x = 0;
	win->player_y = 0;
	win->menu_cursor = 0;
	read(fd, buffle, 1);
	win->srandom = buffle[0];
	win->mob_killed = 0;
	win->equipment_menu = 0;
	win->cursor_pos_equipment = TRUE;
	win->cursor_pos_equipment2 = TRUE;
	init_win(win);
}

void	new_window(window_t *win)
{
	init_var(win);
	win->melgor_encounter = 0;
	win->melgor_after_battle = 0;
	win->oxydia_attack = 0;
	win->dialogue_henro = 0;
	win->intro = 0;
	win->mode.width = WINDOW_X;
	win->mode.height = WINDOW_Y;
	win->money = 30;
	win->goal = 0;
	win->map_number = 0;
	win->text_on = 0;
	win->block_forest = 0;
	win->dialogue_nb = 0;
	win->player = 0;
	win->render_window = sfRenderWindow_create(win->mode, "My_RPG", sfClose
			| sfResize, NULL);
	sfRenderWindow_setKeyRepeatEnabled(win->render_window, sfFalse);
	sfRenderWindow_setMouseCursorVisible(win->render_window, sfFalse);
	sfRenderWindow_requestFocus(win->render_window);
}
