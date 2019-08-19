/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfinds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:08:13 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:37:45 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return ((char *)s + i);
		i++;
	}
	if (c != '\0')
		return (NULL);
	return ((char *)s + i);
}

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)s + i);
	while (i)
	{
		i--;
		if (c == s[i])
			return ((char *)s + i);
	}
	return (NULL);
}

char		*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

char		*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	str_len;
	size_t	find_len;

	if (!*to_find)
		return ((char *)str);
	find_len = ft_strlen(to_find);
	str_len = ft_strlen(str);
	while (*str && n >= find_len && find_len <= str_len)
	{
		if (!ft_strncmp(str, to_find, find_len))
			return ((char *)str);
		n--;
		str_len--;
		str++;
	}
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return ((size_t)i);
}
