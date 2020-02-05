/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Include
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0

typedef struct {
	int*				npc_map;
	sfSprite*			white;
	sfSprite**			npc_sprite;
	sfSprite**			npc_masque;
	sfVideoMode			mode;
	sfRenderWindow*		render_window;
	sfWindow*			window;
	sfEvent				event;
	sfText*				text;
	sfText*				name;
	sfFont*				font;
	int*				npc_diag;
	int*				colision;
	int					player;
	int					text_on;
	int					repeat;
	int					fd;
	int					eof;
	int					intro;
	int					map_number;
	int					mob_killed;
	int					melgor_encounter;
	int					melgor_after_battle;
	int					oxydia_attack;
	int					player_x;
	int					player_y;
	int					dialogue_nb;
	int					dialogue_henro;
	int					block_forest;
	int					block_ottoman;
	int					debog;
	int					srandom;
	int					menu;
	int					menu_cursor;
	sfText*				player_name_menu;
	sfText*				player_health_menu;
	sfText*				player_mana_menu;
	sfText*				melgor_name_menu;
	sfText*				melgor_health_menu;
	sfText*				melgor_mana_menu;
	sfText*				lvl_menu;
	sfText*				m_lvl_menu;
	sfText*				dgt;
	sfText*				dgt_e;
	sfText*				money_menu;
	sfText*				location;
	sfText*				goal;
	sfText*				atk;
	sfText*				def;
	sfText*				short_sword;
	sfText*				long_sword_txt;
	sfText*				heavy_armor_txt;
	sfText*				nothing;
	sfText*				health_txt;
	sfText*				mana_txt;
	sfText*				heal_player;
	sfText*				heal_melgor;
	int					money;
	int					flags;
	int					melgor_turn;
	int					dgt_on;
	int					ennemy_turn;
	int					music1;
	int					music2;
	int					music3;
	int					equipment_menu;
	int					cursor_pos_equipment;
	int					cursor_pos_equipment2;
	int					weapon;
	int					armor;
	int					inventory_menu;
	int					health_potion;
	int					mana_potion;
	int					cursor_pos_inventory;
	int					use_item;
	int					skill_loop;
	int					skill_used;
	int					shop_loop;
	int					cursor_pos_shop;
	int					long_sword;
	int					heavy_armor;
	int					adv_armor;
	int					adv_sword;
	int					elendia_arrival;
	int					final_battle;
	int					cursor_title_pos;
	int					load;
	int					htp;
	int					quest_on;
}window_t;

typedef	struct {
		sfSprite*	mill;
		sfIntRect	mill_rect;
		sfIntRect	player_rect;
		sfSprite*	player;
		sfSprite*	melgor;
		sfSprite*	mob;
		sfSprite*	dialogue;
		sfIntRect	npc_rect;
		sfSprite*	npc0;
		sfSprite*	npc_masque0;
		sfSprite*	npc1;
		sfSprite*	npc_masque1;
		sfSprite*	npc2;
		sfSprite*	npc_masque2;
		sfSprite*	npc3;
		sfSprite*	npc_masque3;
		sfSprite*	npc4;
		sfSprite*	npc_masque4;
		sfSprite*	npc5;
		sfSprite*	npc_masque5;
		sfSprite*	npc6;
		sfSprite*	npc_masque6;
		sfSprite*	npc7;
		sfSprite*	npc_masque7;
		sfSprite*	npc8;
		sfSprite*	npc_masque8;
		sfSprite*	npc9;
		sfSprite*	npc_masque9;
		sfSprite*	npc10;
		sfSprite*	npc_masque10;
		sfSprite*	npc11;
		sfSprite*	npc_masque11;
		sfSprite*	npc12;
		sfSprite*	npc_masque12;
		sfSprite*	light;
		sfSprite*	fire;
		sfSprite*	map;
		sfSprite*	map_masque;
		sfSprite*	menu;
		sfSprite*	cursor;
		sfSprite*	hero_menu;
		sfSprite*	melgor_menu;
		sfSprite*	battleback;
		sfSprite*	battle_hero;
		sfSprite*	battle_mourad;
		sfSprite*	cursor_battle;
		sfSprite*	ennemy_battle;
		sfSprite*	hp_bar;
		sfSprite*	mp_bar;
		sfSprite*	red_bar;
		sfSprite*	blue_bar;
		sfSprite*	hp_bar_m;
		sfSprite*	mp_bar_m;
		sfSprite*	blue_bar_m;
		sfSprite*	red_bar_m;
		sfSprite*	mob_bar;
		sfSprite*	mob_bar_red;
		sfSprite*	equipment_menu;
		sfSprite*	cursor_equipment;
		sfSprite*	inventory_menu;
		sfSprite*	skills;
		sfSprite*	shop;
		sfSprite*	delchior;
		sfSprite*	title_screen;
		sfSprite*	title_cursor;
		sfSprite*	title_htp;
		sfSprite*	necklace;
		int			is_animated;
}sprite_t;

typedef struct {
	int			cursor_pos;
	int			battle_id;
	int			battle;
	char*		name;
	// Player Stats
	int			health;
	int			mana;
	int			max_health;
	int			max_mana;
	int			exp;
	int			lvl;
	int			attack;
	int			def;
	// Mourad Stats
	int			m_health;
	int			m_mana;
	int			m_max_health;
	int			m_max_mana;
	int			m_exp;
	int			m_lvl;
	int			lvl_up;
	int			m_attack;
	int			m_def;
	// Ennemy Stats
	int			e_health;
	int			e_attack;
	int			e_def;
	int			e_health_max;
	int			defend;
	int			m_defend;
	int			h_defend;

}player_t;

void			the_last_function(window_t *win,
		int new_val, int fd);
void			load_qua(window_t *win, int new_val, int fd);
void			load_tris(player_t *player, int new_val,
		window_t *win, int fd);
void			load_bis(player_t *player, int new_val, int fd);
void			save_tris(window_t *win, player_t *player, int fd);
void			save_bis(window_t *win, int fd);
void			drawing_forest(window_t *win, sprite_t *sprite);
void			drawing_oxydia(window_t *win, sprite_t *sprite);
void			update_lvl_m(char *lvl_mourad,
		player_t *player, int lvl_up_m);
void			update_lvl(char *lvl_hero, player_t *player,
		int lvl_up);
void			no_clue(window_t *win, sprite_t *sprite,
		player_t *player, float mana);
void			menu_draw(window_t *win, player_t *player,
		sprite_t *sprite, sfVector2f pos);
void			update_stat(char *health, char *mana,
		player_t *player);
void			init_player(window_t *win, player_t *player);
void			drawing_plzzz(window_t *win, sprite_t *sprite);
void			drawing_plz(window_t *win, sprite_t *sprite);
void			loopy_loop(window_t* win, player_t *player,
		sprite_t *sprite);
void			direction(window_t *win, sprite_t *sprite,
		int npc_position, int i);
void			loading(window_t* win,
		sprite_t* sprite, player_t* player);
float			get_float(int target, player_t *player,
		window_t *win);
void			controller_bis(window_t *win,
		player_t* player, sprite_t* sprite);
void			 controller(window_t *win,
		player_t *player, sprite_t *sprite);
void			dialogue_nb(window_t *win, int i,
		sprite_t *sprite);
void			fd_update(window_t* win, char* fd_string);
void			dialogue_update(window_t *win, int i ,
		sprite_t *sprite, player_t *player);
void			draw_battle_next(window_t *win, sprite_t *sprite);
void			battle_next(window_t *win, player_t *player,
		sprite_t *sprite, char *str);
void			sahakiann(window_t *win, int sahakian);
void			draw_battle(window_t* win, sprite_t *sprite);
void			game_over(player_t *player, window_t *win);
int				battle_tree(player_t *player, window_t *win,
		float dgt, sprite_t *sprite);
void			position_junk_bis(sprite_t *sprite);
void			position_junk_tris(sprite_t *sprite);
void			position_junk_quad(sprite_t *sprite);
void			position_junk(sprite_t *sprite);
void			event(window_t *win, player_t *player);
void			equi_loop(window_t *win, player_t *player);
void			equipment_text(window_t *win);
int				equipment_event(window_t *win);
int				equipment_event_bis(window_t *win);
void			equi_text(window_t *win);
int				equipment_event(window_t *win);
void			check_equip(window_t *win, player_t *player);
void			move_cursor_equip(window_t *win, player_t *player);
void			check_accessory(window_t *win, player_t *player);
void			check_armor(window_t *win, player_t *player);
void			check_weapon(window_t *win, player_t *player);
void			create_everyhting_quad(sprite_t *sprite);
void			non(sfColor color, window_t *win,
		int fd, sfText* text);
void			skill_junk(window_t *win);
void			battle_junk(window_t *win, player_t *player,
		sprite_t *sprite);
int				can_use_bis(int skill, int mana);
int				my_nbrlen(int nbr);
void			init_win(window_t *win);
void			create_everyhting_quad(sprite_t *sprite);
void			create_everything_tris(sprite_t *sprite);
void			create_everything(sprite_t *sprite);
void			create_everything_bis(sprite_t *sprite);
void			oui(sprite_t *sprite, window_t *win);
void			item_use(window_t* win, player_t* player);
void			healing(int sahakian,
		window_t* win, player_t* player);
void			thunderbolt(window_t* win,
		sprite_t* sprite, player_t* player);
void			quickslash(window_t* win,
		sprite_t* sprite, player_t* player);
void			tornado(window_t* win,
		sprite_t* sprite, player_t* player,
		int sahakian);
float			get_damage(player_t* player,
		window_t* win);
void			load(window_t* win, player_t* player,
		sprite_t* sprite);
int				title_screen(window_t* win,
		sprite_t* sprite, player_t* player);
void			ending(window_t* win,
		sprite_t* sprite, player_t* player);
void			final_battle(window_t* win,
		sprite_t* sprite, player_t* player);
void			elendia_arrival(window_t* win,
		sprite_t *sprite, player_t* player);
void			shop_loop(window_t* win, sprite_t* sprite);
void			draw_elendia(window_t* win, sprite_t* sprite);
void			skill_event(window_t* win, player_t* player);
void			skills(window_t* win, player_t* player);
void			skills_loop(window_t* win,
		sprite_t* sprite, player_t* player);
void			event_inventory(window_t* win, player_t* player);
void			text_create_inv(window_t* win);
void			inventory_loop(window_t* win,
		sprite_t* sprite, player_t* player);
void			get_stats_player(window_t *win,
		player_t *player);
void			equipment_loop(window_t* win,
		sprite_t* sprite, player_t* player);
void			inventory(window_t* win);
void			equipment(window_t* win);
void			lvl_up(player_t* player);
void			anim_dgt(window_t* win, int dgt);
void			anim_turn(sprite_t* sprite, window_t* win);
void			ennemy_turn(player_t* player,
		sprite_t* sprite, window_t* win);
void			battle_loop(player_t* player,
		window_t* win, sprite_t* sprite);
void			get_lvl(player_t* player, window_t* win);
void			all_position_next(sprite_t *sprite);
void			get_goal(window_t* win);
void			submenu(window_t* win, sprite_t* sprite,
		player_t* player);
void			get_location(window_t* win);
void			get_money(window_t* win);
void			melgor_menu(window_t* win, sprite_t* sprite,
		player_t* player);
void			text_create(window_t* win, player_t* player);
void			menu_loop(window_t* win, sprite_t* sprite,
		player_t* player);
void			menu_move_cursor(window_t* win,
		sprite_t* sprite, player_t* player);
void			menu(window_t* win, player_t* player);
void			battle(player_t *player, sprite_t* sprite,
		window_t* win);
void			attack_oxydia(window_t* win,
		sprite_t* sprite, player_t* player);
void			melgor_after_battle(window_t* win,
		sprite_t* sprite, player_t* player);
void			melgor_encounter(window_t* win,
		sprite_t* sprite, player_t* player);
void			block_forest(window_t *win,
		sprite_t *sprite, player_t *player);
void			block_ottoman(window_t *win,
		sprite_t *sprite, player_t *player);
void			draw_map_four(window_t *win, sprite_t *sprite);
void			player_movement_loop(window_t *win,
		sprite_t *sprite);
void			main_loop(window_t *win, sprite_t *sprite,
				player_t *player, int i);
void			create_all_sprite(sprite_t* sprite);
void			cinematic_npc(int i, window_t* win);
void			init_npc_diag(window_t* win, sprite_t* sprite);
void			change_dir(int value, sfSprite* sprite);
void			debog(window_t* win, sprite_t* sprite);
void			new_map(sprite_t* sprite,
		window_t* win, int x, int y);
void			cinematic(window_t* win, sprite_t*
		sprite, player_t* player);
void			draw_map_three(window_t* win, sprite_t* sprite);
void			draw_map_two(window_t* win, sprite_t* sprite);
void			draw_map_one(window_t* win, sprite_t* sprite);
void			draw_map_one_m(window_t* win, sprite_t* sprite);
void			draw_map_two_m(window_t* win, sprite_t* sprite);
void			draw_map_three_m(window_t* win, sprite_t* sprite);
void			change_direction(sprite_t *sprite, int value);
void			dialogue(window_t* win, sprite_t* sprite, player_t*
				player, int i);
void			change_dir(int value, sfSprite* sprite);
void    		create_text(sfVector2f position,
		window_t* win, char *font);
void			game_setup(window_t* win, sprite_t* sprite);
void			new_window(window_t* win);
void    		update_text(char *string, window_t* win);
void			text(window_t* win, sprite_t* sprite,
		player_t* player);
void			create_map(sprite_t* sprite, window_t* win);
void			game_loop(window_t* win, sprite_t*
		sprite, player_t* player);
void			player_movement(window_t* win,
		sprite_t* sprite, player_t*
				player);
void			my_strncpy(char* vala, char* valb, int size);
void			mill_move(sprite_t* sprite);
void			generate_colision(window_t* win);
void			update_sprite(char* str, sfSprite* sprite);
void    		fade(window_t* win);
void			teleport(window_t* win, sprite_t* sprite);
int				cinematic_bis(window_t* win,
		sprite_t* sprite, player_t*
				player, int i);
int				collide_next(window_t *win, int value,
				int temp_value, sprite_t *sprite);
int				intro(window_t *win, int  i, sprite_t
		*sprite, player_t *player);
int				my_getnbr(char const *str);
int				choose_name(window_t* win, player_t* player);
int				my_strcmp(char* stra, char* strb);
int				my_strlen(char* str);
int				collide(window_t *win, sprite_t *sprite);
int				my_putstr(char *str);
int				my_nbrlen(int nbr);
char*			my_strdup(char* str);
char*			get_next_line(int fd);
sfVector2f		player_loop(sfVector2f position,
		int value, sprite_t *sprite);
sfSprite*		create_sprite(char* str, int
		spritesheet, sprite_t* sprite);
