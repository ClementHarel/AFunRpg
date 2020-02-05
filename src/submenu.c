/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Submenu
*/

#include "my.h"
#include "config.h"

void	load_loop(int fd, char *big_buff)
{
	char buffer[1] = "o";
	int i = 0;

	while (buffer[0] != '\n') {
		read(fd, buffer, 1);
		big_buff[i] = buffer[0];
		i++;
	}
	big_buff[i - 1] = '\0';
}

void	load(window_t *win, player_t *player, sprite_t *sprite)
{
	int fd = open("save/Save.data", O_RDWR | S_IRUSR | S_IWUSR);
	char big_buff[9] = "________";
	int new_val;

	if (fd < 0)
		return;
	load_loop(fd, big_buff);
	player->name = my_strdup(big_buff);
	load_bis(player, new_val, fd);
	load_tris(player, new_val, win, fd);
	the_last_function(win, new_val, fd);
	read(fd, &new_val, sizeof(new_val));
	win->adv_sword = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->elendia_arrival = new_val;
	read(fd, &new_val, sizeof(new_val));
	win->quest_on = new_val;
	new_map(sprite, win, win->player_x * SQUARE_SIZE,
			win->player_y * SQUARE_SIZE - 16);
	win->menu = FALSE;
}

void	save(window_t *win, player_t *player)
{
	int fd = open("save/Save.data", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

	write(fd, player->name, my_strlen(player->name));
	write(fd, "\n", 1);
	write(fd, &player->health, sizeof(player->health));
	write(fd, &player->mana, sizeof(player->mana));
	write(fd, &player->max_health, sizeof(player->max_health));
	write(fd, &player->max_mana, sizeof(player->max_mana));
	write(fd, &player->exp, sizeof(player->exp));
	write(fd, &player->lvl, sizeof(player->lvl));
	write(fd, &player->attack, sizeof(player->attack));
	write(fd, &player->def, sizeof(player->def));
	write(fd, &player->m_mana, sizeof(player->m_mana));
	save_tris(win, player, fd);
	save_bis(win, fd);
	win->menu = FALSE;
	close(fd);
}

void	get_lvl(player_t *player, window_t *win)
{
	char lvl_hero[28] = "Lvl : ??  -   Exp ??? / ???\0";
	char lvl_mourad[28] = "Lvl : ??  -   Exp ??? / ???\0";
	int lvl_up = 10 * (player->lvl * 2) + player->lvl + 2;
	int lvl_up_m = 10 * (player->m_lvl *2) + player->m_lvl + 2;

	update_lvl(lvl_hero, player, lvl_up);
	update_lvl_m(lvl_mourad, player, lvl_up_m);
	sfText_setString(win->lvl_menu, lvl_hero);
	sfText_setString(win->m_lvl_menu, lvl_mourad);
}

void	submenu(window_t *win, sprite_t *sprite, player_t *player)
{
	switch (win->menu_cursor) {
	case (0):
		inventory(win);
		break;
	case (1):
		equipment(win);
		break;
	case (2):
		save(win, player);
		break;
	case (3):
		load(win, player, sprite);
		break;
	case (4):
		sfRenderWindow_close(win->render_window);
	break;
	}
}
