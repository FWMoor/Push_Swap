/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:43:02 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/18 20:23:33 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
