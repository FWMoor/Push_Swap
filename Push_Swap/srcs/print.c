/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:01:35 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/27 09:23:03 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		plines(int i)
{
	if (i == 1)
	{
		ft_printf("---------------\n");
		ft_printf("|%-5c | %5c|\n", 'A', 'B');
		ft_printf("---------------\n");
	}
	else if (i == 0)
		ft_printf("---------------\n");
}

void		pstack(t_stack *stacka, t_stack *stackb)
{
	int		i;

	plines(1);
	while (stacka || stackb)
	{
		if (stacka)
			i = 6 - ft_num_len(stacka->val, 10);
		else
			i = 5;
		(stacka) ? ft_printf("|%d", stacka->val) : ft_putstr(" |");
		while (--i)
			ft_putchar(' ');
		ft_putstr(" | ");
		if (stackb)
			i = 6 - ft_num_len(stackb->val, 10);
		else
			i = 5;
		while (--i)
			ft_putchar(' ');
		(stackb) ? ft_printf("%d|\n", stackb->val) : ft_putstr(" |\n");
		(stacka) ? (stacka = stacka->next) : NULL;
		(stackb) ? (stackb = stackb->next) : NULL;
	}
	plines(0);
}
