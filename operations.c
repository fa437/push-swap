/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:41 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 14:17:33 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap the top 2 elements on a & b or both */
void	swap(t_node **a, t_node **b, char c)
{
	t_node	*current;
	t_node	*next_node;

	current = *a;
	next_node = current->next;
	current->next = next_node->next;
	next_node->next = current;
	*a = next_node;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	if (c == 'b')
		ft_putendl_fd("sb", 1);
	if (c == 's')
	{
		swap(b, a, 'c');
		ft_putendl_fd("ss", 1);
	}
}

/* push elements from top of a to b or otherwise */
void	push(t_node **a, t_node **b, char c)
{
	t_node	*current;
	t_node	*next_node;

	current = *a;
	next_node = current->next;
	current->next = *b;
	*b = current;
	*a = next_node;
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	if (c == 'b')
		ft_putendl_fd("pb", 1);
}

/* rotate top elements to the bottom of a, b or both*/
void	rotate(t_node **a, t_node **b, char c)
{
	t_node	*current;
	t_node	*prev;
	t_node	*last;

	current = *a;
	prev = current->next;
	last = current;
	while (last->next)
		last = last->next;
	last->next = current;
	current->next = NULL;
	*a = prev;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	if (c == 'b')
		ft_putendl_fd("rb", 1);
	if (c == 'r')
	{
		rotate(b, a, 'c');
		ft_putendl_fd("rr", 1);
	}
}

/* reverse elements in a, b or both*/
void	reverse(t_node **a, t_node **b, char c)
{
	t_node	*current;
	t_node	*prev;
	t_node	*last;

	current = *a;
	prev = current;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	last->next = current;
	prev->next = NULL;
	*a = last;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	if (c == 'b')
		ft_putendl_fd("rrb", 1);
	if (c == 'R')
	{
		reverse(b, a, 'c');
		ft_putendl_fd("rrr", 1);
	}
}
