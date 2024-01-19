/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:47 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 14:03:17 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* iteratre thtough the linked list and return the size */
int	get_size(t_node *head)
{
	t_node	*current;
	int		i;

	current = head;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/* itereate the head, find the min value
	and retuen it.*/
int	min_value(t_node *head)
{
	t_node	*current;
	int		min;

	current = head;
	min = current->data;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
		}
		current = current->next;
	}
	return (min);
}

/* iterate the the head find the max value in
	head and retuen the valua*/
int	max_value(t_node *head)
{
	t_node	*current;
	int		max;

	current = head;
	max = current->data;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
		}
		current = current->next;
	}
	return (max);
}

/* find & return the pos of min value in a linked list.*/
int	min_position(t_node *head)
{
	int		position;
	int		min;
	int		min_position;
	t_node	*current;

	position = 0;
	current = head;
	min = current->data;
	min_position = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_position = position;
		}
		position++;
		current = current->next;
	}
	return (min_position);
}

/* find & return the pos of max value in a linked list.*/
int	max_position(t_node *head)
{
	int		position;
	int		max;
	int		max_position;
	t_node	*current;

	position = 0;
	current = head;
	max = current->data;
	max_position = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_position = position;
		}
		position++;
		current = current->next;
	}
	return (max_position);
}
