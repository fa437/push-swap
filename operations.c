/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:41 by fasare            #+#    #+#             */
/*   Updated: 2024/01/09 10:02:01 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
