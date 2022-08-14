# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 16:13:46 by wdebotte          #+#    #+#              #
#    Updated: 2022/08/13 13:40:29 by xle-baux         ###   ########.fr        #
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

SRCS		= $(addprefix ${PATHSRCS}, main.c minimap.c xlb_raycasting.c) \
			$(addprefix ${PATHSRCS}parser/, parser.c check_infos.c is_info.c \
								get_infos.c get_map.c check_map.c \
								parser_tools_1.c parser_tools_2.c \
								tab_char_to_int.c tmp_parser_tools.c) \
			$(addprefix ${PATHSRCS}utils/, exit.c file.c free_stuff.c \
								ft_split_piscine.c) \
			$(addprefix ${PATHSRCS}hooks/, handler_hooks.c) \
#			$(addprefix ${PATHSRCS}raycast/, raycastlodev.c)

OBJS		= ${SRCS:.c=.o}
HEADERS		= ${PATHHEADERS}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
INCS		= -I${PATHHEADERS} -I${PATHLIBFT}${PATHHEADERS} -I${PATHLIBS}minilibx

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

all:		${NAME}

${NAME}:	${OBJS}
				@echo "${BOLD}${GREEN}Building:${END}\tlibft.a"
				@${MAKE} ${PATHLIBFT} >${PATHNULL}
				@echo "${BOLD}${GREEN}Building:${END}\tminilibx"
				@${MAKE} ${PATHMLX} >${PATHNULL} 2>${PATHNULL}
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@${CC} ${OBJS} ${INCS} ${LIBS} -o ${NAME} >${PATHNULL}

clean:
				@echo "${BOLD}${RED}Removing:${END}\tAll .o files"
				@${RM} ${OBJS} >${PATHNULL}

fclean:		clean
				@${MAKE} ${PATHLIBFT} fclean >${PATHNULL}
				@echo "${BOLD}${RED}Removing:${END}\tMinilibx"
				@${MAKE} ${PATHMLX} clean >${PATHNULL}
				@echo "${BOLD}${RED}Removing:${END}\t${NAME}"
				@${RM} ${NAME} >${PATHNULL}

norminette:
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .c files"
				${NORM} ${SRCS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !\n"
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .h files"
				${NORM} ${HEADERS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !"

re:			fclean all

.PHONY:		all clean fclean re norminette

################################################################################
