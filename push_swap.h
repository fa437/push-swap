/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:40:56 by fasare            #+#    #+#             */
/*   Updated: 2024/01/01 08:27:02 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	int				cost;
	struct s_node	*next;
}	t_node;

int		get_last(t_node *head);
int		node_pos(t_node *x, t_node *head);
t_node	*max_node(t_node *head);
void	target_div(t_node *x, t_node *a, t_node *current, int *i);
int		target(t_node *x, t_node *a);
void	get_list(char **str, t_node **head);
void	insert_end(int x, t_node **head);
int		has_dup(t_node *head);
void	clear(t_node **head);
void	duplicate(t_node *a, t_node *b, t_node **new_a, t_node **new_b);
void	cost_div2(t_node **a, t_node **b, t_node **x, int *i);
void	cost_div1(t_node **a, t_node **b, t_node **x, int *i);
void	rotatelistforward(t_node **list, t_node **secondaryList, char dir);
void	reverselist(t_node **list, t_node **secondarylist, char dir);
int		calculatecost(t_node *list_a, t_node *list_b, t_node *node);
void	assigncosts(t_node **list_a, t_node **list_b);
t_node	*findminimumcostnode(t_node **list);
int		midpoint(t_node *head);
int		isreverse(t_node *head);
int		issorted(t_node *head);
int		check_min(t_node *head, int min);
int		check_max(t_node *head, int max);
int		get_size(t_node *head);
int		min_value(t_node *head);
int		max_value(t_node *head);
int		min_position(t_node *head);
int		max_position(t_node *head);
void	swap(t_node **a, t_node **b, char c);
void	push(t_node **a, t_node **b, char c);
void	rotate(t_node **a, t_node **b, char c);
void	reverse(t_node **a, t_node **b, char c);
void	sort_three(t_node **a, t_node **b);
void	costbenefit(t_node **a, t_node **b);
void	push_swap(t_node **a);
int		main(int argc, char **argv);
int		validint(char **str);
int		checkint(char *str);
int		checkdup(char **str);
int		validate(char **str);

#endif
