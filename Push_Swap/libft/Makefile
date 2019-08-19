NAME =		libftprintf.a

FLAG =		-Wall -Werror -Wextra -I 

FTDR =		libft/

FTFL =		ft_charcon.c ft_extra.c ft_flags.c ft_isfuncs.c ft_lstcreate.c \
ft_itoas.c ft_lstmod.c ft_math.c ft_memclr.c ft_memset.c ft_mid_num.c \
ft_mid_str.c ft_numlens.c ft_printf.c ft_putchars.c ft_putnbrs.c ft_putstrs.c \
ft_strclrs.c ft_strcmps.c ft_strcpys.c ft_strfill.c ft_strfinds.c ft_strjoins.c\
ft_strmods.c ft_strscon.c get_next_line.c

LOBJ =		$(FTFL:.c=.o)

all: $(NAME)

$(LOBJ): %.o: %.c
	@gcc -c $(FLAG) FTFL $< -o $@

$(NAME): $(LOBJ)
	@ar rcs $(NAME) $(LOBJ)
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf a.out

re: fclean all

.PHONY: all fclean clean re
