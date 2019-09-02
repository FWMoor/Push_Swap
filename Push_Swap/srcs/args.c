/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:26:54 by fwmoor            #+#    #+#             */
/*   Updated: 2019/09/02 09:35:14 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			understand_char(char c, t_env *flags)
{
	if (c == 'v')
		flags->vis = 1;
	else if (c == 'u')
		puse();
	else if (c == 'c')
		flags->col = 1;
	else if (c == 's')
		flags->step = 1;
	else if (c == 'm')
		flags->mov = 1;
	else if (c == 'o')
		flags->opp = 1;
	else
		puse();
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
	if (env->mov && env->vis != 1)
		env->mov = 0;
	if (env->step && env->vis != 1)
		env->step = 0;
	if (env->opp && env->vis != 1)
		env->opp = 0;
}
