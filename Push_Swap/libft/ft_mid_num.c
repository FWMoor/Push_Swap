/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:26:34 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/18 16:11:18 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_middle_n(t_format *tf, int fd)
{
	int				i;
	long			len;
	char			*str;

	i = 0;
	str = ft_getstr_n(tf);
	len = ft_strlen(str);
	str = (*str == '0' && (tf->flags & PREC && tf->prec <= 0)) ?
	ft_strdup("") : str;
	if (*str != '-' && (tf->flags & PLUS || tf->flags & BLANK) && ++i)
		tf->len > 0 ? tf->len-- : tf->len;
	if (*str == '-')
		tf->prec++;
	i += ft_before(tf, len, str, fd);
	if (*str != '-' && (tf->flags & PLUS))
		ft_putchar_fd('+', fd);
	else if (*str != '-' && (tf->flags & BLANK))
		ft_putchar_fd(' ', fd);
	i += ft_after(tf, len, str, fd);
	free(str);
	return (i);
}

int					ft_middle_u(t_format *tf, int fd)
{
	int				i;
	long			len;
	char			*str;

	i = 0;
	if (ft_tolower(tf->t_form) == 'x' || tf->t_form == 'o')
		str = (tf->t_form == 'o') ? ft_getstr_u(tf, 8) : ft_getstr_u(tf, 16);
	else
		str = ft_getstr_u(tf, 10);
	if (tf->t_form == 'X')
		str = ft_str_upper(str);
	str = (ft_strcmp(str, "0") == 0 && (tf->t_form == 'x' ||
	tf->t_form == 'X' || tf->t_form == 'o') && tf->flags & PREC &&
	tf->prec <= 0) ? ft_strdup("") : str;
	if (ft_tolower(tf->t_form) == 'x' && (tf->prec <= 0 && tf->flags & PREC))
		tf->flags &= ~(SHARP);
	len = ft_strlen(str);
	i += ft_before(tf, len, str, fd);
	i += ft_after(tf, len, str, fd);
	free(str);
	return (i);
}

int					ft_middle_p(t_format *tf, int fd)
{
	int				i;
	long			len;
	char			*str;
	long			add;
	unsigned char	*ptr;

	i = 0;
	ptr = va_arg(*tf->ap, void *);
	add = (long)ptr;
	str = ft_itoa_base_u(add, 16);
	len = ft_strlen(str);
	tf->len -= 2;
	i += ft_before(tf, len, str, fd);
	ft_putstr_fd("0x", fd);
	i += 2;
	if (ft_strcmp(str, "0") == 0)
		return (i);
	i += ft_after(tf, len, str, fd);
	free(str);
	return (i);
}

int					ft_middle_b(t_format *tf, int fd)
{
	int				c;
	int				d;
	int				n;
	int				count;
	char			*ret;

	c = 32;
	count = 0;
	n = va_arg(*tf->ap, int);
	if (!(ret = (char *)malloc(32 + 1)))
		return (0);
	while (c-- > 0)
	{
		d = n >> c;
		if (d & 1)
			*(ret + count) = 1 + '0';
		else
			*(ret + count) = 0 + '0';
		count++;
	}
	*(ret + count) = '\0';
	ft_putstr_fd(ret, fd);
	free(ret);
	return (32);
}
