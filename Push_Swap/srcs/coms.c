/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:27:55 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 19:49:05 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		swap(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	if (temp && temp->next)
	{
		i = temp->val;
		temp->val = temp->next->val;
		temp->next->val = i;
	}
}

void		pstack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		ft_printf("%d\n", temp->val);
		temp = temp->next;
	}
}
