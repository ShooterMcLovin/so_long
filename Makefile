RT	:= \033[0m
BK 	:= \033[90;1m
R 	:= \033[91;1m
G	:= \033[92;1m
Y	:= \033[93;1m
B 	:= \033[94;1m
P	:= \033[95;1m
C	:= \033[96;1m
W	:= \033[97;1m

NAME	= so_long
CC		= gcc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	= MLX42
LIBFT	= libft

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= MLX42/libmlx42.a MLX42/lib/lib-x86_64/libglfw3.a libft/libft.a
SRCS	= src/so_long.c src/ennemy.c src/check_map.c src/error.c src/end_game.c src/map.c src/data.c src/move.c src/render.c

OBJDIR	=	bin/
SRCDIR	=	src/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: libs_make $(NAME)
	@echo "$(Y)SO_LONG READY ✔️✔️✔️$(RT)"
	@echo "$(G)launching: $(NAME)...$(RT)"
	@./$(NAME) maps/map42.ber
	
libs_make: 
	@$(MAKE) -C $(LIBMLX)
	@$(MAKE) -C $(LIBFT)
	@echo "$(Y)LIBS UP TO DATE$(RT)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "$(G)Compiling : $(notdir $<) $(RT)"

clean: 
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIBMLX) fclean
	$(MAKE) -C $(LIBFT) fclean	

re: clean all

.PHONY: all, clean, fclean, re
