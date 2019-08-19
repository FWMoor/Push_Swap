/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:14:55 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:37:57 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s != '\0')
			f(s++);
}

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
		while (*s)
			f(i++, s++);
}

char				*ft_strmap(char const *s, char (*f)(char))
{
	size_t			i;
	char			*fresh;

	if (!s || !f)
		return (NULL);
	fresh = (char *)malloc(ft_strlen(s) + 1);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*fresh;

	if (!s || !f)
		return (NULL);
	fresh = (char *)malloc(ft_strlen(s) + 1);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

char				*ft_strrev(char *str)
{
	int				i;
	char			*ret;
	size_t			len;

	i = 0;
	len = ft_strlen(str);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	while (len--)
		ret[i++] = str[len];
	return (ret);
}
