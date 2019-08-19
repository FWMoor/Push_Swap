/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:49:55 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 10:53:00 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <ctype.h>

# define ZERO 1
# define BLANK 2
# define PLUS 4
# define MINUS 8
# define SHARP 16
# define PREC 32

# define HHLEN 1
# define HLEN 2
# define LLLEN 4
# define LLEN 8
# define JLEN 16
# define ZLEN 32
# define CLLEN 64

# define BUFF_SIZE 32

typedef struct		s_format
{
	int				neg;
	char			t_form;
	long			prec;
	long			len;
	va_list			*ap;
	unsigned char	flags;
	unsigned char	p_len;
}					t_format;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Int functions
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_lnum_len(long long n);
int					ft_atoi(const char *str);
int					ft_num_len(intmax_t n, int base);
int					ft_unum_len(uintmax_t n, int base);
int					ft_word_len(char const *str, char c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);

/*
** Char functions
*/

char				*ft_itoa(long long n);
char				*ft_strnew(size_t size);
char				*ft_str_upper(char *str);
char				*ft_strdup(const char *s);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_strstr(char *str, char *to_find);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa_base_u(uintmax_t n, int base);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *srcs);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(char *str, char *to_find, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Void functions
*/

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				*ft_memalloc(size_t n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_memccpy(void *str1, const void *str2, int c, size_t n);

/*
** Her functions
*/

int					digit_her(char *args);
void				free_her(char **dirs);

/*
** Size_t functions
*/

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

/*
** T_list functions
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Bonus functions
*/

int					ft_sqrt(int nb);
int					ft_factorial(int nb);
int					ft_power(int nb, int pwr);
char				*ft_strrev(char *str);
void				ft_foreach(int *tab, int len, void(*f)(int));

/*
** GNL functions
*/

int					get_next_line(const int fd, char **line);

/*
** FT_PrintF functions
*/

int					ft_correct_form(char c);
int					ft_middle_n(t_format *tf, int fd);
int					ft_middle_u(t_format *tf, int fd);
int					ft_middle_p(t_format *tf, int fd);
int					ft_middle_b(t_format *tf, int fd);
int					ft_printf(const char *format, ...);
int					ft_getstr_all(t_format *tf, int fd);
int					ft_format(char **str, va_list ap, int fd);
int					ft_fdprintf(int fd, const char *format, ...);
int					ft_print_sc(t_format *tf, char *str, int fd);
int					ft_width(char **str, va_list ap, t_format *tf);
int					ft_after(t_format *tf, long len, char *str, int fd);
int					ft_before(t_format *tf, long len, char *str, int fd);
int					ft_defore(t_format *tf, long len, char *str, int fd);
int					ft_format_all(const char *format, va_list ap, int fd);
char				*ft_middle_c(t_format *tf);
char				*ft_middle_s(t_format *tf);
char				*ft_getstr_n(t_format *tf);
char				*ft_getstr_u(t_format *tf, int base);
char				*ft_appendwchar(wchar_t wc, char *str);
unsigned char		ft_flags(char **str);
unsigned char		ft_p_len(char **str);

#endif
