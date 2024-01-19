/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:04 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 12:42:39 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* convert each str to an int using ft_atoi.
insert the int at the end of the list */
void	get_list(char **str, t_node **head)
{
	int	i;

	i = 1;
	while (str[i])
	{
		insert_end(ft_atoi(str[i]), head);
		i++;
	}
}

/*insert new node with a specified value at
the end of a linked list*/
void	insert_end(int x, t_node **head)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	new_node->data = x;
	new_node->cost = -5;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
}

/*Iterates through the linked list.
for every node compare nodes, if it has dup.*/
int	has_dup(t_node *head)
{
	t_node	*current;
	t_node	*compare;

	current = head;
	compare = current;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->data == compare->data)
			{
				ft_putendl_fd("Error: there are duppplicates", 2);
				return (1);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

/*frees each node in the linked list until list is empty.
it takes a pointer to the head of the list, and after
execution, the head is set to NULL*/
void	clear(t_node **head)
{
	t_node	*current;

	if (head == NULL)
		return ;
	while (*head != NULL)
	{
		current = *head;
		*head = current->next;
		free(current);
		current = *head;
	}
}
/* create linked list, insert nodes at end,
 check for duplicates and then free all memory allocated*/
