/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:05:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/30 16:04:30 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sorting(t_stack **stacka, t_stack **stackb)
{
	if (list_size(*stacka) == 2)
		sort_2(stacka);
	else if (list_size(*stacka) == 3)
		sort_3(stacka);
	else if (list_size(*stacka) <= 5)
		sort_5(stacka, stackb);
	else if (list_size(*stacka) > 5)
		sort_larger(stacka, stackb);
}

int			main(int ac, char **av)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	stackb = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		if (check_args(ac, av))
		{
			stacka = stack_init(av);
			if (!check_dups(stacka))
			{
				if (is_ordered(stacka) && !stackb)
					return (0);
				norm(&stacka);
				sorting(&stacka, &stackb);
			}
		}
		list_del(&stacka);
		list_del(&stackb);
	}
	return (0);
}
