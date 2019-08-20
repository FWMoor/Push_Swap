/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:14:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 11:38:02 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_stack	*stacka = NULL;
	//t_stack	*stackb = NULL;

	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		if (check_args(ac, av))
		{
			stacka = stack_init(av);
			if (check_dups(stacka))
				write(1, "Error\n", 6);
		}
	}
	return (0);
}
