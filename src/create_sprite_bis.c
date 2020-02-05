/*
** EPITECH PROJECT, 2018
** Create Sprite next
** File description:
** My RPG
*/

#include "my.h"
#include "config.h"

void	create_everyhting_quad(sprite_t *sprite)
{
	sprite->npc11
	= create_sprite("ressources/sprite/npc11.png", 1, sprite);
	sprite->npc_masque11
	= create_sprite("ressources/sprite/npc11_masque.png", 1, sprite);
	sprite->npc12
	= create_sprite("ressources/sprite/npc12.png", 1, sprite);
	sprite->npc_masque12
	= create_sprite("ressources/sprite/npc12_masque.png", 1, sprite);
	sprite->shop
	= create_sprite("ressources/shop.png", 0, sprite);
	sprite->delchior
	= create_sprite("ressources/sprite/delchior.png", 1, sprite);
	sprite->title_screen
	= create_sprite("ressources/title.png", 0, sprite);
	sprite->title_cursor
	= create_sprite("ressources/title_cursor.png", 0, sprite);
	sprite->title_htp
	= create_sprite("ressources/title_htp.png", 0, sprite);
	change_dir(LEFT, sprite->npc6);
	change_dir(RIGHT, sprite->npc7);
}

void	create_everything_tris(sprite_t *sprite)
{
	sprite->npc6
	= create_sprite("ressources/sprite/npc6.png", 1, sprite);
	sprite->npc_masque6
	= create_sprite("ressources/sprite/npc6_masque.png", 1, sprite);
	sprite->npc7
	= create_sprite("ressources/sprite/npc7.png", 1, sprite);
	sprite->npc_masque7
	= create_sprite("ressources/sprite/npc7_masque.png", 1, sprite);
	sprite->npc8
	= create_sprite("ressources/sprite/npc8.png", 1, sprite);
	sprite->npc_masque8
	= create_sprite("ressources/sprite/npc8_masque.png", 1, sprite);
	sprite->npc9
	= create_sprite("ressources/sprite/npc9.png", 1, sprite);
	sprite->npc_masque9
	= create_sprite("ressources/sprite/npc9_masque.png", 1, sprite);
	sprite->npc10
	= create_sprite("ressources/sprite/npc10.png", 1, sprite);
	sprite->npc_masque10
	= create_sprite("ressources/sprite/npc10_masque.png", 1, sprite);
}

void	create_everything_bis(sprite_t *sprite)
{
	sprite->mp_bar = create_sprite
			("ressources/battle/bar.png", 0, sprite);
	sprite->hp_bar_m = create_sprite
			("ressources/battle/bar.png", 0, sprite);
	sprite->mp_bar_m = create_sprite
			("ressources/battle/bar.png", 0, sprite);
	sprite->red_bar = create_sprite
			("ressources/battle/health.png", 0, sprite);
	sprite->blue_bar = create_sprite
			("ressources/battle/mana.png", 0, sprite);
	sprite->red_bar_m = create_sprite
			("ressources/battle/health.png", 0, sprite);
	sprite->blue_bar_m = create_sprite
			("ressources/battle/mana.png", 0, sprite);
	sprite->mob_bar = create_sprite
			("ressources/battle/bar.png", 0, sprite);
	sprite->mob_bar_red = create_sprite
			("ressources/battle/health.png", 0, sprite);
	sprite->equipment_menu = create_sprite
			("ressources/equipment.png", 0, sprite);
}

void	create_everything(sprite_t *sprite)
{
	sprite->menu = create_sprite
			("ressources/tileset/menu.png", 0, sprite);
	sprite->cursor = create_sprite
			("ressources/cursor.png", 0, sprite);
	sprite->hero_menu
	= create_sprite("ressources/sprite/player.png", 1, sprite);
	sprite->melgor_menu = create_sprite
			("ressources/sprite/Melgor.png", 1, sprite);
	sprite->battleback = create_sprite
			("ressources/battle/Battleback.png", 0, sprite);
	sprite->battle_hero = create_sprite
			("ressources/sprite/player.png", 1, sprite);
	sprite->battle_mourad = create_sprite
			("ressources/sprite/Melgor.png", 1, sprite);
	sprite->cursor_battle = create_sprite
			("ressources/battle/cursor.png", 0, sprite);
	sprite->ennemy_battle = create_sprite
			("ressources/battle/0.png", 1, sprite);
	sprite->hp_bar = create_sprite
			("ressources/battle/bar.png", 0, sprite);
}
