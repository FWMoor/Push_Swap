/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:26:54 by fwmoor            #+#    #+#             */
/*   Updated: 2019/09/01 21:56:25 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			understand_char(char c, t_env *flags)
{
	if ('v' == c)
		flags->vis = 1;
}

void			short_arg(char *str, t_env *flags)
{
	str += 1;
	while ('\0' != *str)
	{
		understand_char(*str, flags);
		str += 1;
	}
}

void			args(int *ac, char ***av, t_env *env)
{
	int			pos;

	pos = 1;
	while (pos < *ac)
	{
		if ((*av)[pos][0] == '-')
		{
			if (!ft_isdigit((*av)[pos][1]))
				short_arg(*((*av) + pos), env);
			else
				break ;
		}
		else
			break ;
		pos += 1;
	}
	pos -= 1;
	*ac -= pos;
	*av += pos;

}
