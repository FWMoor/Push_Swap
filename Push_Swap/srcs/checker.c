/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:14:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 08:45:12 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rotate_her(char *line, t_stack **a, t_stack **b)
{
	int		i;

	i = 0;
	if (ft_strequ(line, "ra"))
		i += rotate(a, 0, "meh");
	else if (ft_strequ(line, "rb"))
		i += rotate(b, 0, "meh");
	else if (ft_strequ(line, "rr"))
	{
		i += rotate(a, 0, "meh");
		i += rotate(b, 0, "meh");
	}
	return (i);
}

int			swap_her(char *line, t_stack **a, t_stack **b)
{
	int		i;

	i = 0;
	if (ft_strequ(line, "sa"))
		i += swap(a, 0, "meh");
	else if (ft_strequ(line, "sb"))
		i += swap(b, 0, "meh");
	else if (ft_strequ(line, "ss"))
	{
		i += swap(a, 0, "meh");
		i += swap(b, 0, "meh");
	}
	return (i);
}

int			arg_her(char *line, t_stack **a, t_stack **b)
{
	int		i;

	i = 0;
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		i += swap_her(line, a, b);
	else if (ft_strequ(line, "pb"))
		i += push(b, a, 0, "meh");
	else if (ft_strequ(line, "pa"))
		i += push(a, b, 0, "meh");
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb") ||
	ft_strequ(line, "rr"))
		i += rotate_her(line, a, b);
	else if (ft_strequ(line, "rra"))
		i += rev_rotate(a, 0, "meh");
	else if (ft_strequ(line, "rrb"))
		i += rev_rotate(b, 0, "meh");
	else if (ft_strequ(line, "rrr"))
	{
		i += rev_rotate(a, 0, "meh");
		i += rev_rotate(b, 0, "meh");
	}
	else
		exit_com(a, b, "Error");
	return (i);
}

int			get_args(t_stack **stacka, t_stack **stackb, t_env *env)
{
	int		i;
	char	*line;

	i = 0;
	(env->vis) ? pstack(*stacka, *stackb, env, i) : 0;
	while (get_next_line(0, &line) > 0)
	{
		i += arg_her(line, stacka, stackb);
		(env->vis) ? pstack(*stacka, *stackb, env, i) : 0;
		free(line);
		(env->step) ? sleep(1) : 0;
	}
	return (i);
}

int			main(int ac, char **av)
{
	int		i;
	int		tot;
	t_env	env;
	t_stack	*stacka;
	t_stack	*stackb;

	i = 1;
	stackb = NULL;
	args(&ac, &av, &env);
	if (ac == 1 || !check_args(ac, av))
		return (0);
	stacka = stack_init(av);
	tot = get_args(&stacka, &stackb, &env);
	if (is_ordered(stacka) && !stackb)
		ft_putendl(GREEN"OK");
	else
		ft_putendl(RED"KO");
	return (0);
}
