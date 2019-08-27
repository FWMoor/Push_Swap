/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:50:46 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/27 14:08:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rotate_her(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "ra"))
		rotate(a);
	else if (ft_strequ(line, "rb"))
		rotate(b);
	else if (ft_strequ(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
}

void		swap_her(char *line, t_stack **a, t_stack **b)
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
}

void		check_line(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap_her(line, a, b);
	else if (ft_strequ(line, "pa"))
		push(a, b);
	else if (ft_strequ(line, "pb"))
		push(b, a);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb") ||
	ft_strequ(line, "rr"))
		rotate_her(line, a, b);
	else if (ft_strequ(line, "rra"))
		rev_rotate(a);
	else if (ft_strequ(line, "rrb"))
		rev_rotate(b);
	else if (ft_strequ(line, "rrr"))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		exit_com(a, b, "Error");
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
	return (1);
}
