/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:00:30 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:36:52 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memalloc(size_t size)
{
	void				*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

void					*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t				i;
	char				*dest;
	const char			*src;

	if (str2 == str1)
		return ((char *)str2);
	dest = (char *)str1;
	src = (char *)str2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char				*str1;
	const char			*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	while (n)
	{
		*str1 = *str2;
		if (*str2 == (char)c)
			return (str1 + 1);
		str1++;
		str2++;
		n--;
	}
	return (NULL);
}

int						ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
