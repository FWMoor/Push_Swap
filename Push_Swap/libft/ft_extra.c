/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:22:59 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/18 16:10:19 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_defore(t_format *tf, long len, char *str, int fd)
{
	int				i;
	long			max;

	(void)str;
	i = 0;
	max = (tf->prec > len && (tf->flags & PREC && tf->prec >= 0)) ? tf->prec :
	len;
	if (!(tf->flags & MINUS) && !(tf->flags & ZERO))
		while (tf->len-- > max)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
	return (i);
}

int					ft_before(t_format *tf, long len, char *str, int fd)
{
	int				i;
	long			max;

	i = 0;
	if (ft_tolower(tf->t_form) == 'x' && tf->flags & SHARP && str[0] != '0')
	{
		tf->len-- > 0 ? tf->len-- && i++ : i++;
		i++;
	}
	if (tf->flags & SHARP && (tf->t_form == 'o' && str[0] != '0'))
		tf->len > 0 ? tf->len-- && i++ : i++;
	max = (tf->prec > len && (tf->prec >= 0)) ? tf->prec : len;
	if (!(tf->flags & MINUS) & !(tf->flags & ZERO))
		while (tf->len-- > max)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
	if (tf->flags & SHARP && tf->t_form == 'x' && str[0] != '0')
		ft_putstr_fd("0x", fd);
	else if (tf->flags & SHARP && tf->t_form == 'X' && str[0] != '0')
		ft_putstr_fd("0X", fd);
	else if (tf->flags & SHARP && tf->t_form == 'o' && str[0] != '0')
		ft_putchar_fd('0', fd);
	return (i);
}

int					ft_after(t_format *tf, long len, char *str, int fd)
{
	int				i;
	long			max;

	i = 0;
	if (*str == '-')
	{
		ft_putchar_fd('-', fd);
		(str)++;
	}
	while ((tf->flags & ZERO && tf->len > len) || tf->prec-- > len)
	{
		ft_putchar_fd('0', fd);
		i++;
		tf->len > 0 ? tf->len-- : tf->len;
	}
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	ft_putstr_fd(str, fd);
	i += len;
	if (tf->flags & MINUS)
		while (tf->len-- > max)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
	return (i);
}

int					ft_correct_form(char c)
{
	if (ft_tolower(c) == 's' || ft_tolower(c) == 'c' || ft_tolower(c) == 'd' ||
			c == '%' || ft_tolower(c) == 'o' || c == 'x' || c == 'X' ||
			ft_tolower(c) == 'u' || c == 'p' || c == 'i' || c == 'm' ||
			c == 'b')
		return (1);
	else
		return (0);
}
