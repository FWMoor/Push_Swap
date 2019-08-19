/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:04:09 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:37:06 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, (int)'\0', size + 1);
	return (str);
}

char		*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	return (ft_strcpy(str, s));
}
