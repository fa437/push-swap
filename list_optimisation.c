/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_optimisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:50 by fasare            #+#    #+#             */
/*   Updated: 2024/01/01 08:19:52 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	reverselist(t_node **list, t_node **secondarylist, char dir)
{
	t_node	*current;
	t_node	*prev;
	t_node	*nextnode;

	current = *list;
	prev = NULL;
	nextnode = NULL;
	while (current->next)
	{
		nextnode = current->next;
		current->next = prev;
		prev = current;
		current = nextnode;
	}
	current->next = prev;
	*list = current;
	if (dir == 'R')
		reverselist(secondarylist, list, 'c');
}

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
