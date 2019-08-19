/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:50:46 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 13:02:06 by fremoor          ###   ########.fr       */
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
		ft_printf("hey\n");
		free(line);
	}
	return (1);
}
