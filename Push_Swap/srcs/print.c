/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:01:35 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/03 16:53:16 by fwmoor           ###   ########.fr       */
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
	ft_putendl("\t-c\tAdds colour to the output");
	ft_putendl("\t-s\tStep-by-step mode waits 0.5s between each move. (ps)");
	ft_putendl("\t-m\tDisplays total amount of moves at the end of the algo");
	ft_putendl("\t-o\tDisplays last operation done");
	exit(0);
}

char		*setcol(char *l, t_env *env)
{
	if (env->col)
	{
		if (l[0] == 's')
			return (BLUE);
		else if (l[0] == 'r')
			return (CYAN);
		else if (l[0] == 'p')
			return (MAGENTA);
		else if (l[0] == '1')
			return (GREEN);
		else
			return (YELLOW);
	}
	return (DEFAULT);
}

void		plines(t_env *env, int i, char *l)
{
	if (i == 2 && (env->mov || env->opp))
	{
		ft_putstr("| ");
		(env->opp) ? ft_printf("%-8s | ", "Last") : 0;
		(env->mov) ? ft_printf("%8s |", "Move") : 0;
		ft_putstr("\n|");
		if (l)
			(env->opp) ? ft_printf("%s %-8s \x1b[0m|", setcol(l, env), l) : 0;
		else
			(env->opp) ? ft_printf(" %-8c |", ' ') : 0;
		(env->mov) ? ft_printf("%9d |", env->moves) : 0;
		ft_putchar('\n');
		(env->opp) ? ft_printf("------------") : 0;
		if (env->opp && env->mov)
				ft_printf("-----------");
		else
			(env->mov) ? ft_printf("------------") : 0;
		ft_putchar('\n');
	}
	else if (i == 1)
	{
		ft_printf("\e[1;1H\e[2J-----------------------");
		ft_printf("\n| %-8c | %8c |", 'A', 'B');
		ft_printf("\n-----------------------\n");
	}
	else if (i == 0)
		ft_printf("-----------------------\n");
}

void		pstack(t_stack *a, t_stack *b, t_env *env, char *l)
{
	int		i;

	plines(env, 1, l);
	while (a || b)
	{
		i = (a) ? 9 - ft_num_len(a->val, 10) : 9;
		(a) ? ft_printf("|%s %d"DEFAULT, setcol("1", env), a->val) :
		ft_putstr("| ");
		while (--i)
			ft_putchar(' ');
		ft_putstr(" | ");
		i = (b) ? 9 - ft_num_len(b->val, 10) : 9;
		while (--i)
			ft_putchar(' ');
		(b) ? ft_printf("%s%d \x1b[0m|", setcol("2", env), b->val) :
		ft_putstr(" |");
		ft_putchar('\n');
		(a) ? (a = a->next) : NULL;
		(b) ? (b = b->next) : NULL;
	}
	plines(env, 0, l);
	plines(env, 2, l);
}
