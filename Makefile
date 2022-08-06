# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 16:13:46 by wdebotte          #+#    #+#              #
#    Updated: 2022/08/06 14:08:31 by wdebotte         ###   ########.fr        #
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

NAME		= cub3d

PATHSRCS	= srcs/
PATHHEADERS	= includes/
PATHLIBFT	= libft/
PATHNULL	= /dev/null

SRCS		= $(addprefix ${PATHSRCS}, main.c parser.c parcer_tools.c tmp_tools.c \
									check_map.c)
#			$(addprefix ${PATHSRCS}parsing/, file1.c file2.c file3.c)

OBJS		= ${SRCS:.c=.o}
HEADERS		= ${PATHHEADERS}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
INCS		= -I${PATHHEADERS} -I${PATHLIBFT}${PATHHEADERS}

RM			= rm -rf
MAKE		= make -C
NORM		= norminette

LIBFT		= -L${PATHLIBFT} -lft

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
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@${CC} ${OBJS} ${INCS} ${LIBFT} -o ${NAME} >${PATHNULL}

clean:
				@echo "${BOLD}${RED}Removing:${END}\tAll .o files"
				@${RM} ${OBJS} >${PATHNULL}

fclean:		clean
				@${MAKE} ${PATHLIBFT} fclean >${PATHNULL}
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
