/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_opt_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:01 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 12:57:50 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* iterate each node in a & b, insert a new node with
 the same data at the end of new_a & new_b */
void	duplicate(t_node *a, t_node *b, t_node **new_a, t_node **new_b)
{
	t_node	*current;

	current = a;
	while (current)
	{
		insert_end(current->data, new_a);
		current = current->next;
	}
	current = b;
	while (current)
	{
		insert_end(current->data, new_b);
		current = current->next;
	}
}

/* Rotates nodes between two a & b considering pos & targets.
 The dir is determined by the 'R', 'a', or 'b' argument */
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

/* Rotate nodes between a & b, in the forward dir, considering
 pos and targets. rotation is determined by the 'r', 'a', or 'b' arg */
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
