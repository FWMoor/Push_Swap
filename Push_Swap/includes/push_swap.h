/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:12:39 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/30 11:57:34 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				val;
	int				norm;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*set_list(int num);
t_stack				*stack_init(char **av);
void				norm(t_stack **stacka);
int					check_dups(t_stack *list);
int					is_ordered(t_stack *a);
void				sort_larger(t_stack **stacka, t_stack **stackb);
void				swap(t_stack **stack, int p, char *s);
void				push(t_stack **to, t_stack **from, int p, char *s);
void				rotate(t_stack **stack, int p, char *s);
void				rev_rotate(t_stack **stack, int p, char *s);
int					check_sort(t_stack **stacka, t_stack **stackb);
void				pstack(t_stack *stacka, t_stack *stackb);
int					check_args(int ac, char **args);
int					list_size(t_stack *stack);
void				sort_2(t_stack **stack);
void				sort_3(t_stack **stack);
void				sort_5(t_stack **stacka, t_stack **stackb);
int					small_num(t_stack **stack);
int					small_pos(t_stack **stack, int num);
int					large_num(t_stack **stack);
int					large_pos(t_stack **stack, int num);
void				push_small(t_stack **stacka, t_stack **stackb, int pos);
void				exit_com(t_stack **stacka, t_stack **stackb, char *str);
void				list_add(t_stack **list, int num);
void				list_del(t_stack **list);
void				head_add(t_stack **list, t_stack *node);

#endif
