NAME_CHECKER =		checker

FLAG =				-Wall -Werror -Wextra -I 

SRCDR =				srcs/

FTDR =				libft/

CHFL =				checker.c lists.c checks.c sort.c

FTFL =				ft_charcon.c ft_extra.c ft_flags.c ft_isfuncs.c \
					ft_lstcreate.c ft_itoas.c ft_lstmod.c ft_math.c \
					ft_memclr.c ft_memset.c ft_mid_num.c ft_mid_str.c \
					ft_numlens.c ft_printf.c ft_putchars.c ft_putnbrs.c \
					ft_putstrs.c ft_strclrs.c ft_strcmps.c ft_strcpys.c \
					ft_strfill.c ft_strfinds.c ft_strjoins.c ft_strmods.c \
					ft_strscon.c get_next_line.c

CHSR =				$(addprefix $(SRCDR), $(CHFL))

FTSR =				$(addprefix $(FTDR), $(FTFL))

CHOBJ =				$(CHSR:.c=.o)
LOBJ =				$(FTSR:.c=.o)

all: $(NAME_CHECKER)

$(CHOBJ): %.o: %.c
	@gcc -c $(FLAG) $(SRCDR) $< -o $@

$(LOBJ): %.o: %.c
	@gcc -c $(FLAG) $(FTDR) $< -o $@

$(NAME_CHECKER): $(LOBJ) $(CHOBJ)
	@make -C $(FTDR)
	@gcc $(FLAGS) -o $(NAME_CHECKER) $(CHSR) $(FTDR)libftprintf.a
	@echo "\033[32mBin \033[1;32m$(NAME_CHECKER)\033[1;0m\033[32m Created.\033[0m"

clean:
	@/bin/rm -rf $(SRCDR)*.o
	@/bin/rm -rf $(FTDR)*.o $(FTDR)libftprintf.a
	@echo "\033[1;31mObjects Files Removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME_CHECKER)
	@echo "\033[31mBin \033[1;31m$(NAME_CHECKER)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re
