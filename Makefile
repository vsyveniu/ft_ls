NAME   = ft_ls

SRC	 =  ft_ls.c ft_alphasort.c ft_createlist.c ft_cut.c ft_cut.2.c ft_error.c ft_fill.c ft_fillnull.c ft_fill2.c ft_flags.c \
        ft_free.c ft_get.c ft_mergesort.c ft_print1.c ft_print2.c ft_printfiles.c ft_recursion.c \
        ft_resetcolor.c ft_smallprint.c ft_smallprint2.c ft_smallprint3.c ft_sortbytime2.c ft_suppfuncs.c ft_print3.c ft_sortbytime.c ft_suppfuncs2.c

SRCLIB = ./libft/

NAME2SRC = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror 

HEADER = ft_ls.h

HEADERLIB = ./libft/libft.h

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	 @make -C $(SRCLIB)
	 @echo "\x1b[0;32mLibft OK\033[0m"
	 $(CC) $(OBJ) -L $(SRCLIB) -lft -I $(HEADER) -I $(HEADERLIB) -o $(NAME)
	 @echo "\x1b[36m$(NAME)\x1b[0;32m OK \033[0m"

%.o: %.c
	$(CC) -c $(FLAGS) -I $(HEADER) -I $(HEADERLIB) $< -o $@


clean:
	@echo "\x1b[0;32mClean \x1b[36m libft OBJS \033[1;0m\033[32m --->\033[0m"
	@make -C $(SRCLIB)/ clean
	@echo "\x1b[0;32mClean \x1b[36m ft_ls OBJ \x1b[0;32m --->\033[0m"
	rm -f $(OBJ)
	
	

fclean: clean
	@echo "\x1b[0;32mFClean \x1b[36m libft \x1b[0;32m --->\033[0m"
	@make -C $(SRCLIB)/ fclean
	@echo "\x1b[0;32mFClean \x1b[36m ft_ls \x1b[0;32m --->\033[0m"	
	rm -f $(NAME)
	
	

re: fclean all

.PHONY: re, all, clean, fclean

