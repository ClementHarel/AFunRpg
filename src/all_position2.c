/*
** EPITECH PROJECT, 2018
** My rpg
** File description:
** All position set
*/

#include "my.h"
#include "config.h"

void	load_qua(window_t *win, int new_val, int fd)
{
	read(fd, &new_val, sizeof(new_val));
	win->intro = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->melgor_encounter = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->melgor_after_battle = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->oxydia_attack = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->dialogue_henro = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->block_ottoman = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->money = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->flags = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->weapon = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->armor = new_val;
}

void	load_tris(player_t *player, int new_val, window_t *win, int fd)
{
	read(fd, &new_val, sizeof(new_val));
	player->m_max_mana = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_max_health = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_exp = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_lvl = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_attack = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_def = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->player_x = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->player_y = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->map_number = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->player = new_val;
}

void	load_bis(player_t *player, int new_val, int fd)
{
	read(fd, &new_val, sizeof(new_val));
	player->health = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->mana = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->max_health = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->max_mana = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->exp = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->lvl = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->attack = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->def = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_mana = new_val;
	read(fd, &new_val, sizeof(new_val));
	player->m_health = new_val;
}

void	save_tris(window_t *win, player_t *player, int fd)
{
	write(fd, &player->m_health, sizeof(player->m_health));
	write(fd, &player->m_max_mana, sizeof(player->m_max_mana));
	write(fd, &player->m_max_health, sizeof(player->m_health));
	write(fd, &player->m_exp, sizeof(player->m_exp));
	write(fd, &player->m_lvl, sizeof(player->m_lvl));
	write(fd, &player->m_attack, sizeof(player->m_attack));
	write(fd, &player->m_def, sizeof(player->m_def));
	write(fd, &win->player_x, sizeof(win->player_x));
	write(fd, &win->player_y, sizeof(win->player_y));
}

void	all_position_next(sprite_t *sprite)
{
	position_junk(sprite);
	position_junk_bis(sprite);
	position_junk_tris(sprite);
	position_junk_quad (sprite);
	sfSprite_setPosition(sprite->delchior,
			(sfVector2f ) { (19) * SQUARE_SIZE,
		((12 * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->necklace,
			(sfVector2f ) { (19) * SQUARE_SIZE,
		((12 * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->title_cursor, (sfVector2f ) { 458, 455 });
	sfSprite_setOrigin(sprite->red_bar_m, (sfVector2f ) { 67, 0 });
	sfSprite_setOrigin(sprite->red_bar, (sfVector2f ) { 67, 0 });
	sfSprite_setOrigin(sprite->mob_bar_red, (sfVector2f ) { 67, 0 });
	sfSprite_setOrigin(sprite->mob_bar, (sfVector2f ) { 67, 0 });
}
