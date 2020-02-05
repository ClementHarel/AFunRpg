/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Init npc diag array
*/

#include "my.h"
#include "config.h"

void	fill_plz(sprite_t *sprite, window_t *win)
{
	win->npc_sprite[0] = sprite->npc0;
	win->npc_masque[0] = sprite->npc_masque0;
	win->npc_sprite[1] = sprite->npc1;
	win->npc_masque[1] = sprite->npc_masque1;
	win->npc_sprite[2] = sprite->npc2;
	win->npc_masque[2] = sprite->npc_masque2;
	win->npc_sprite[3] = sprite->npc3;
	win->npc_masque[3] = sprite->npc_masque3;
	win->npc_sprite[4] = sprite->npc4;
	win->npc_masque[4] = sprite->npc_masque4;
	win->npc_sprite[5] = sprite->npc5;
	win->npc_masque[5] = sprite->npc_masque5;
	win->npc_sprite[6] = sprite->npc5;
	win->npc_masque[6] = sprite->npc_masque5;
	win->npc_sprite[15] = sprite->npc8;
	win->npc_masque[15] = sprite->npc_masque8;
	win->npc_sprite[16] = sprite->npc9;
	win->npc_masque[16] = sprite->npc_masque9;
}

void	cinematic_npc(int i, window_t *win)
{
	if ((i == 3) && (win->dialogue_henro == 1))
		win->dialogue_nb = 7;
}

void	fill_npc_map(window_t *win)
{
	int fd = open("ressources/dialogue/npc_map", O_RDONLY);
	char buffer[1] = "0";
	int i = 0;

	while (read(fd, buffer, 1) != '\0') {
		win->npc_map[i] = buffer[0] - '0';
		i++;
	}
}

void	fill_npc_sprite(sprite_t *sprite, window_t *win)
{
	fill_plz(sprite, win);
	win->npc_sprite[17] = sprite->npc10;
	win->npc_masque[17] = sprite->npc_masque10;
	win->npc_sprite[18] = sprite->npc11;
	win->npc_masque[18] = sprite->npc_masque11;
	win->npc_masque[19] = sprite->npc_masque12;
	win->npc_sprite[19] = sprite->npc12;
	sfSprite_setOrigin(sprite->mill, (sfVector2f ) { 149, 144 });
	sfSprite_setScale(win->white, (sfVector2f ) { WINDOW_X, WINDOW_Y });

}

void	init_npc_diag(window_t *win, sprite_t *sprite)
{
	int fd = open("ressources/dialogue/npc_diag", O_RDONLY);
	char str[3];
	int i = 0;

	win->npc_sprite = malloc(sizeof(sfSprite*) * NPC_NUMBER);
	win->npc_masque = malloc(sizeof(sfSprite*) * NPC_NUMBER);
	win->npc_diag = malloc(sizeof(int) * NPC_NUMBER);
	win->npc_map = malloc(sizeof(int) * NPC_NUMBER);
	while (i < NPC_NUMBER) {
		read(fd, str, 3);
		win->npc_diag[i] = my_getnbr(str);
		i++;
		read(fd, str, 1);
	}
	fill_npc_sprite(sprite, win);
	fill_npc_map(win);
}
