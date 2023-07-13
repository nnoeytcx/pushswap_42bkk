/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:04:12 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/13 22:08:22 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp -> next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp -> next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("pb\n", 1);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (len--)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

void	init_lst(char **tab, t_list *lst)
{
	int	i;
	int	*num;

	i = 0;
	while (tab[i])
		make_lst_str(&lst, tab[i++]);
	if (ft_lstsize(lst) != 0 && is_sorted(lst))
	{
		num = get_arr(lst);
		get_lst_pos(lst, sort_arr(num, ft_lstsize(lst)));
		free(num);
		pushswap_init(&lst);
	}
	else if (ft_lstsize(lst) != 0 && !is_sorted(lst))
		ft_freestack(&lst);
	else
	{
		ft_putstr_fd(ERR, 2);
		ft_freestack(&lst);
	}
}

int	check_null(int argc, char *argv[])
{
	int	i;
	int	j;
	int	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		c = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				c++;
			j++;
		}
		if (c == ft_strlen(argv[i]) || ft_strlen(argv[i]) == 0)
		{
			ft_putstr_fd(ERR, 2);
			return (0);
		}
		i++;
	}
	return (1);
}
