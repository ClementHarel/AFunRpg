/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Call to create a text
*/

#include "my.h"
#include "config.h"

void	final_text(int nb, char *string, window_t *win)
{
	int i = 0;
	char *name = malloc(nb);

	while (string[i] != ':') {
		name[i] = string[i];
		i++;
	}
	name[i] = '\0';
	sfText_setString(win->text, string);
	sfText_setString(win->name, name);
}

void	update_text(char *string, window_t *win)
{
	int i = 0;

	if (string == NULL) {
		sfText_setString(win->text, "");
		sfText_setString(win->name, "");
		return;
	}
	while (string[i] != ':') {
		if (string[i] == '\0') {
			sfText_setString(win->text, string);
			return;
		}
		i++;
	}
	final_text(i, string, win);
}

void	create_text(sfVector2f position, window_t *win, char *font)
{
	sfColor color = { 255, 255, 255, 255 };

	win->font = sfFont_createFromFile(font);
	win->name = sfText_create();
	win->text = sfText_create();
	win->dgt_e = sfText_create();
	sfText_setFont(win->text, win->font);
	sfText_setFont(win->name, win->font);
	sfText_setCharacterSize(win->text, TEXT_SIZE);
	sfText_setCharacterSize(win->name, TEXT_SIZE);
	sfText_setColor(win->text, color);
	color.r = 0;
	sfText_setColor(win->name, color);
	sfText_setPosition(win->text, position);
	sfText_setPosition(win->name, position);
	sfText_setStyle(win->text, sfTextBold);
	sfText_setStyle(win->name, sfTextBold);
}
