/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:23:24 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/18 16:11:19 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		ft_p_len(char **str)
{
	unsigned char	p_len;

	p_len = 0;
	while (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
		{
			(*str)++;
			p_len |= (**str == 'h') ? HHLEN && (*str)++ : HLEN;
		}
		else if (**str == 'l')
		{
			(*str)++;
			p_len |= (**str == 'l') ? LLLEN : LLEN;
		}
		else if (**str == 'j' || **str == 'z' || **str == 'L')
		{
			if (**str == 'j' || **str == 'z')
				p_len |= (**str == 'j') ? JLEN : ZLEN;
			else
				p_len |= CLLEN;
			(*str)++;
		}
	}
	return (p_len);
}

unsigned char		ft_flags(char **str)
{
	unsigned char	flags;

	flags = 0;
	while (**str == '0' || **str == ' ' || **str == '+' || **str == '-' ||
		**str == '#')
	{
		if (**str == '0')
			flags |= ZERO;
		if (**str == ' ')
			flags |= BLANK;
		if (**str == '+')
			flags |= PLUS;
		if (**str == '-')
			flags |= MINUS;
		if (**str == '#')
			flags |= SHARP;
		(*str)++;
	}
	if (flags & MINUS && flags & ZERO)
		flags &= ~(ZERO);
	return (flags);
}

int					ft_width(char **str, va_list ap, t_format *tf)
{
	int				i;
	int				temp;

	i = 0;
	if (**str == '*')
	{
		(*str)++;
		temp = va_arg(ap, int);
		i = (temp >= 0) ? temp : 0;
		if (temp < 0)
			tf->flags |= ZERO;
	}
	if (ft_isdigit(**str))
		i = ft_atoi(*str);
	while (**str <= '9' && **str >= '0')
		(*str)++;
	return (i);
}

int					ft_format(char **str, va_list ap, int fd)
{
	int				i;
	t_format		tf;

	tf.prec = 0;
	tf.flags = ft_flags(str);
	tf.len = ft_width(str, ap, &tf);
	if (**str == '.')
	{
		(*str)++;
		tf.flags &= ~(ZERO);
		tf.prec = ft_width(str, ap, &tf);
		tf.flags |= PREC;
	}
	tf.p_len = ft_p_len(str);
	tf.ap = (va_list *)ap;
	if (ft_correct_form(**str) != 1)
		return (0);
	tf.t_form = *(*str)++;
	i = ft_getstr_all(&tf, fd);
	return (i);
}

int					ft_format_all(const char *format, va_list ap, int fd)
{
	int				i;
	char			**str;

	i = 0;
	str = (char **)&format;
	while (**str)
	{
		if (**str == '%')
		{
			*str += 1;
			i += ft_format(str, ap, fd);
		}
		else
		{
			ft_putchar_fd(*((*str)++), fd);
			i++;
		}
	}
	va_end(ap);
	return (i);
}
