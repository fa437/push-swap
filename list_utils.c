/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:44 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 13:33:25 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get midpoint of the linked list.
	use get_size and divide it */
int	midpoint(t_node *head)
{
	return (get_size(head) / 2);
}

/* check if the list is in reverve order.
 compare current node with next node */
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

/* check if the list is already sorted? */
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

/* check if the head is min value*/
int	check_min(t_node *head, int min)
{
	if (head->data == min)
		return (1);
	return (0);
}

/* check if the head is max value*/
int	check_max(t_node *head, int max)
{
	if (head->data == max)
		return (1);
	return (0);
}
