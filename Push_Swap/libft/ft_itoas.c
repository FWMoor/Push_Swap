/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:44:25 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:32:59 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(long long n)
{
	int				neg;
	long long		len;
	char			*str;

	neg = (n < 0 ? 1 : 0);
	len = ft_lnum_len(n);
	str = ft_strnew((size_t)(len + neg));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	else if (n > 0)
		len--;
	else
		str[0] = '0';
	while (n)
	{
		str[len] = (n < 0) ? '0' + -(n % 10) : '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}

char				*ft_itoa_base(intmax_t n, int base)
{
	int				len;
	char			*new;
	static char		rep[] = "0123456789abcdef";

	len = ft_num_len(n, base);
	new = ft_strnew(len);
	while (len > 0)
	{
		new[--len] = rep[n % base];
		n /= base;
	}
	return (new);
}

char				*ft_itoa_base_u(uintmax_t n, int base)
{
	int				len;
	static char		*buf;
	static char		rep[] = "0123456789abcdef";

	len = ft_unum_len(n, base);
	if (len == 0)
		len = 1;
	buf = ft_strnew(len);
	while (len)
	{
		buf[--len] = rep[n % base];
		n /= base;
	}
	return (buf);
}
