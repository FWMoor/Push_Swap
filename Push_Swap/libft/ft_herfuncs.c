/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:50:47 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/28 13:12:56 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_her(char **dirs)
{
	int		i;

	i = 0;
	while (dirs[i])
		ft_strdel(&dirs[i++]);
	free(dirs);
}

int			digit_her(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] == '-')
		i++;
	else if (!ft_isdigit(arg[i]))
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
