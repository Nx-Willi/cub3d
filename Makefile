# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 16:13:46 by wdebotte          #+#    #+#              #
#    Updated: 2022/08/27 15:58:08 by xle-baux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# => TEXT
################################################################################

END		= \033[0m
BOLD	= \033[1m

RED		= \033[91m
GREEN	= \033[92m
YELLOW	= \033[93m
CYAN	= \033[96m

################################################################################
# => VARIABLES
################################################################################

NAME		= cub3D

PATHSRCS	= srcs/
PATHHEADERS	= includes/
PATHLIBS	= libs/
PATHLIBFT	= ${PATHLIBS}libft/
PATHMLX		= ${PATHLIBS}minilibx/
PATHNULL	= /dev/null

COMMON_SRCS	= $(addprefix ${PATHSRCS}, main.c \
								handler_hooks.c) \
			$(addprefix ${PATHSRCS}parser/, parser.c check_infos.c is_info.c \
								get_infos.c get_map.c check_map.c \
								parser_tools_1.c parser_tools_2.c \
								tab_char_to_int.c tmp_parser_tools.c) \
			$(addprefix ${PATHSRCS}utils/, exit.c file.c free_stuff.c \
								ft_split_piscine.c my_mlx_pixel_put.c \
								get_tab_infos.c is_coordinate_in_map.c) \
			$(addprefix ${PATHSRCS}raycast/, raycast.c draw_map.c)

MAND_SRCS	= $(addprefix ${PATHSRCS}raycast/, initialize.c movements.c) \
			$(addprefix ${PATHSRCS}, init_main.c)

BONUS_SRCS	= $(addprefix ${PATHSRCS}bonus/, initialize_bonus.c \
								movements_bonus.c movements_utils_bonus.c \
								init_main_bonus.c minimap_bonus.c)

OBJS		= ${COMMON_SRCS:.c=.o}
OBJS_MAND	= ${MAND_SRCS:.c=.o}
OBJS_BONUS	= ${BONUS_SRCS:.c=.o}
HEADERS		= ${PATHHEADERS}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
INCS		= -I${PATHHEADERS} -I${PATHLIBFT}${PATHHEADERS} \
			-I${PATHLIBS}minilibx

RM			= rm -rf
MAKE		= make -C
NORM		= norminette

LIBFT		= -L${PATHLIBFT} -lft
MLX			= -L${PATHMLX} -lmlx -lXext -lX11
MATH		= -lm
LIBS		= ${LIBFT} ${MLX} ${MATH}

################################################################################
# => RULES
################################################################################

.c.o:
				@echo "${BOLD}${YELLOW}Compiling:${END}\t$<"
				@${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o} >${PATHNULL}

all:		libs ${NAME}

libs:
				@echo "${BOLD}${GREEN}Building:${END}\tlibft.a"
				@${MAKE} ${PATHLIBFT} >${PATHNULL}
				@echo "${BOLD}${GREEN}Building:${END}\tminilibx"
				@${MAKE} ${PATHMLX} >${PATHNULL} 2>${PATHNULL}

${NAME}:	${OBJS} ${OBJS_MAND}
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@${CC} ${OBJS} ${OBJS_MAND} ${INCS} ${LIBS} -o ${NAME}\
					>${PATHNULL}

bonus:		libs ${OBJS} ${OBJS_BONUS}
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@${CC} ${OBJS} ${OBJS_BONUS} ${INCS} ${LIBS} -o ${NAME}\
					>${PATHNULL}

clean:
				@echo "${BOLD}${RED}Removing:${END}\tAll .o files"
				@${RM} ${OBJS} ${OBJS_MAND} ${OBJS_BONUS} >${PATHNULL}

fclean:		clean
				@${MAKE} ${PATHLIBFT} fclean >${PATHNULL}
				@echo "${BOLD}${RED}Removing:${END}\tMinilibx"
				@${MAKE} ${PATHMLX} clean >${PATHNULL}
				@echo "${BOLD}${RED}Removing:${END}\t${NAME}"
				@${RM} ${NAME} >${PATHNULL}

norminette:
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .c files"
				${NORM} ${COMMON_SRCS} ${MAND_SRCS} ${BONUS_SRCS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !\n"
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .h files"
				${NORM} ${HEADERS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !"

re:			fclean all

.PHONY:		all clean fclean re norminette bonus libs

################################################################################
