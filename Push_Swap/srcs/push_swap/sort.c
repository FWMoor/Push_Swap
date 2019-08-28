/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:18:48 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/28 11:32:28 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		sort_2(t_stack **stack)
{
	if ((*stack)->val > (*stack)->next->val)
	{
		ft_putendl("sa");
		swap(stack);
	}
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
		ft_putendl("sa");
		swap(stack);
		ft_putendl("rra");
		rev_rotate(stack);
	}
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		ft_putendl("sa");
		swap(stack);
		ft_putendl("ra");
		rotate(stack);
	}
	else if (n1 > n2 && n1 < n3 && n3 > n2)
	{
		ft_putendl("sa");
		swap(stack);
	}
	else if (n1 > n3 && n3 > n2 && n1 > n2)
	{
		ft_putendl("ra");
		rotate(stack);
	}
	else if (n3 < n1 && n3 < n2 && n1 < n2)
	{
		ft_putendl("rra");
		rev_rotate(stack);
	}
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
	while(i-- > 0)
	{
		ft_putendl("pa");
		push(stacka, stackb);
	}
}
