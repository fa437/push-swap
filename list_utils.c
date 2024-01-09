/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:44 by fasare            #+#    #+#             */
/*   Updated: 2024/01/09 08:28:13 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	midpoint(t_node *head)
{
	return (get_size(head) / 2);
}

int	isreverse(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next)
	{
		if (current->data < current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	issorted(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_min(t_node *head, int min)
{
	if (head->data == min)
		return (1);
	return (0);
}

int	check_max(t_node *head, int max)
{
	if (head->data == max)
		return (1);
	return (0);
}
