/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:14:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/01 21:56:07 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rotate_her(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "ra"))
		rotate(a, 0, "meh");
	else if (ft_strequ(line, "rb"))
		rotate(b, 0, "meh");
	else if (ft_strequ(line, "rr"))
	{
		rotate(a, 0, "meh");
		rotate(b, 0, "meh");
	}
}

void		swap_her(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa"))
		swap(a, 0, "meh");
	else if (ft_strequ(line, "sb"))
		swap(b, 0, "meh");
	else if (ft_strequ(line, "ss"))
	{
		swap(a, 0, "meh");
		swap(b, 0, "meh");
	}
}

void		arg_her(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap_her(line, a, b);
	else if (ft_strequ(line, "pb"))
		push(b, a, 0, "meh");
	else if (ft_strequ(line, "pa"))
		push(a, b, 0, "meh");
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb") ||
	ft_strequ(line, "rr"))
		rotate_her(line, a, b);
	else if (ft_strequ(line, "rra"))
		rev_rotate(a, 0, "meh");
	else if (ft_strequ(line, "rrb"))
		rev_rotate(b, 0, "meh");
	else if (ft_strequ(line, "rrr"))
	{
		rev_rotate(a, 0, "meh");
		rev_rotate(b, 0, "meh");
	}
	else
		exit_com(a, b, "Error");
}

void		get_args(t_stack **stacka, t_stack **stackb)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		arg_her(line, stacka, stackb);
		free(line);
	}
}

int			main(int ac, char **av)
{
	int		i;
	t_env	env;
	t_stack	*stacka;
	t_stack	*stackb;

	i = 1;
	stackb = NULL;
	args(&ac, &av, &env);
	if (ac == 1 || !check_args(ac, av))
		return (0);
	stacka = stack_init(av);
	get_args(&stacka, &stackb);
	if (is_ordered(stacka) && !stackb)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	(env.vis) ? pstack(stacka, stackb) : 0;
	return (0);
}
