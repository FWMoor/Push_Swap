/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:42:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/30 13:17:40 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		exit_com(t_stack **stacka, t_stack **stackb, char *str)
{
	ft_putendl(str);
	list_del(stacka);
	list_del(stackb);
	exit(0);
}

int			is_ordered(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp && temp->next && temp->val < temp->next->val)
		temp = temp->next;
	if (temp && temp->next)
		return (0);
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
