NAME		=	cub3d

LIBFT		=	 ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
                 ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
                 ft_strchr.c ft_strrchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
                 ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_free_dbchar.c ft_dbstrlen.c get_next_line.c get_next_line_utils.c \
                 ft_realloc_dbchar.c

SRCS		=	main.c show_minimap.c exit.c show_player.c player.c raycasting_minimap.c
SRCS		=	main.c show_minimap.c exit.c player/movement.c player/vector_utils.c show_player.c player.c

OBJDIR_SRCS	=	obj
OBJDIR_SRCS2	=	libft/obj

OBJS		=	\
				$(addprefix $(OBJDIR_SRCS)/,$(SRCS:.c=.o)) \
				$(addprefix $(OBJDIR_SRCS2)/,$(LIBFT:.c=.o)) \
				

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
LIBS		=	-Lmlx -lmlx -lXext -lX11 -lm
RM			=	rm -f

$(OBJDIR_SRCS)/%.o: %.c | $(OBJDIR_SRCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_SRCS2)/%.o: libft/%.c | $(OBJDIR_SRCS2)
				$(CC) $(CFLAGS) -c $< -o $@

all:			${NAME}

$(OBJDIR_SRCS):
				mkdir -p $(OBJDIR_SRCS)

$(OBJDIR_SRCS2):
				mkdir -p $(OBJDIR_SRCS2)

${NAME}:		${OBJS} Makefile cub3d.h
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				rm -fr $(OBJS) $(OBJDIR_SRCS) $(OBJDIR_SRCS2)
fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
