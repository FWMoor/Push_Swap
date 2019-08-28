/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:32:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/28 12:49:08 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			list_size(t_stack *stack)
{
	int		len;
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int			small_pos(t_stack **stack, int num)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp->val != num)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int			small_num(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = temp->val;
	while (temp)
	{
		if (temp->val < i)
			i = temp->val;
		temp = temp->next;
	}
	return (i);
}

void		push_small(t_stack **stacka, t_stack **stackb, int pos)
{
	int		len;

	len = list_size(*stacka);
	if (pos > len / 2)
	{
		pos = len - pos;
		while (pos-- != 0)
			rev_rotate(stacka, 1, "rra");
	}
	else if (pos <= len / 2)
	{
		while (pos-- != 0)
			rotate(stacka, 1, "ra");
	}
	push(stackb, stacka, 1, "pb");
}
