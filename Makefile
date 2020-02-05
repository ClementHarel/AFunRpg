##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_RPG
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c 					\
	./src/window.c					\
	./src/game_loop.c				\
	./src/create_text.c				\
	./src/player_movement.c				\
	./src/create_sprite.c				\
	./src/create_map.c				\
	./src/npc_dialogue.c				\
	./src/get_next_line.c				\
	./src/teleport.c				\
	./src/stringlibc.c				\
	./src/mill.c					\
	./src/name_choose.c				\
	./src/drawing_sprite.c				\
	./src/drawing_mask.c				\
	./src/cinematic.c				\
	./src/debog.c					\
	./src/init_npc_diag.c				\
	./src/my_getnbr.c				\
	./src/player_movement2.c			\
	./src/cinematic2.c				\
	./src/cinematic3.c				\
	./src/battle.c					\
	./src/menu.c					\
	./src/menu_text.c				\
	./src/menu2.c					\
	./src/submenu.c					\
	./src/all_position2.c				\
	./src/battle_ennemy.c				\
	./src/lvl_up.c					\
	./src/inventory.c				\
	./src/equipment.c				\
	./src/menu_text2.c				\
	./src/skills.c					\
	./src/shop.c					\
	./src/title_screen.c				\
	./src/skill_bis.c				\
	./src/junk.c					\
	./src/create_sprite_bis.c			\
	./src/junk_bis.c				\
	./src/equipment_bis.c				\
	./src/equipment_tris.c				\
	./src/junk_tris.c				\
	./src/battle_junk.c


OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

oui:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lc_graph_prog

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
