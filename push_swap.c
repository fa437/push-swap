/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:28:11 by fasare            #+#    #+#             */
/*   Updated: 2024/01/01 09:19:39 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a, t_node **b)
{
	if (get_size(*a) == 3 && (!issorted(*a)))
	{
		if (max_position(*a) == 0)
			rotate(a, b, 'a');
		if (min_position(*a) == 2)
			reverse(a, b, 'a');
		if (min_position(*a) == 0 && !issorted(*a))
			reverse(a, b, 'a');
		if (!issorted(*a))
			swap(a, b, 'a');
		sort_three(a, b);
	}
}

void	costbenefit(t_node **a, t_node **b)
{
	t_node	*x;

	x = NULL;
	x = findminimumcostnode(b);
	while ((node_pos(x, *b) <= midpoint(*b) && node_pos(x, *b) != 0)
		&& (target(x, *a) <= midpoint(*a) && target(x, *a) != 0))
	rotate(a, b, 'r');
	while ((node_pos(x, *b) == 0 || node_pos(x, *b) > midpoint(*b))
		&& (target(x, *a) <= midpoint(*a) && target(x, *a) != 0))
	rotate(a, b, 'a');
	while ((target(x, *a) == 0 || target(x, *a) > midpoint(*a))
		&& (node_pos(x, *b) <= midpoint(*b) && node_pos(x, *b) != 0))
	rotate(b, a, 'b');
	while ((node_pos(x, *b) > midpoint(*b) && node_pos(x, *b) != 0)
		&& (target(x, *a) > midpoint(*a) && target(x, *a) != 0))
	reverse(a, b, 'R');
	while ((node_pos(x, *b) == 0 || node_pos(x, *b) <= midpoint(*b))
		&& (target(x, *a) > midpoint(*a) && target(x, *a) != 0))
	reverse(a, b, 'a');
	while ((target(x, *a) == 0 || target(x, *a) <= midpoint(*a))
		&& (node_pos(x, *b) > midpoint(*b) && node_pos(x, *b) != 0))
	reverse(b, a, 'b');
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (get_size(*a) == 2 && !issorted(*a))
		swap(a, &b, 'a');
	else if (!issorted(*a) && get_size(*a) > 2)
	{
		while (!issorted(*a) && (get_size(*a) > 3))
			push(a, &b, 'b');
		sort_three(a, &b);
		while (b)
		{
			assigncosts(a, &b);
			costbenefit(a, &b);
			push(&b, a, 'a');
		}
		while (min_position(*a) <= midpoint(*a) && min_position(*a) != 0)
			rotate(a, &b, 'a');
		while (min_position(*a) > midpoint(*a) && min_position(*a) != 0)
			reverse(a, &b, 'a');
	}
	clear(&b);
}

int	main(int argc, char **argv)
{
	t_node	*head;

	head = NULL;
	if (argc == 1)
		return (0);
	if (argc > 1)
	{
		if (!validate(argv))
			return (2);
		get_list(argv, &head);
		if (has_dup(head))
			return (3);
		push_swap(&head);
		clear(&head);
		return (0);
	}
	return (4);
}
