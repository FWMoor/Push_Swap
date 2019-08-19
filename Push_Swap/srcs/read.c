/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:50:46 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 20:01:21 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			sort_list(t_stack *stacka)
{
	char	*line;

	if (check_dups(stacka))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		swap(&stacka);
		free(line);
	}
	check_sort(&stacka);
	list_del(&stacka);
	return (1);
}
