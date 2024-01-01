/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:04 by fasare            #+#    #+#             */
/*   Updated: 2024/01/01 06:42:10 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

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

void	clear(t_node **head)
{
	t_node	*current;
	t_node	*next_node;	

	current = *head;
	if (head == NULL || *head == NULL)
	{
		return ;
	}
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}
// check line 77 to 82, current = head must be 
// after assignment. it might change the whole operation.
// clear.c is create.c