/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:14:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/28 14:51:02 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			main(int ac, char **av)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		if (check_args(ac, av))
		{
			stacka = stack_init(av);
			if (sort_list(stacka, stackb) == 0)
				ft_putendl("Error");
		}
	}
	return (0);
}
