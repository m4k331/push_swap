# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/04/11 16:31:32 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PW			=	push_swap
NAME_CR			=	checker

# colors

BLACK			=	'\033[0;30m'
RED				=	'\033[0;31m'
GREEN			=	'\033[0;32m'
YELLOW			=	'\033[0;33m'
BLUE			=	'\033[0;34m'
MAGENTA			=	'\033[0;35m'
CYAN			=	'\033[0;36m'
GRAY			=	'\033[0;37m'

# bold color

DGRAY			=	'\033[1;30m'
LRED			=	'\033[1;31m'
LGREEN			=	'\033[1;32m'
LYELLOW			=	'\033[1;33m'
LBLUE			=	'\033[1;34m'
LMAGENTA		=	'\033[1;35m'
LCYAN			=	'\033[1;36m'
WHITE			=	'\033[1;37m'

# name files

PW				=	bt_sort.c \
					index_stack.c \
					push_swap.c \
					median.c \
					modify.c \
					partition_a.c \
					partition_b.c \
					rule_papb.c \
					rule_rarra_rbrrb.c \
					rule_rr.c \
					rule_rrr.c \
					rule_ss.c \
					sort.c \
					throw_ins.c 

CO				=	elem_ins.c \
					fill_stack.c \
					parse_flags.c \
					parse_nums.c \
					stack_ins.c \
					utils_ps.c \
					utils_stack.c \
					utils_checkers.c

CR				=	bottom.c \
					center_p1.c \
					center_p2.c \
					checker.c \
					clip_bgn.c \
					clip_end.c \
					color.c \
					draw_line.c \
					draw_slant_line.c \
					draw_square.c \
					draw_straight_line.c \
					fill_ins.c \
					image.c \
					left_bottom.c \
					left_p1.c \
					left_p2.c \
					left_top.c \
					parse_ins.c \
					top.c \
					utils_draw_line.c \
					vector_colors.c \
					draw_stacks.c \
					keys.c \
					ins_vsr.c \
					apply_ins.c \
					utils_vsr.c \
					panel.c \
					run_mods.c \
					rev_apply_ins.c \
					utils_checker.c \
					window.c 

# flags && compile

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -c -g

# mlx library

MLX				=	./minilibx/
MLX_LIB			=	$(MLX)mlx.a
MLX_INC			=	-I $(MLX)
MLX_LNK			=	-L $(MLX) -l mlx -framework OpenGL -framework AppKit

# ft library
 
FT				=	./libft/
FT_LIB			=	$(FT)libft.a
FT_INC			=	-I $(FT)includes/
FT_LNK			=	-L $(FT) -l ft

# dir

OBJ_DIR_PW		=	./obj_pw/
OBJ_DIR_CR		=	./obj_cr/
OBJ_DIR_CO		=	./obj_co/

SRC_DIR_PW		=	./src_pw/
SRC_DIR_CR		=	./src_cr/
SRC_DIR_CO		=	./src_co/

# all files

HEADER			=	stack.h

OBJ_PW			=	$(addprefix $(OBJ_DIR_PW), $(PW:%.c=%.o))
OBJ_CR			=	$(addprefix $(OBJ_DIR_CR), $(CR:%.c=%.o))
OBJ_CO			=	$(addprefix $(OBJ_DIR_CO), $(CO:%.c=%.o))

SRC_PW			=	$(addprefix $(SRC_DIR_PW), $(PW))
SRC_CR			=	$(addprefix $(SRC_DIR_CR), $(CR))
SRC_CO			=	$(addprefix $(SRC_DIR_CO), $(CO))

# exceptions

.PHONY:				all clean fclean re

all: $(NAME_PW) $(NAME_CR)

$(FT_LIB):
	make -C $(FT) >> /dev/null
	@echo $(GREEN)"compile libft!"$(DGRAY)

$(MLX_LIB):
	make -C $(MLX) >> /dev/null
	@echo $(GREEN)"compile libmlx!"$(DGRAY)

obj_pw:
	mkdir -p $(OBJ_DIR_PW)
	@echo $(CYAN)"create dir "$(WHITE)$(OBJ_DIR_PW)$(DGRAY)

obj_cr:
	mkdir -p $(OBJ_DIR_CR)
	@echo $(CYAN)"create dir "$(WHITE)$(OBJ_DIR_CR)$(DGRAY)

obj_co:
	mkdir -p $(OBJ_DIR_CO)
	@echo $(CYAN)"create dir "$(WHITE)$(OBJ_DIR_CO)$(DGRAY)

$(OBJ_DIR_CO)%.o:$(SRC_DIR_CO)%.c
	$(CC) $(CFLAGS) -I. $(FT_INC) -o $@ -c $<

$(OBJ_DIR_PW)%.o:$(SRC_DIR_PW)%.c
	$(CC) $(CFLAGS) -I. $(FT_INC) -o $@ -c $<
	@echo $(YELLOW)"create obj files push_swap"$(DGRAY)

$(OBJ_DIR_CR)%.o:$(SRC_DIR_CR)%.c
	$(CC) $(CFLAGS) -I. $(FT_INC) $(MLX_INC) -o $@ -c $<
	@echo $(YELLOW)"create obj files checker"$(DGRAY)

$(NAME_PW): obj_co obj_pw $(FT_LIB) $(OBJ_CO) $(OBJ_PW)
	$(CC) $(OBJ_CO) $(OBJ_PW) $(FT_LNK) -o $(NAME_PW) 
	@echo $(LMAGENTA)"push_swap - ready!"$(DGRAY)

$(NAME_CR): obj_co obj_cr $(FT_LIB) $(MLX_LIB) $(OBJ_CO) $(OBJ_CR)
	$(CC) $(OBJ_CO) $(OBJ_CR) $(FT_LNK) $(MLX_LNK) -o $(NAME_CR) 
	@echo $(LMAGENTA)"cheker - ready!"$(DGRAY)

norm:
	@echo $(GREEN)"cheking is norminette:"$(DGRAY)
	@norminette $(HEADER) $(SRC_CO) $(SRC_PW) $(SRC_CR)

clean:
	@echo $(LRED)"clean!"$(DGRAY)
	make -C $(MLX) clean >> /dev/null
	make -C $(FT) clean >> /dev/null
	rm -rf $(OBJ_DIR_CO) $(OBJ_DIR_PW) $(OBJ_DIR_CR)
	@echo $(RED)"deleted directories: "$(WHITE) $(OBJ_DIR_CO) $(OBJ_DIR_PW) \
												$(OBJ_DIR_CR) $(DGRAY)

fclean: clean
	@echo $(LRED)"all clean!"$(DGRAY)
	make -C $(FT) fclean >> /dev/null
	rm -f $(NAME_PW) $(NAME_CR)

re: fclean all

horde:
	@echo $(RED)"\n\
                                   ########                                  \n\
                               #######  ######                               \n\
                            ######         ######                            \n\
                         ######               ######                         \n\
                #####  #####                     ###### #####                \n\
               ### ######                           ##########               \n\
              ###                                           ###              \n\
              ###                                            ##              \n\
             ###                                             ###             \n\
           ####                                               ####           \n\
          ###                   #############                   ####         \n\
        ####                 ######        #####                  ####       \n\
      ####                 ####               #####                ####      \n\
    ####                 ####                   ####                 ####    \n\
   ###                  ###         #####         ###                  ###   \n\
   ###                 ###        #########        ###                 ###   \n\
    ####              ###        ###     ####       ###              ####    \n\
      ####            ###      ####        ###       ##             ###      \n\
       ####           ##      ###           ####     ##           ####       \n\
         ####         ##     ###              ##     ##          ###       # \n\
######    ####        ###    ###             ###     ##        ####    ######\n\
 #############        ###     ###           ###      ##        ##############\n\
 ###    ######         ##      ###         ###      ###        #######   ### \n\
  ###                  ###      ####     ####      ###                  ###  \n\
   ###                  ###       #### #####      ###                  ###   \n\
    ###                  ###        ######       ###                  ###    \n\
     ###                  ###                   ###                  ###     \n\
      ###     ######       ###                 ###       ######     ###      \n\
       ###############      ###               ###      ###############       \n\
                    ###      ###             ###      ####        #          \n\
                     ###      ###            ##      ###                     \n\
                      ###      ##           ###     ###                      \n\
                       ###     ###         ###     ###                       \n\
                        ##      ##         ##     ###                        \n\
                        ###     ###       ###     ##                         \n\
                         ##      ##       ###    ###                         \n\
                         ##      ##       ##     ###                         \n\
                         ###     ###     ###      #######                    \n\
                         ###     ###     ###          ###                    \n\
                    ########     ###     ###         ###                     \n\
                    #######       ##     ###         ##                      \n\
                     ##           ##     ###        ###                      \n\
                     ###         ###     ###       ###                       \n\
                      ###        ###      ##      ###                        \n\
                       ###       ##       ###    ###                         \n\
                        ###      ##        ##   ###                          \n\
                         ###     ##        ### ###                           \n\
                          ###   ###         #####                            \n\
                           ###  ##           ###                             \n\
                            ######                                           \n\
                             ####                                            \n\
"$(DGRAY)

