NAME_CHECKER =		checker

FLAG =				-Wall -Werror -Wextra -I 

PFDR =				srcs/

FTDR =				libft/

PFFL =				main.c

FTFL =				ft_charcon.c ft_extra.c ft_flags.c ft_isfuncs.c \
					ft_lstcreate.c ft_itoas.c ft_lstmod.c ft_math.c \
					ft_memclr.c ft_memset.c ft_mid_num.c ft_mid_str.c \
					ft_numlens.c ft_printf.c ft_putchars.c ft_putnbrs.c \
					ft_putstrs.c ft_strclrs.c ft_strcmps.c ft_strcpys.c \
					ft_strfill.c ft_strfinds.c ft_strjoins.c ft_strmods.c \
					ft_strscon.c get_next_line.c

PFSR =				$(addprefix $(PFDR), $(PFFL))

FTSR =				$(addprefix $(FTDR), $(FTFL))

POBJ =				$(PFSR:.c=.o)
LOBJ =				$(FTSR:.c=.o)

all: $(NAME_CHECKER)

$(POBJ): %.o: %.c
	@gcc -c $(FLAG) src/ $< -o $@

$(LOBJ): %.o: %.c
	@gcc -c $(FLAG) libft/ $< -o $@

$(NAME_CHECKER): $(LOBJ) $(POBJ)
	@make -C $(FTDR)
	@gcc $(FLAGS) -o $(NAME_CHECKER) $(PFSR) $(FTDR)libftprintf.a

clean:
	@rm -rf $(PFDR)*.o
	@rm -rf $(FTDR)*.o $(FTDR)libftprintf.a

fclean: clean
	@rm -rf $(NAME_CHECKER)

re: fclean all

.PHONY: all fclean clean re
