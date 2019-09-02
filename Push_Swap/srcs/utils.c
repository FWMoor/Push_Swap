/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:32:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 08:13:26 by fremoor          ###   ########.fr       */
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

int			large_num(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = temp->val;
	while (temp)
	{
		if (temp->val > i)
			i = temp->val;
		temp = temp->next;
	}
	return (i);
}

int			large_pos(t_stack **stack, int num)
{
	int		i;
	int		pos;
	t_stack	*node;

	node = *stack;
	i = 0;
	pos = 0;
	while (node)
	{
		if (node->norm == num)
		{
			pos = i;
			break ;
		}
		node = node->next;
		i++;
	}
	return (pos);
}
