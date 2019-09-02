/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:42:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 14:50:42 by fremoor          ###   ########.fr       */
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
				ft_putendl("Error");
				return (1);
			}
			temp = temp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int			dups_check(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strequ(av[i], av[j]))
			{
				ft_putendl("Error");
				return (1);
			}
			j++;
		}
		i++;
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
