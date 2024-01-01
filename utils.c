/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:53 by fasare            #+#    #+#             */
/*   Updated: 2024/01/01 06:58:25 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validint(char **str)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			c = str[i][j];
			if ((c >= '0' && c <= '9') || c == '-' || c == '+')
			{
				if (((c == '+' || c == '-') && !ft_isdigit(str[i][j + 1]))
					|| ((c == '+' || c == '-') && ft_isdigit(str[i][j - 1])))
					return (0);
				j++;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkint(char *str)
{
	int		i;
	int		isneg;
	long	nbr;

	i = 0;
	isneg = 0;
	nbr = 0;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (isneg == 1)
		nbr *= -1;
	if (!(nbr >= -2147483648 && nbr <= 2147483647))
		return (0);
	return (1);
}

int	checkdup(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((ft_strncmp(str[i], str[j], ft_strlen(str[j])) == 0)
				&& (ft_strlen(str[i]) == ft_strlen(str[j])))
			{
				ft_putendl_fd("Error: there are duplicates", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	validate(char **str)
{
	int	i;

	i = 1;
	if (!validint(str))
	{
		ft_putendl_fd("Error: some arguments aren't integers", 2);
		return (0);
	}
	if (checkdup(str))
		return (0);
	while (str[i])
	{
		if (!checkint(str[i]))
		{
			ft_putendl_fd("Error: some arguments are out of integer range", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
