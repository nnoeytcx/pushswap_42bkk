/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:20:22 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/12 20:41:32 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num(const char *str, int i)
{
	int	num;

	num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + str[i] - '0';
			i++;
		}
		else
			break ;
	}
	return (num);
}

int	check_space(const char *c, int i)
{
	while (c[i])
	{
		if (c[i] == '\r' || c[i] == '\n' || c[i] == '\f' )
			i++;
		else if (c[i] == '\v' || c[i] == '\t' || c[i] == ' ' )
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	i = check_space(str, i);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (get_num(str, i) * neg);
}

long	get_longnum(const char *str, int i)
{
	long	num;

	num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + str[i] - '0';
			i++;
		}
		else
			break ;
	}
	return (num);
}

long	ft_atol(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	i = check_space(str, i);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (get_longnum(str, i) * neg);
}
