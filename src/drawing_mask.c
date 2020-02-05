/*
** EPITECH PROJECT, 2018
** Drawing mask
** File description:
** MY RPG
*/

#include "my.h"

void	save_bis(window_t *win, int fd)
{
	write(fd, &win->map_number, sizeof(win->map_number));
	write(fd, &win->player, sizeof(win->player));
	write(fd, &win->intro, sizeof(win->intro));
	write(fd, &win->melgor_encounter, sizeof(win->melgor_encounter));
	write(fd, &win->melgor_after_battle, sizeof(win->melgor_after_battle));
	write(fd, &win->dialogue_henro, sizeof(win->dialogue_henro));
	write(fd, &win->oxydia_attack, sizeof(win->oxydia_attack));
	write(fd, &win->block_ottoman, sizeof(win->block_ottoman));
	write(fd, &win->money, sizeof(win->money));
	write(fd, &win->flags, sizeof(win->flags));
	write(fd, &win->weapon, sizeof(win->weapon));
	write(fd, &win->armor, sizeof(win->armor));
	write(fd, &win->health_potion, sizeof(win->health_potion));
	write(fd, &win->mana_potion, sizeof(win->mana_potion));
	write(fd, &win->long_sword, sizeof(win->long_sword));
	write(fd, &win->heavy_armor, sizeof(win->heavy_armor));
	write(fd, &win->adv_armor, sizeof(win->adv_armor));
	write(fd, &win->adv_sword, sizeof(win->adv_sword));
	write(fd, &win->elendia_arrival, sizeof(win->elendia_arrival));
	write(fd, &win->quest_on, sizeof(win->quest_on));
}

void	draw_elendia(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 6) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque6, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque7, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque8, NULL);
	}
	if (win->map_number == 7) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque9, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque10, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque11, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque12, NULL);
	}
}

void	draw_map_three_m(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window,
			sprite->npc_masque3, NULL);
}

void	draw_map_two_m(window_t *win, sprite_t *sprite)
{
	if (win->melgor_encounter == 1)
		sfRenderWindow_drawSprite(win->render_window,
			sprite->fire, NULL);
	else {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque1, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->npc_masque2, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->mill, NULL);
	}
}

void	draw_map_one_m(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window,
			sprite->npc_masque0, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->npc_masque4, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->npc_masque5, NULL);
}
