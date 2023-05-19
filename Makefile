NAME		=	cub3d

LIBFT		=	 ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
                 ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
                 ft_strchr.c ft_strrchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
                 ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_free_dbchar.c ft_dbstrlen.c get_next_line.c get_next_line_utils.c \
                 ft_realloc_dbchar.c

SRCS		=	main.c exit.c make_dda_array.c need_place.c
SRCS2		=	movement.c vector_utils.c input.c checker.c player.c
SRCS3		=	setup.c setup_textures.c map_validity.c
SRCS4		=	debug.c
SRCS5		=	display.c show_minimap.c roof_floor_display.c

OBJDIR_SRCS		=	obj
OBJDIR_SRCS2	=	libft/obj
OBJDIR_SRCS3	=	player/obj
OBJDIR_SRCS4	=	setup/obj
OBJDIR_SRCS5	=	debug/obj
OBJDIR_SRCS6	=	display/obj

OBJS		=	\
				$(addprefix $(OBJDIR_SRCS)/,$(SRCS:.c=.o)) \
				$(addprefix $(OBJDIR_SRCS2)/,$(LIBFT:.c=.o)) \
				$(addprefix $(OBJDIR_SRCS3)/,$(SRCS2:.c=.o)) \
				$(addprefix $(OBJDIR_SRCS4)/,$(SRCS3:.c=.o)) \
				$(addprefix $(OBJDIR_SRCS5)/,$(SRCS4:.c=.o)) \
				$(addprefix $(OBJDIR_SRCS6)/,$(SRCS5:.c=.o))

				
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -O3
LIBS		=	-Lmlx -lmlx -lXext -lX11 -lm
RM			=	rm -f

$(OBJDIR_SRCS)/%.o: %.c | $(OBJDIR_SRCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_SRCS2)/%.o: libft/%.c | $(OBJDIR_SRCS2)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_SRCS3)/%.o: player/%.c | $(OBJDIR_SRCS3)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_SRCS4)/%.o: setup/%.c | $(OBJDIR_SRCS4)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_SRCS5)/%.o: debug/%.c | $(OBJDIR_SRCS5)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_SRCS6)/%.o: display/%.c | $(OBJDIR_SRCS6)
				$(CC) $(CFLAGS) -c $< -o $@

all:			${NAME}

$(OBJDIR_SRCS):
				mkdir -p $(OBJDIR_SRCS)

$(OBJDIR_SRCS2):
				mkdir -p $(OBJDIR_SRCS2)

$(OBJDIR_SRCS3):
				mkdir -p $(OBJDIR_SRCS3)

$(OBJDIR_SRCS4):
				mkdir -p $(OBJDIR_SRCS4)
	
$(OBJDIR_SRCS5):
				mkdir -p $(OBJDIR_SRCS5)

$(OBJDIR_SRCS6):
				mkdir -p $(OBJDIR_SRCS6)

${NAME}:		${OBJS} Makefile cub3d.h
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				rm -fr $(OBJS) $(OBJDIR_SRCS) $(OBJDIR_SRCS2) $(OBJDIR_SRCS3) $(OBJDIR_SRCS4) $(OBJDIR_SRCS5) $(OBJDIR_SRCS6)
fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
