/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:12:39 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 11:36:36 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*set_list(int num);
t_stack				*stack_init(char **av);
int					check_dups(t_stack *list);
int					sort_list(t_stack *stacka);
void				swap(t_stack **stack);
int					check_sort(t_stack **stacka);
void				pstack(t_stack **stack);
int					check_args(int ac, char **args);
void				list_add(t_stack **list, int num);
void				list_del(t_stack **list);

#endif
