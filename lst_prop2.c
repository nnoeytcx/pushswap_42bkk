/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_prop2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:48:59 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/12 19:10:40 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	get_lst_pos(t_list *lst, int *num)
{
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(lst);
	while (lst -> next)
	{
		i = 0;
		while (i < len)
		{
			if (num[i] == lst -> content)
				lst -> index = i + 1;
			i++;
		}
		lst = lst -> next;
	}
	i = 0;
	while (i < len)
	{
		if (num[i] == lst -> content)
			lst -> index = i + 1;
		i++;
	}
}

void	ft_print_lstind(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp -> next != NULL)
	{
		printf("[%d] -> ", tmp -> index);
		tmp = tmp -> next;
	}
	printf("[%d]\n", tmp -> index);
}

int	is_sorted(t_list *lst)
{
	t_list	*tmp;
	t_list	*next;
	int		a;
	int		b;

	tmp = lst;
	while (tmp -> next != NULL)
	{
		a = tmp -> content;
		next = tmp -> next;
		b = next -> content;
		if (a > b)
		{
			return (1);
		}
		tmp = tmp -> next;
	}
	return (0);
}

void	ft_freestack(t_list **lst)
{
	t_list	*tmp;

	while ((*lst))
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
