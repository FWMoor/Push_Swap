/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:32:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/27 14:33:46 by fremoor          ###   ########.fr       */
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
