/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:47 by fasare            #+#    #+#             */
/*   Updated: 2024/01/09 08:47:34 by fasare           ###   ########.fr       */
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
