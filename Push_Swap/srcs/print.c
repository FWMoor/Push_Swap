/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:01:35 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 10:26:13 by fremoor          ###   ########.fr       */
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
		ft_printf("-------");
	else if (i == 1)
	{
		ft_putstr("\e[1;1H\e[2J");
		ft_printf("-----------------------");
		(env->opp) ? ft_printf("-------") : 0;
		(env->mov) ? ft_printf("-------") : 0;
		ft_putchar('\n');
		ft_printf("| %-8c | %8c |", 'A', 'B');
		(env->opp) ? ft_printf(" %4s |", "Last") : 0;
		(env->mov) ? ft_printf(" %4s |", "Move") : 0;
		ft_putchar('\n');
		ft_printf("-----------------------");
		(env->opp) ? ft_printf("-------") : 0;
		(env->mov) ? ft_printf("-------") : 0;
		ft_putchar('\n');
	}
	else if (i == 0)
		ft_printf("-----------------------\n");
}

void		sidebar(t_env *env, int m, char *l, int tot)
{
	int		i;
	
	if (env->opp)
	{
		if (l)
		{
			i = ft_strlen(l);
			i = (i == 3) ? 6 - i : 5 - i;
			(m == 0) ? ft_printf(" %*s  |", i, l) : 0;
		}
		else
			(m == 0) ? ft_printf("%7c", '|') : 0;
		(m == 1) ? plines(env, 2) : 0;
	}
	if (env->mov)
	{
		(m == 0) ? ft_printf("%5d |", tot) : 0;
		(m == 1) ? plines(env, 2) : 0;
	}
	ft_putchar('\n');
}

void		pstack(t_stack *a, t_stack *b, t_env *env, char *l, int tot)
{
	int		i;
	int		m;

	m = 0;
	plines(env, 1);
	while (a || b)
	{
		i = (a) ? 9 - ft_num_len(a->val, 10) : 9;
		ft_putchar('|');
		(a) ? ft_printf(GREEN" %d"DEFAULT, a->val) : ft_putchar(' ');
		while (--i)
			ft_putchar(' ');
		ft_putstr(" | ");
		i = (b) ? 9 - ft_num_len(b->val, 10) : 9;
		while (--i)
			ft_putchar(' ');
		(b) ? ft_printf(RED"%d "DEFAULT, b->val) : ft_putchar(' ');
		ft_putchar('|');
		sidebar(env, m, l, tot);
		m++;
		(a) ? (a = a->next) : NULL;
		(b) ? (b = b->next) : NULL;
	}
	plines(env, 0);
}
