/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:04 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 12:48:49 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Return last node in ll
int	get_last(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next)
	{
		current = current->next;
	}
	return (current->data);
}

// return position of node x
int	node_pos(t_node *x, t_node *head)
{
	t_node	*current;
	int		position;

	position = 0;
	current = head;
	while (current && current->data != x->data)
	{
		position++;
		current = current->next;
	}
	return (position);
}

//iterates ll, track max node with the max value.
t_node	*max_node(t_node *head)
{
	t_node	*current;
	t_node	*max;
	int		max_value;

	if (head == NULL)
	{
		return (NULL);
	}
	current = head;
	max = head;
	max_value = current->data;
	while (current)
	{
		if (current->data > max_value)
		{
			max_value = current->data;
			max = current;
		}
		current = current->next;
	}
	return (max);
}

//check if it is sorted, iterate list until appropriate pos for x
//Determines target pos to insert node into sorted or unsorted ll.
void	target_div(t_node *x, t_node *a, t_node *current, int *i)
{
	while (issorted(a) && current && x->data > current->data)
	{
		*i = *i + 1;
		current = current->next;
	}
	if (!issorted(a))
	{
		if (x->data < get_last(a))
		{
			current = max_node(a);
			current = current->next;
			*i = max_position(a) + 1;
		}
		while (current && x->data > current->data)
		{
			*i = *i + 1;
			current = current->next;
		}
	}
}

// determining the pos for inserting x, if max or min
int	target(t_node *x, t_node *a)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a;
	if (x->data < min_value(a) || x->data > max_value(a))
		i = min_position(a);
	else if (x->data > min_value(a) && x->data < max_value(a))
	{
		target_div(x, a, current, &i);
	}
	return (i);
}

/*
find the max node, determine target pos for inserting nodes
based on the nature of the list.
*/