/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:03:10 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/27 08:19:23 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*add_nodes(int num)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
		return (NULL);
	new->prev = NULL;
	new->val = num;
	new->next = NULL;
	return (new);
}

void		head_add(t_stack **list, t_stack *node)
{
	t_stack	*temp;

	if (!list || !node)
		return ;
	temp = *list;
	if (temp)
	{
		temp->prev = node;
		node->next = *list;
		node->prev = NULL;
		*list = node;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
		*list = node;
	}
}

void		tail_add(t_stack **list, t_stack *node)
{
	t_stack	*temp;

	if (!list || !node)
		return ;
	temp = *list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
}

void		list_del(t_stack **list)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *list;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*list = NULL;
}

t_stack		*stack_init(char **av)
{
	int		i;
	int		j;
	char	**cur;
	t_stack	*head;
	t_stack	*node;

	i = 1;
	j = 0;
	cur = ft_strsplit(av[i++], ' ');
	head = add_nodes(ft_atoi(cur[j++]));
	while (av[i])
	{
		j = 0;
		cur = ft_strsplit(av[i], ' ');
		while (cur[j])
		{
			node = add_nodes(ft_atoi(cur[j++]));
			tail_add(&head, node);
		}
		i++;
		free_her(cur);
	}
	return (head);
}
