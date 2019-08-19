/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:14:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 13:02:43 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_lst(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	if (check_dups(lst))
		ft_printf("Error\n");
	else
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
	return (sort_list(initial));
}

int			main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		if (check_args(ac, av) != 0)
			if (pop_lst(av) == 0)
				write(1, "Error\n", 6);
	}
	return (0);
}
