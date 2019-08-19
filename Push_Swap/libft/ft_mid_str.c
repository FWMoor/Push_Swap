/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:19:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/18 16:11:17 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_middle_c(t_format *tf)
{
	char		*str;
	char		arg;

	if (tf->t_form == 'c')
	{
		if (!(arg = (char)va_arg(*tf->ap, int)))
		{
			tf->len++;
			return (ft_strdup("^@"));
		}
		str = ft_strnew(2);
		str[0] = arg;
		return (str);
	}
	else if (tf->t_form == 'C')
	{
		str = ft_strnew(5);
		ft_appendwchar(va_arg(*tf->ap, wchar_t), str);
		return (str);
	}
	else
		return (ft_strdup("%"));
}

char			*ft_middle_s(t_format *tf)
{
	char		*str;
	int			*arr;
	int			*temp;
	long		len;

	if (tf->t_form == 's')
	{
		if (!(str = ft_strdup(va_arg(*tf->ap, char *))))
			return (ft_strdup("(null)"));
		return (str);
	}
	if (!(arr = va_arg(*tf->ap, wchar_t *)))
		return (ft_strdup("(null"));
	temp = arr;
	len = 0;
	while (*temp++)
		len++;
	str = ft_strnew((len + 1) * sizeof(wchar_t));
	while (*arr)
		str = ft_appendwchar(*arr++, str);
	return ((char *)str);
}

int				ft_print_sc(t_format *tf, char *str, int fd)
{
	int			i;
	int			len;
	int			min;

	i = 0;
	len = ft_strlen(str);
	if (tf->prec < 0 || tf->t_form == 'c' || tf->t_form == '%')
		tf->prec = len;
	min = (len > tf->prec && (tf->flags & PREC)) ? tf->prec : len;
	if (!(tf->flags & MINUS))
		while (tf->len-- > min)
		{
			(tf->flags & 1) ? ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd);
			i++;
		}
	write(fd, str, min);
	i += (tf->t_form == 'c' && len == 2) ? min - 1 : min;
	if (tf->flags & MINUS)
		while (tf->len-- > min)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
	free(str);
	return (i);
}

char			*ft_appendwchar(wchar_t wc, char *str)
{
	if (wc <= 0x7F)
		*str = (unsigned char)wc;
	else if (wc <= 0x7FF)
	{
		*str++ = 0xC0 | ((wc & 0x07C0) >> 6);
		*str++ = 0x80 | (wc & 0x003F);
	}
	else if (wc <= 0xFFFF)
	{
		*str++ = 0xE0 | ((wc & 0xF000) >> 12);
		*str++ = 0x80 | ((wc & 0x0FC0) >> 6);
		*str++ = 0x80 | (wc & 0x003F);
	}
	else if (wc <= 0x10FFFF)
	{
		*str++ = 0xF0 | ((wc & 0x1c0000) >> 18);
		*str++ = 0x80 | ((wc & 0x03F000) >> 12);
		*str++ = 0x80 | ((wc & 0x0FC0) >> 6);
		*str++ = 0x80 | (wc & 0x003F);
	}
	return (str);
}
