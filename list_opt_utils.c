/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_opt_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:01 by fasare            #+#    #+#             */
/*   Updated: 2024/01/01 08:29:19 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate(t_node *a, t_node *b, t_node **new_a, t_node **new_b)
{
	
	t_node	 *current;
	
	current = a;
	while (current)
	{
		insert_end(current->data, new_a);
		current = current->next;
	}
	current = b;
	{
		insert_end(current->data, new_b);
		current = current->next;
	}
}

void	cost_div2(t_node **a, t_node **b, t_node **x, int *i)
{
	while ((node_pos(*x, *b) > midpoint(*b) && node_pos(*x, *b) != 0)
		&& (target(*x, *a) > midpoint(*a) && target(*x, *a) != 0))
	{
		reverselist(a, b, 'R');
		*i = *i + 1;
	}
	while ((node_pos(*x, *b) == 0 || node_pos(*x, *b) <= midpoint(*b))
		&& (target(*x, *a) > midpoint(*a) && target(*x, *a) != 0))
	{
		reverselist(a, b, 'a');
		*i = *i + 1;
	}
	while ((target(*x, *a) == 0 || target(*x, *a) <= midpoint(*a))
		&& (node_pos(*x, *b) > midpoint(*b) && node_pos(*x, *b) != 0))
	{
		reverselist(b, a, 'b');
		*i = *i + 1;
	}
}

void	cost_div1(t_node **a, t_node **b, t_node **x, int *i)
{
	while ((node_pos(*x, *b) <= midpoint(*b) && node_pos(*x, *b) != 0)
		&& (target(*x, *a) <= midpoint(*a) && target(*x, *a) != 0))
	{
		rotatelistforward(a, b, 'r');
		*i = *i + 1;
	}
	while ((node_pos(*x, *b) == 0 || node_pos(*x, *b) > midpoint(*b))
		&& (target(*x, *a) <= midpoint(*a) && target(*x, *a) != 0))
	{
		rotatelistforward(a, b, 'a');
		*i = *i + 1;
	}
	while ((target(*x, *a) == 0 || target(*x, *a) > midpoint(*a))
		&& (node_pos(*x, *b) <= midpoint(*b) && node_pos(*x, *b) != 0))
	{
		rotatelistforward(b, a, 'b');
		*i = *i + 1;
	}
}
