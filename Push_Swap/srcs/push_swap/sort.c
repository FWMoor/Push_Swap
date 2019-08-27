/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:18:48 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/27 20:19:57 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		swap(stack);
		rev_rotate(stack);
	}
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		swap(stack);
		rotate(stack);
	}
	else if (n1 > n2 && n1 < n3 && n3 > n2)
		swap(stack);
	else if (n1 > n3 && n3 > n2 && n1 > n2)
		rotate(stack);
	else if (n3 < n1 && n3 < n2 && n1 < n2)
		rev_rotate(stack);
}


