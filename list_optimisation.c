/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_optimisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:50 by fasare            #+#    #+#             */
/*   Updated: 2024/01/19 13:26:18 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate the linked list forward by moving the first element
 to the end. if dir is r thne recursively rotate the sec list. */
void	rotatelistforward(t_node **list, t_node **secondaryList, char dir)
{
	t_node	*current;
	t_node	*first;
	t_node	*last;

	current = *list;
	first = current->next;
	last = current;
	while (last->next)
	{
		last = last->next;
	}
	last->next = current;
	current->next = NULL;
	*list = first;
	if (dir == 'r')
		rotatelistforward(secondaryList, list, 'c');
}

/* reverse the linked list. if dir is R then
 recursively reverse the sec list. */
void	reverselist(t_node **list, t_node **secondarylist, char dir)
{
	t_node	*current;
	t_node	*prev;
	t_node	*nextnode;

	current = *list;
	prev = current;
	while (prev->next->next)
	{
		prev = prev->next;
	}
	nextnode = prev->next;
	nextnode->next = current;
	prev->next = NULL;
	*list = nextnode;
	if (dir == 'R')
		reverselist(secondarylist, list, 'c');
}

/* Calculate the cost on the node on the list_a & list_b.
 dup list and check the cost involved. */
int	calculatecost(t_node *list_a, t_node *list_b, t_node *node)
{
	int		cost;
	t_node	*copy_a;
	t_node	*copy_b;

	cost = 0;
	copy_a = NULL;
	copy_b = NULL;
	duplicate(list_a, list_b, &copy_a, &copy_b);
	cost_div1(&copy_a, &copy_b, &node, &cost);
	cost_div2(&copy_a, &copy_b, &node, &cost);
	clear(&copy_a);
	clear(&copy_b);
	return (cost);
}

/* assign cost to every noode on list_b.
 calculate the cost on the current node */
void	assigncosts(t_node **list_a, t_node **list_b)
{
	t_node	*current;

	current = *list_b;
	while (current)
	{
		current->cost = calculatecost(*list_a, *list_b, current);
		current = current->next;
	}
}

/* find node with min cost and return it */
t_node	*findminimumcostnode(t_node **list)
{
	int		mincost;
	t_node	*current;
	t_node	*mincostnode;

	current = *list;
	mincostnode = current;
	mincost = current->cost;
	while (current)
	{
		if (current->cost < mincost)
		{
			mincost = current->cost;
			mincostnode = current;
		}
		current = current->next;
	}
	return (mincostnode);
}
