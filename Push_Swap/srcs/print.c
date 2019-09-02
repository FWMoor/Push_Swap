/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:01:35 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 09:27:52 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		puse(void)
{
	ft_putstr("\e[1;1H\e[2J");
	ft_putendl("Push_Swap:");
	ft_putendl("usage: ./push_swap [nums]\n");
	ft_putendl("Checker:");
	ft_putendl("usage: ./checker [-vu] [nums]");
	ft_putendl("\t-v\tVisual mode prints stacks after each move");
	ft_putendl("\t-u\tUsage flag displays this screen");
	exit(0);
}

void		plines(t_env *env, int i)
{
	if (i == 2)
		ft_printf("--------");
	else if (i == 1)
	{
		ft_putstr("\e[1;1H\e[2J");
		ft_printf("-----------------------");
		(env->mov) ? printf("--------\n") : ft_putchar('\n');
		ft_printf("| %-8c | %8c |", 'A', 'B');
		(env->mov) ? ft_printf(" %4s |\n", "Moves") : ft_putchar('\n');
		ft_printf("-----------------------");
		(env->mov) ? printf("--------\n") : ft_putchar('\n');
	}
	else if (i == 0)
		ft_printf("-----------------------\n");
}

void		sidebar(t_env *env, int m, int tot)
{
	if (env->mov)
	{
		(m == 0) ? ft_printf("%6d |", tot) : 0;
		(m == 1) ? plines(env, 2) : 0;
	}
}

void		pstack(t_stack *stacka, t_stack *stackb, t_env *env, int tot)
{
	int		i;
	int		m;

	m = 0;
	plines(env, 1);
	while (stacka || stackb)
	{
		i = (stacka) ? 9 - ft_num_len(stacka->val, 10) : 9;
		ft_putchar('|');
		(stacka) ? ft_printf(GREEN" %d"DEFAULT, stacka->val) : ft_putchar(' ');
		while (--i)
			ft_putchar(' ');
		ft_putstr(" | ");
		i = (stackb) ? 9 - ft_num_len(stackb->val, 10) : 9;
		while (--i)
			ft_putchar(' ');
		(stackb) ? ft_printf(RED"%d "DEFAULT, stackb->val) : ft_putchar(' ');
		ft_putchar('|');
		sidebar(env, m, tot);
		ft_putchar('\n');
		m++;
		(stacka) ? (stacka = stacka->next) : NULL;
		(stackb) ? (stackb = stackb->next) : NULL;
	}
	plines(env, 0);
}
