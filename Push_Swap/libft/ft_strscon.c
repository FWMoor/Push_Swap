/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:16:11 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:38:11 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			len;
	int			start;
	char		**ret;

	if ((s == NULL) || (c == 0))
		return (NULL);
	len = ft_word_len(s, c);
	if (!(ret = malloc((sizeof(char *)) * (len + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < len)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ret[j] = ft_strsub(s, start, i - start);
		i++;
	}
	ret[j] = NULL;
	return (ret);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return (ft_strsub(s, start, end - start + 1));
}

char			*ft_str_upper(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] -= 32;
		i++;
	}
	return (str);
}
