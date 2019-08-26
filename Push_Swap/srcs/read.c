/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:50:46 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/26 21:08:03 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		check_line(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa"))
		swap(a);
	else if (ft_strequ(line, "sb"))
		swap(b);
	else if (ft_strequ(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (ft_strequ(line, "pa"))
		push(a, b);
	else if (ft_strequ(line, "pb"))
		push(b, a);
	else if (ft_strequ(line, "ra"))
		rotate(a);
	else if (ft_strequ(line, "rb"))
		rotate(b);
	else if (ft_strequ(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
}

int			sort_list(t_stack *stacka, t_stack *stackb)
{
	char	*line;

	if (check_dups(stacka))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		check_line(line, &stacka, &stackb);
		free(line);
	}
	check_sort(&stacka, &stackb);
	pstack(&stacka);
	ft_putchar('\n');
	pstack(&stackb);
	return (1);
}
