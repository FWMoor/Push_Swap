/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:18:48 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/27 15:14:39 by fremoor          ###   ########.fr       */
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
	if (n1 > n2 && n1 < n3 && n2 < n3)
		swap(stack);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		rotate(stack);
	else if (n1 < n2 && n2 < n3 && n1 > n3)
		rev_rotate(stack);
	else if (n1 > n2 && n2 > n1 && n1 > n3)
	{
		swap(stack);
		rev_rotate(stack);
	}
	else
	{
		swap(stack);
		rotate(stack);
	}
}


