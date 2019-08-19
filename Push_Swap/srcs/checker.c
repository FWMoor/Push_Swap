/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:14:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 11:27:06 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_lst(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->val);
		temp = temp->next;
	}
}

int			pop_lst(char **av)
{
	int		i;
	int		j;
	char	**temp;
	t_stack	*initial;

	i = 1;
	initial = NULL;
	while (av[i])
		{
			j = 0;
			temp = ft_strsplit(av[i], ' ');
			while (temp[j])
			{
				if (!initial)
					initial = set_list(ft_atoi(temp[j]));
				else
					list_add(&initial, ft_atoi(temp[j]));
				j++;
			}
			i++;
			free_her(temp);
		}
	print_lst(initial);
	list_del(&initial);
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		while (i < ac)
		{
			j = 0;
			temp = ft_strsplit(av[i++], ' ');
			while (temp[j])
				if (!digit_her(temp[j++]))
				{
					write(1, "Error\n", 6);
					return (0);
				}
			free_her(temp);
		}
		pop_lst(av);
	}
	return (0);
}
