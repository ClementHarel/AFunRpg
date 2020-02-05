/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Create a Sprite
*/

#include "my.h"
#include "config.h"

void	create_allsprite_tris(sprite_t *sprite)
{
	create_everything(sprite);
	create_everything_bis(sprite);
	create_everything_tris(sprite);
	create_everyhting_quad(sprite);
	sprite->cursor_equipment = create_sprite
			("ressources/cursor_equipment.png", 0, sprite);
	sprite->inventory_menu = create_sprite
			("ressources/inventory.png", 0, sprite);
	sprite->skills = create_sprite
			("ressources/skills.png", 0, sprite);
	sprite->necklace = create_sprite
			("ressources/sprite/necklace.png", 0, sprite);
	change_dir(LEFT, sprite->battle_hero);
	change_dir(LEFT, sprite->battle_mourad);
	change_dir(RIGHT, sprite->ennemy_battle);
	change_dir(DOWN, sprite->npc11);
	change_dir(DOWN, sprite->npc_masque11);
}

void	create_all_sprite_bis(sprite_t *sprite)
{
	sprite->npc_masque3 = create_sprite
			("ressources/sprite/forgeron_masque.png", 1, sprite);
	sprite->npc4 = create_sprite("ressources/sprite/npc4.png", 1, sprite);
	sprite->npc_masque4
	= create_sprite("ressources/sprite/npc4_masque.png", 1,
			sprite);
	sprite->npc5 = create_sprite("ressources/sprite/npc5.png", 1, sprite);
	sprite->npc_masque5
	= create_sprite("ressources/sprite/npc5_masque.png", 1, sprite);
	sprite->dialogue = create_sprite("ressources/sprite/dialogue.png", 0,
			sprite);
	sprite->light = create_sprite("ressources/fog.png", 0, sprite);
	sprite->melgor = create_sprite
			("ressources/sprite/Melgor.png", 1, sprite);
	sprite->mob = create_sprite
			("ressources/sprite/mob.png", 1, sprite);
	sprite->fire = create_sprite
			("ressources/fire.png", 0, sprite);
	create_allsprite_tris(sprite);
}

void	create_all_sprite(sprite_t *sprite)
{
	sprite->is_animated = 0;
	sprite->player
	= create_sprite("ressources/sprite/player.png", 1, sprite);
	sprite->mill
	= create_sprite("ressources/tileset/moulin.png", 0, sprite);
	sprite->npc0
	= create_sprite("ressources/sprite/npc.png", 1, sprite);
	sprite->npc_masque0
	= create_sprite("ressources/sprite/npc_masque.png", 1, sprite);
	sprite->npc1
	= create_sprite("ressources/sprite/npc2.png", 1, sprite);
	sprite->npc_masque1
	= create_sprite("ressources/sprite/npc2_masque.png", 1, sprite);
	sprite->npc2 = create_sprite("ressources/sprite/npc3.png", 1, sprite);
	sprite->npc_masque2
	= create_sprite("ressources/sprite/npc3_masque.png", 1,
			sprite);
	sprite->npc3
	= create_sprite("ressources/sprite/forgeron.png", 1, sprite);
	create_all_sprite_bis(sprite);
}

void	update_sprite(char *str, sfSprite *sprite)
{
	sfTexture* tmp = sfTexture_createFromFile(str, NULL);

	sfSprite_setTexture(sprite, tmp, sfTrue);
}

sfSprite*	create_sprite(char *str, int spritesheet, sprite_t *sprite)
{
	sfTexture* tmp = sfTexture_createFromFile(str, NULL);
	sfSprite* new = sfSprite_create();

	sprite->player_rect.top = 0;
	sprite->player_rect.left = 0;
	if (my_strcmp(str, "ressources/fire.png") == 0)
		sprite->player_rect.width = 1280;
	else
		sprite->player_rect.width = SQUARE_SIZE;
	sprite->player_rect.height = NPC_HEIGHT;
	if (spritesheet == 2) {
		sprite->player_rect.height = SQUARE_SIZE;
		spritesheet--;
	}
	sfSprite_setTexture(new, tmp, sfTrue);
	if (spritesheet == 1)
		sfSprite_setTextureRect(new, sprite->player_rect);
	return (new);
}
