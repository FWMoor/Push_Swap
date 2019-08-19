/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:35:45 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/18 16:13:21 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_getstr_n(t_format *tf)
{
	char			*str;

	if (tf->p_len & HHLEN)
		str = ft_itoa((char)va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & HLEN)
		str = ft_itoa((short)va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & LLLEN)
		str = ft_itoa(va_arg(*tf->ap, long long));
	else if (tf->p_len & LLEN)
		str = ft_itoa((long)va_arg(*tf->ap, long));
	else if (tf->p_len & JLEN)
		str = ft_itoa(va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & ZLEN)
		str = ft_itoa(va_arg(*tf->ap, size_t));
	else if (tf->p_len & CLLEN)
		str = ft_itoa(va_arg(*tf->ap, long double));
	else
		str = ft_itoa(va_arg(*tf->ap, int));
	return (str);
}

char				*ft_getstr_u(t_format *tf, int base)
{
	char			*str;

	if (tf->p_len & HHLEN)
		str = ft_itoa_base_u((unsigned char)va_arg(*tf->ap, uintmax_t), base);
	else if (tf->p_len & HLEN)
		str = ft_itoa_base_u((unsigned short)va_arg(*tf->ap, uintmax_t), base);
	else if (tf->p_len & LLLEN)
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned long long), base);
	else if (tf->p_len & LLEN)
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned long), base);
	else if (tf->p_len & JLEN)
		str = ft_itoa_base_u(va_arg(*tf->ap, uintmax_t), base);
	else if (tf->p_len & ZLEN)
		str = ft_itoa_base_u(va_arg(*tf->ap, size_t), base);
	else
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned int), base);
	return (str);
}

int					ft_getstr_all(t_format *tf, int fd)
{
	char			*str;

	if (tf->t_form == 's' || tf->t_form == 'c' || tf->t_form == '%' ||
			tf->t_form == 'C' || tf->t_form == 'S')
	{
		if (tf->t_form == 's' || tf->t_form == 'S')
			str = ft_middle_s(tf);
		else
			str = ft_middle_c(tf);
		return (ft_print_sc(tf, str, fd));
	}
	else if (tf->t_form == 'd' || tf->t_form == 'i')
		return (ft_middle_n(tf, fd));
	else if (tf->t_form == 'o' || tf->t_form == 'u' ||
	tf->t_form == 'x' || tf->t_form == 'X')
		return (ft_middle_u(tf, fd));
	else if (tf->t_form == 'p')
		return (ft_middle_p(tf, fd));
	else
		return (ft_middle_b(tf, fd));
}
