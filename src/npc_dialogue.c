/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Text
*/

#include "my.h"
#include "config.h"

void	replace_name(char *result, player_t *player)
{
	int i = 0;
	int j = 0;
	char *tmp;

	if (result == NULL)
		return;
	tmp = my_strdup(result);
	while (result[i] != '\0') {
		if (result[i] == '@') {
			while (player->name[j] != '\0') {
				result[i + j] = player->name[j];
				j++;
			}
			while (tmp[i] != '\0') {
				result[i + j] = tmp[i + 1];
				i++;
			}
		}
		i++;
	}
}

void	direction(window_t *win, sprite_t *sprite, int npc_position, int i)
{
	sprite->npc_rect.left = 0;
	sprite->npc_rect.width = SQUARE_SIZE;
	sprite->npc_rect.height = NPC_HEIGHT;
	if (win->player == npc_position + MAP_X)
		sprite->npc_rect.top = 0;
	if (win->player == npc_position - 1)
		sprite->npc_rect.top = NPC_HEIGHT;
	if (win->player == npc_position + 1)
		sprite->npc_rect.top = NPC_HEIGHT * 2;
	if (win->player == npc_position - MAP_X)
		sprite->npc_rect.top = NPC_HEIGHT * 3;
	sfSprite_setTextureRect(win->npc_sprite[i], sprite->npc_rect);
	sfSprite_setTextureRect(win->npc_masque[i], sprite->npc_rect);
}

int	cinematic_controller(char *string, window_t *win,
		sprite_t *sprite, player_t *player)
{
	int return_value = 0;

	if (string == NULL || my_strlen(string) == 0) {
		return_value = -1;
		win->text_on = 0;
		if (win->dialogue_nb == 3) {
			win->dialogue_henro = 1;
			win->flags++;
		}
		controller_bis(win, player, sprite);
		controller(win, player, sprite);
	}
	return (return_value);
}

void	dialogue(window_t *win, sprite_t *sprite, player_t *player, int i)
{
	char *string;
	static int fd = -1;
	char fd_string[23] = "ressources/dialogue/??";

	fd_update(win, fd_string);
	if (fd_string == NULL)
		return;
	if (fd == -1)
		fd = open(fd_string, O_RDONLY);
	win->text_on = 1;
	string = get_next_line(fd);
	replace_name(string, player);
	if (cinematic_controller(string, win, sprite, player) == -1)
		fd = -1;
	dialogue_nb(win, i, sprite);
	update_text(string, win);
	if (string == NULL)
		return;
}

void	text(window_t *win, sprite_t *sprite, player_t *player)
{
	int i = 0;

	while (i <= NPC_NUMBER) {
		if (((win->player == win->npc_diag[i] + MAP_X
				&& sprite->player_rect.top == NPC_HEIGHT * 3)
				|| (win->player == win->npc_diag[i] - 1
				&& sprite->player_rect.top == NPC_HEIGHT * 2)
				|| (win->player == win->npc_diag[i] + 1
				&& sprite->player_rect.top == NPC_HEIGHT)
				|| (win->player == win->npc_diag[i] - MAP_X
				&& sprite->player_rect.top == 0))
				&& win->event.key.code == ENTER
				&& win->npc_map[i] == win->map_number
				&& win->menu == FALSE) {
			if (i > 8)
				i += 4;
			dialogue_update(win, i, sprite, player);
		}
		i++;
	}
}

