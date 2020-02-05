/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Menu all text creation
*/

#include "my.h"
#include "config.h"

void	text_create_goal(window_t *win)
{
	sfColor color = {255, 100, 0, 255};
	sfVector2f position = { 850, 75};
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	win->goal = sfText_create();
	win->atk = sfText_create();
	win->def = sfText_create();
	win->short_sword = sfText_create();
	win->heavy_armor_txt = sfText_create();
	win->long_sword_txt = sfText_create();
	win->nothing = sfText_create();
	sfText_setFont(win->goal, font);
	sfText_setPosition(win->goal, position);
	sfText_setColor(win->goal, color);
	color.g = 255;
	color.b = 255;
	sfText_setColor(win->lvl_menu, color);
	sfText_setColor(win->m_lvl_menu, color);
	win->dgt = sfText_create();
	text_create_inv(win);
}

void	text_create_money(window_t *win)
{
	sfColor color = {255, 100, 0, 255};
	sfVector2f position = { 988, 610};
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	win->money_menu = sfText_create();
	sfText_setFont(win->money_menu, font);
	sfText_setCharacterSize(win->money_menu, TEXT_SIZE + 20);
	sfText_setPosition(win->money_menu, position);
	sfText_setColor(win->money_menu, color);
	win->location = sfText_create();
	sfText_setFont(win->location, font);
	sfText_setCharacterSize(win->location, TEXT_SIZE + 20);
	position.y -= 5;
	position.x -= 630;
	sfText_setPosition(win->location, position);
	sfText_setColor(win->location, color);
	win->goal = sfText_create();
	win->lvl_menu = sfText_create();
	win->m_lvl_menu = sfText_create();
	text_create_goal(win);
}

void	text_create_next_next(window_t *win)
{
	sfColor color = {255, 0, 0, 255};
	sfVector2f position = { 175 + 50, 200 + 45 + 175};

	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");
	win->melgor_health_menu = sfText_create();
	sfText_setFont(win->melgor_health_menu, font);
	sfText_setCharacterSize(win->melgor_health_menu, TEXT_SIZE);
	sfText_setPosition(win->melgor_health_menu, position);
	sfText_setString(win->melgor_health_menu, "HP oui / oui");
	sfText_setColor(win->melgor_health_menu, color);
	color.r = 0;
	color.b = 255;
	win->melgor_mana_menu = sfText_create();
	position.x += 300;
	sfText_setFont(win->melgor_mana_menu, font);
	sfText_setCharacterSize(win->melgor_mana_menu, TEXT_SIZE);
	sfText_setPosition(win->melgor_mana_menu, position);
	sfText_setColor(win->melgor_mana_menu, color);
	sfText_setString(win->melgor_mana_menu, "MP : oui / oui");
	text_create_money(win);
}

void	text_create_next(window_t *win)
{
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	win->player_mana_menu = sfText_create();
	sfText_setFont(win->player_mana_menu, font);
	sfText_setCharacterSize(win->player_mana_menu, TEXT_SIZE);
	sfText_setColor(win->player_mana_menu, (sfColor){0, 0, 255, 255});
	sfText_setPosition(win->player_mana_menu, (sfVector2f) {525, 245});
	win->melgor_name_menu = sfText_create();
	sfText_setFont(win->melgor_name_menu, font);
	sfText_setCharacterSize(win->melgor_name_menu, TEXT_SIZE );
	sfText_setColor(win->melgor_name_menu, (sfColor){255, 100, 0, 255});
	sfText_setPosition(win->melgor_name_menu, (sfVector2f) {175, 370});
	sfText_setString(win->melgor_name_menu, "Melgor");
	text_create_next_next(win);
}

void	text_create(window_t *win, player_t *player)
{
	sfColor color = {255, 100, 0, 255};
	sfVector2f position = { 175, 200};
	sfFont *font = sfFont_createFromFile("ressources/font/aachenn.ttf");

	win->player_name_menu = sfText_create();
	sfText_setFont(win->player_name_menu, font);
	sfText_setCharacterSize(win->player_name_menu, TEXT_SIZE );
	sfText_setColor(win->player_name_menu, color);
	sfText_setPosition(win->player_name_menu, position);
	sfText_setString(win->player_name_menu, player->name);
	win->player_health_menu = sfText_create();
	sfText_setFont(win->player_health_menu, font);
	sfText_setCharacterSize(win->player_health_menu, TEXT_SIZE);
	color.r = 255;
	color.g = 0;
	sfText_setColor(win->player_health_menu, color);
	position.x += 50;
	position.y += 45;
	sfText_setPosition(win->player_health_menu, position);
	text_create_next(win);
}
