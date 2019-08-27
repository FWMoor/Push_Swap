NAME_P = push_swap
NAME_C = checker

S_DIR = ./srcs/
C_DIR = ./srcs/checker/
P_DIR = ./srcs/push_swap/

LIBRARY_NAME = libftprintf.a
LIBRARY_DIR = ./libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))

FLAGS = -Wall -Werror -Wextra

CHECK_FUNC =	$(C_DIR)checker.c $(C_DIR)read.c $(S_DIR)lists.c \
				$(S_DIR)checks.c $(S_DIR)coms.c $(S_DIR)print.c

PUSH_FUNC = 	$(P_DIR)push_swap.c $(S_DIR)lists.c $(S_DIR)checks.c \
				$(S_DIR)utils.c $(P_DIR)sort.c $(S_DIR)coms.c $(S_DIR)print.c

CHECK_OBJECTS = $(CHECK_FUNC:.c=.o)
PUSH_OBJECTS = $(PUSH_FUNC:.c=.o)

all: $(NAME_P) $(NAME_C)

$(NAME_C): $(LIBRARY_NAME) 
	@gcc $(FLAGS) -o $(NAME_C) $(CHECK_FUNC) $(LIBRARY) 
	@echo "Checker Built!"

$(NAME_P): $(LIBRARY_NAME) 
	@gcc $(FLAGS) -o $(NAME_P) $(PUSH_FUNC) $(LIBRARY) 
	@echo "Push_Swap Built!"

$(LIBRARY_NAME):
	@make -C $(LIBRARY_DIR)
	@echo "Libft Built!"

clean:
	@echo "Removing Objects..."
	@/bin/rm -rf $(S_DIR)*.o $(C_DIR)*.o $(P_DIR)*.o
	@make clean -C $(LIBRARY_DIR)
	@echo "Clean complete!"

fclean: clean
	@echo "Removing Objects..."
	@/bin/rm -f $(NAME_P) $(NAME_C)
	@make fclean -C $(LIBRARY_DIR)
	@echo "Fclean complete!"

re: fclean all
