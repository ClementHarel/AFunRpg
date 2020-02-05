/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Ennemy
*/

#include "config.h"
#include "my.h"

void	loopy_loop(window_t *win, player_t *player, sprite_t *sprite)
{
	sfRenderWindow_clear(win->render_window, sfBlack);
	if (win->repeat == -1) {
		win->repeat = 0;
		load(win, player, sprite);
	}
	lvl_up(player);
	fade(win);
	if (win->map_number == 1 && sprite->is_animated == 0)
		mill_move(sprite);
	drawing_oxydia(win, sprite);
	drawing_forest(win, sprite);
	sfRenderWindow_drawSprite(win->render_window, sprite->light, NULL);
	if (win->menu == TRUE) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->menu, NULL);
		menu_loop(win, sprite, player);
	}
}

void	anim_dgt(window_t *win, int dgt)
{
	char font[28] = "ressources/font/aachenn.ttf";
	char str[2];
	sfFont* fontfont = sfFont_createFromFile(font);

	str[0] = dgt / 10 + '0';
	str[1] = dgt % 10 + '0';
	str[2] = '\0';
	if (dgt < 1)
		sfText_setString(win->dgt, "00");
	else
		sfText_setString(win->dgt, str);
	sfText_setFont(win->dgt, fontfont);
	sfText_setPosition(win->dgt, (sfVector2f){200, 150});
	win->dgt_on = TRUE;
}

void	anim_turn(sprite_t *sprite, window_t *win)
{
	static sfIntRect player_rect;

	player_rect.top = NPC_HEIGHT;
	player_rect.left += SQUARE_SIZE;
	if (player_rect.left >= SQUARE_SIZE * 4)
		player_rect.left = 0;
	player_rect.width = SQUARE_SIZE;
	player_rect.height = NPC_HEIGHT;
	if (win->melgor_turn == 0)
		sfSprite_setTextureRect(sprite->battle_hero, player_rect);
	else
		sfSprite_setTextureRect(sprite->battle_mourad, player_rect);
}

int	get_damage_ennemy(player_t *player, sprite_t *sprite,
		int target, window_t *win)
{
	float dgt = get_float(target, player, win);

		if (target == 0)
			sfSprite_setScale(sprite->red_bar,
					(sfVector2f) {dgt, 1});
		else
			sfSprite_setScale(sprite->red_bar_m,
					(sfVector2f) {dgt, 1});
		if (target == 1) {
			dgt = player->e_attack - player->m_def;
			if (player->m_defend == TRUE)
				dgt -= 10;
		}
		if (target == 0) {
			dgt = player->e_attack - player->def;
			if (player->h_defend == TRUE)
				dgt -= 10;
		}
		return ((int)dgt);
}

void	ennemy_turn(player_t *player, sprite_t *sprite,
		window_t *win)
{
	int target = 0;
	int dgt;

	if (win->melgor_encounter == TRUE)
		target = rand()%2;
	dgt = get_damage_ennemy(player, sprite, target, win);
	if (target == 0)
		anim_dgt(win, dgt + rand() % 4);
	else
		anim_dgt(win, dgt + rand() % 4);
	if (target == 0)
		sfText_setPosition(win->dgt, (sfVector2f){1050, 100});
	if (target == 1)
		sfText_setPosition(win->dgt, (sfVector2f){1050, 300});
	win->melgor_turn = FALSE;
}
