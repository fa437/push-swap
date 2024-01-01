/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:47 by fasare            #+#    #+#             */
/*   Updated: 2023/12/26 04:37:14 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	min_value(t_node *head)
{
	t_node	*current;
	int		min_value;

	current = head;
	min_value = current->data;
	while (current)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
		}
		current = current->next;
	}
	return (min_value);
}

int	max_value(t_node *head)
{
	t_node	*current;
	int		max_value;

	current = head;
	max_value = current->data;
	while (current)
	{
		if (current->data > max_value)
		{
			max_value = current->data;
		}
		current = current->next;
	}
	return (max_value);
}

int	min_position(t_node *head)
{
	int		position;
	int		current_position;
	int		min_value;
	t_node	*current;

	position = 0;
	current_position = 0;
	current = head;
	min_value = current->data;
	while (current)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
			position = current_position;
		}
		current_position++;
		current = current->next;
	}
	return (position);
}

int	max_position(t_node *head)
{
	int		position;
	int		current_position;
	int		max_value;
	t_node	*current;

	position = 0;
	current_position = 0;
	current = head;
	max_value = current->data;
	while (current)
	{
		if (current->data > max_value)
		{
			max_value = current->data;
			position = current_position;
		}
		current_position++;
		current = current->next;
	}
	return (position);
}
