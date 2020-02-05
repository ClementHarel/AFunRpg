/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Create_MAP
*/

#include "my.h"
#include "config.h"

void	all_position_bis(sprite_t *sprite)
{
	sfSprite_setPosition(sprite->npc3, (sfVector2f )
			{NPC3_X * SQUARE_SIZE, ((NPC3_Y * SQUARE_SIZE) - 16)});
	sfSprite_setPosition(sprite->npc_masque3,
			(sfVector2f ) { NPC3_X * SQUARE_SIZE,
		((NPC3_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc4,
			(sfVector2f ) { NPC4_X * SQUARE_SIZE,
		((NPC4_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc_masque4,
			(sfVector2f ) { NPC4_X * SQUARE_SIZE,
		((NPC4_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc5,
			(sfVector2f ) { NPC5_X * SQUARE_SIZE,
		((NPC5_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc_masque5,
			(sfVector2f ) { NPC5_X * SQUARE_SIZE,
		((NPC5_Y * SQUARE_SIZE) - 16) });
	all_position_next(sprite);
}

void	all_position(sprite_t *sprite)
{
	sfSprite_setPosition(sprite->npc0,
			(sfVector2f ) { NPC0_X * SQUARE_SIZE,
		((NPC0_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc_masque0,
			(sfVector2f ) { NPC0_X * SQUARE_SIZE,
		((NPC0_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc1,
			(sfVector2f ) { NPC1_X * SQUARE_SIZE,
		((NPC1_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc_masque1,
			(sfVector2f ) { NPC1_X * SQUARE_SIZE,
		((NPC1_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc2,
			(sfVector2f ) { NPC2_X * SQUARE_SIZE,
		((NPC2_Y * SQUARE_SIZE) - 16) });
	sfSprite_setPosition(sprite->npc_masque2,
			(sfVector2f ) { NPC2_X * SQUARE_SIZE,
		((NPC2_Y * SQUARE_SIZE) - 16) });
	all_position_bis(sprite);
}

void	set_position(window_t *win, sprite_t *sprite)
{
	create_text((sfVector2f ) { 190, 535 }, win, FONT);
	update_sprite("ressources/tileset/0.png", sprite->map);
	update_sprite("ressources/tileset/0m.png", sprite->map_masque);
	sfSprite_setPosition(sprite->dialogue, (sfVector2f ) { 50, 325 });
	all_position(sprite);
	change_dir(DOWN, sprite->npc3);
	change_dir(DOWN, sprite->npc_masque3);
	change_dir(LEFT, sprite->npc5);
	change_dir(LEFT, sprite->npc_masque5);
	change_dir(RIGHT, sprite->npc4);
	change_dir(RIGHT, sprite->npc_masque4);
	change_dir(LEFT, sprite->npc_masque6);
	change_dir(RIGHT, sprite->npc_masque7);
	change_dir(RIGHT, sprite->melgor);
	change_dir(LEFT, sprite->mob);
	sfSprite_setPosition(sprite->player,
			(sfVector2f ) { 3 * SQUARE_SIZE,
		(5 * SQUARE_SIZE) - 16 });
	sfSprite_setPosition(sprite->mill, (sfVector2f )
			{ 466 + 150, 75 + 150 });
}

void	generate_colision(window_t *win)
{
	int i = 0;
	char buffer[1] = "0";
	char string[23] = "ressources/collision/?";
	int fd;

	win->block_forest = 0;
	string[21] = win->map_number + '0';
	string[22] = '\0';
	fd = open(string, O_RDONLY);
	win->colision = malloc(sizeof(int) * (MAP_X * MAP_Y));
	while (i < (MAP_X * MAP_Y)) {
		read(fd, buffer, 1);
		if (buffer[0] == '\n')
			read(fd, buffer, 1);
		win->colision[i] = buffer[0] - '0';
		i++;
	}
}

void	create_map(sprite_t *sprite, window_t *win)
{
	sprite->map = create_sprite("ressources/tileset/0.png", 0, sprite);
	sprite->map_masque = create_sprite
			("ressources/tileset/0m.png", 0, sprite);
	set_position(win, sprite);
}
