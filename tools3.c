/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:15:48 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/12 22:38:39 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ((i == 0)
				&& ((str[i] == '-' || str[i] == '+'))
				&& ft_strlen(str) != 1))
			i++;
		else
			return (0);
	}
	return (1);
}

int	dup_checker(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			{
				ft_putstr_fd(ERR, 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = ' ';
	i++;
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	*get_arr(t_list *lst)
{
	t_list	*tmp;
	int		len;
	int		i;
	int		*num;

	i = 0;
	len = ft_lstsize(lst);
	num = malloc (sizeof(int) * (len + 1));
	tmp = lst;
	while (tmp -> next != NULL)
	{
		num[i] = tmp -> content;
		i++;
		tmp = tmp -> next;
	}
	num[i] = tmp -> content;
	return (num);
}

int	*sort_arr(int *num, int len)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] > num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (num);
}
