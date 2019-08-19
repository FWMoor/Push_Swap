/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:42:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 20:03:27 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_sort(t_stack **stacka)
{
	t_stack	*temp;

	temp = *stacka;
	while (temp->next)
	{
		if (temp->val > temp->next->val)
		{
			ft_putendl("KO");
			return (1);
		}
		temp = temp->next;
	}
	ft_putendl("OK");
	return (1);
}

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
			{
				list_del(&list);
				return (1);
			}
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
					free_her(temp);
					ft_putendl("Error");
					return (0);
				}
			free_her(temp);
		}
	return (1);
}
