/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:18:48 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 14:08:41 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_2(t_stack **stack)
{
	if ((*stack)->val > (*stack)->next->val)
		swap(stack, 1, "sa");
}

void		sort_3(t_stack **stack)
{
	int		n1;
	int		n2;
	int		n3;
	t_stack	*temp;

	temp = *stack;
	n1 = temp->val;
	n2 = temp->next->val;
	n3 = temp->next->next->val;
	if (n1 > n2 && n1 > n3 && n3 < n2)
	{
		swap(stack, 1, "sa");
		rev_rotate(stack, 1, "rra");
	}
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		swap(stack, 1, "sa");
		rotate(stack, 1, "ra");
	}
	else if (n1 > n2 && n1 < n3 && n3 > n2)
		swap(stack, 1, "sa");
	else if (n1 > n3 && n3 > n2 && n1 > n2)
		rotate(stack, 1, "ra");
	else if (n3 < n1 && n3 < n2 && n1 < n2)
		rev_rotate(stack, 1, "rra");
}

void		sort_5(t_stack **stacka, t_stack **stackb)
{
	int		i;
	int		pos;
	int		size;

	size = list_size(*stacka);
	i = 0;
	while (i++ < (size - 3))
	{
		pos = small_pos(stacka, small_num(stacka));
		push_small(stacka, stackb, pos);
	}
	sort_3(stacka);
	while (i-- > 0)
		push(stacka, stackb, 1, "pa");
}

void		sort_larger(t_stack **stacka, t_stack **stackb)
{
	int		i;
	int		max;
	int		size;

	i = 1;
	max = 0;
	size = list_size(*stacka);
	while (*stacka)
	{
		max += (size <= 100) ? size / 5 - 2 : size / 11 - 2;
		while (i <= max)
		{
			if (!(*stacka))
				break ;
			if ((*stacka)->norm <= max)
			{
				push(stackb, stacka, 1, "pb");
				i++;
			}
			else
				rotate(stacka, 1, "ra");
		}
	}
	i--;
	push_b(stacka, stackb, i, max);
}
