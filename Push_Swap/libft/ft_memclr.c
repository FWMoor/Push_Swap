/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:59:02 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/18 20:18:57 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	if (n)
		ft_memset(str, 0, n);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *chr;

	if (len == 0)
		return (b);
	chr = (unsigned char *)b;
	while (len)
	{
		*chr = (unsigned char)c;
		len--;
		chr++;
	}
	return (b);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return (dest);
}

void	ft_foreach(int *tab, int len, void (*f)(int))
{
	int i;

	i = 0;
	while (i < len)
	{
		f(tab[i]);
		i++;
	}
}
