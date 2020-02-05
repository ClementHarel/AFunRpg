/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Menu_text 2
*/

#include "config.h"
#include "my.h"

void	 controller(window_t *win, player_t *player, sprite_t *sprite)
{
	if (win->dialogue_nb == 16)
		win->quest_on = 1;
	if (win->dialogue_nb == 19)
		win->shop_loop = TRUE;
	if (win->dialogue_nb == 25) {
		win->elendia_arrival = 1;
		win->flags++;
	}
	if (win->dialogue_nb == 21) {
		win->final_battle = TRUE;
		battle(player, sprite, win);
	}
	if (win->dialogue_nb == 22)
		win->final_battle++;
	if (win->dialogue_nb == 23) {
		win->quest_on++;
		player->attack += 8;
		player->def += 7;
	}
	win->block_forest = 0;
}

void	dialogue_nb(window_t *win, int i, sprite_t *sprite)
{
	if (win->dialogue_nb != 4 && win->dialogue_nb != 5
			&& win->dialogue_nb != 6
		&& win->dialogue_nb != 8 && win->dialogue_nb != 9
		&& win->dialogue_nb != 10 && win->dialogue_nb != 13
		&& win->dialogue_nb != 14 && win->dialogue_nb != 17
		&& win->dialogue_nb != 18 && win->dialogue_nb != 23) {
		if (i > 8)
			direction(win, sprite, win->npc_diag[i - 4], i);
		else
			direction(win, sprite, win->npc_diag[i], i);
	}
}

void	text_create_new(window_t *win)
{
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	sfText_setFont(win->short_sword, font);
	sfText_setFont(win->long_sword_txt, font);
	sfText_setFont(win->heavy_armor_txt, font);
	sfText_setFont(win->nothing, font);
	sfText_setFont(win->lvl_menu, font);
	sfText_setFont(win->m_lvl_menu, font);
	sfText_setCharacterSize(win->def, TEXT_SIZE * 3);
	sfText_setCharacterSize(win->dgt, TEXT_SIZE + 40);
}

void	text_create_equip(window_t *win)
{
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	win->health_txt = sfText_create();
	win->mana_txt = sfText_create();
	win->heal_melgor = sfText_create();
	win->heal_player = sfText_create();
	sfText_setFont(win->health_txt, font);
	sfText_setFont(win->mana_txt, font);
	sfText_setFont(win->heal_player, font);
	sfText_setFont(win->heal_melgor, font);
	sfText_setPosition(win->atk, (sfVector2f){188, 473});
	sfText_setPosition(win->def, (sfVector2f){188, 633});
	sfText_setPosition(win->heal_player, (sfVector2f){900, 573});
	sfText_setPosition(win->heal_melgor, (sfVector2f){900, 700});
	sfText_setPosition(win->health_txt, (sfVector2f){100, 265});
	sfText_setPosition(win->mana_txt, (sfVector2f){100, 400});
	sfText_setCharacterSize(win->atk, TEXT_SIZE * 3);
}

void	text_create_inv(window_t *win)
{
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	sfText_setCharacterSize(win->goal, TEXT_SIZE);
	sfText_setCharacterSize(win->m_lvl_menu, TEXT_SIZE);
	sfText_setCharacterSize(win->lvl_menu, TEXT_SIZE);
	sfText_setPosition(win->lvl_menu, (sfVector2f){280, 200});
	sfText_setPosition(win->m_lvl_menu, (sfVector2f){280, 375});
	sfText_setPosition(win->atk, (sfVector2f){188, 473});
	sfText_setPosition(win->def, (sfVector2f){188, 633});
	sfText_setPosition(win->short_sword, (sfVector2f){454, 519});
	sfText_setPosition(win->long_sword_txt, (sfVector2f){850, 519});
	sfText_setPosition(win->heavy_armor_txt, (sfVector2f){850, 519});
	sfText_setPosition(win->nothing, (sfVector2f){454, 660});
	sfText_setFont(win->atk, font);
	sfText_setFont(win->def, font);
	text_create_new(win);
	text_create_equip(win);
}
