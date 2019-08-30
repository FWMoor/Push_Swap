/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:46:50 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/30 13:05:33 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_len(intmax_t n, int base)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= base)
		i++;
	return (i);
}

int		ft_unum_len(uintmax_t n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int		ft_lnum_len(long long n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

int		ft_word_len(char const *str, char c)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (*str)
	{
		if (temp == 1 && *str == c)
			temp = 0;
		if (temp == 0 && *str != c)
		{
			temp = 1;
			i++;
		}
		str++;
	}
	return (i);
}
