/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Battle junk
*/

#include "config.h"
#include "my.h"

void	battle_next(window_t *win, player_t *player,
		sprite_t *sprite, char *str)
{
	sfTexture*	text;

	player->e_def = 2 + rand()%2;
	player->e_health = 20 + rand()%40;
	if (win->final_battle == TRUE) {
		player->battle_id = 3;
		player->e_attack = 100;
		player->e_def = 10;
		player->e_health = 250;
		sprite->battleback = create_sprite("ressources/"
				"battle/Battleback2.png", 0, sprite);
		player->m_attack += 12;
	}
	player->e_health_max = player->e_health;
	str[18] = player->battle_id + '0';
	text = sfTexture_createFromFile(str, NULL);
	sfSprite_setTexture(sprite->ennemy_battle, text, sfTrue);
	player->battle = TRUE;
	win->repeat = 1;
	win->melgor_turn = FALSE;
}

void	sahakiann(window_t *win, int sahakian)
{
	if (win->dgt_on == TRUE) {
		sahakian -= 40;
		if (sahakian < 0) {
			win->dgt_on = FALSE;
			sahakian = 0;
		}
		sfText_move(win->dgt, (sfVector2f) {0, -8});
		sfText_setColor(win->dgt, (sfColor) {255, 0, 0, sahakian});
		sfRenderWindow_drawText(win->render_window, win->dgt, NULL);
	}
}

void	draw_battle(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window, sprite->battleback, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->battle_hero,
			NULL);
	if (win->melgor_encounter == TRUE) {
		sfRenderWindow_drawSprite(win->render_window,
				sprite->battle_mourad, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->hp_bar_m, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->red_bar_m, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->mp_bar_m, NULL);
		sfRenderWindow_drawSprite(win->render_window,
				sprite->blue_bar_m, NULL);
	}
	draw_battle_next(win, sprite);
}

int	battle_tree(player_t *player, window_t *win,
		float dgt, sprite_t *sprite)
{
	if (player->cursor_pos == 4) {
		if (win->final_battle == TRUE)
			return (1);
		player->battle = FALSE;
		win->repeat = 1;
		player->cursor_pos = 0;

	}
	else if (player->cursor_pos == 0) {
		dgt = get_damage(player, win);
		sfSprite_setScale(sprite->mob_bar_red, (sfVector2f) {dgt, 1});
	}
	if (player->cursor_pos == 2)
		player->defend = TRUE;
	else if (player->cursor_pos == 3)
		inventory(win);
	if (player->cursor_pos == 1)
		skills(win, player);
	return (0);
}

void	game_over(player_t *player, window_t *win)
{
	player->battle = FALSE;
	player->cursor_pos = 0;
	player->exp += 10 + rand()%5 - (player->lvl + 5);
	win->money += 5 + rand()%3;
	if (win->melgor_encounter == TRUE)
		player->m_exp += 10 + rand()%5 - (player->m_lvl + 5);
	if (win->final_battle == TRUE) {
		win->final_battle++;
	}
}
