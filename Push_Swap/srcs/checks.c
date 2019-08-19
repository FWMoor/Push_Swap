/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:42:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 12:59:04 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_dups(t_stack *list)
{
	t_stack *cur;
	t_stack *temp;

	cur = list;
	while (cur->next)
	{
		temp = cur->next;
		while (temp)
		{
			if (temp->val == cur->val)
				return (1);
			temp = temp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int			check_args(int ac, char **args)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < ac)
		{
			j = 0;
			temp = ft_strsplit(args[i++], ' ');
			while (temp[j])
				if (!digit_her(temp[j++]))
				{
					write(1, "Error\n", 6);
					return (0);
				}
			free_her(temp);
		}
	return (1);
}
