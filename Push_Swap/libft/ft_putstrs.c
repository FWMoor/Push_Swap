/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:50:19 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/18 19:51:50 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s == NULL)
		return ((void)NULL);
	write(1, s, ft_strlen(s));
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ((void)NULL);
	write(fd, s, ft_strlen(s));
}

void	ft_putendl(char const *s)
{
	if (s == NULL)
		return ((void)NULL);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
		return ((void)NULL);
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
