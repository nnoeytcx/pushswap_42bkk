/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:34:53 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/12 21:02:59 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack)
{
	int	fst;
	int	snd;
	int	trd;

	fst = (*stack)->content;
	snd = (*stack)->next->content;
	trd = (*stack)->next->next->content;
	if (fst < trd && fst < snd && trd < snd)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (snd < fst && snd < trd && fst < trd)
		ft_sa(stack);
	else if (snd < trd && snd < fst && trd < fst)
		ft_ra(stack);
	else if (trd < fst && trd < snd && fst < snd)
		ft_rra(stack);
	else if (trd < snd && trd < fst && snd < fst)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
}

void	ft_split5(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		len;

	tmp = (*lst1);
	tmp2 = (*lst2);
	len = ft_lstsize(tmp);
	while (len > 3)
	{
		if (tmp -> index <= 2)
		{
			ft_pb(lst1, lst2);
			len--;
		}
		else
			ft_ra(lst1);
		tmp = (*lst1);
	}
}

void	sort_5(t_list **lst1, t_list **lst2)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	ft_split5(lst1, lst2);
	tmp_a = (*lst1);
	tmp_b = (*lst2);
	if (tmp_b->content < tmp_b->next->content)
		ft_sb(lst2);
	sort_3(lst1);
	ft_pa(lst1, lst2);
	ft_pa(lst1, lst2);
}

void	ft_sortradix(t_list **lst1, t_list **lst2, int len)
{
	int	i;
	int	j;
	int	x;
	int	count;

	i = 0;
	while (((*lst1)->index >> i) > 0)
	{
		x = 0;
		count = 0;
		while (x++ < len)
		{
			if (((*lst1)->index >> i & 1) == 0)
				ft_pb(lst1, lst2);
			else if (((*lst1)->index >> i & 1) == 1)
				ft_ra(lst1);
			count = ft_lstsize(*lst2);
		}
		j = 0;
		while (j++ < count)
			ft_pa(lst1, lst2);
		i++;
	}
}

void	pushswap_init(t_list **lst1)
{
	t_list	*lst2;
	int		len;

	lst2 = NULL;
	len = ft_lstsize((*lst1));
	if (len == 2)
		ft_sa(lst1);
	else if (len == 3)
		sort_3(lst1);
	else if (len == 5)
		sort_5(lst1, &lst2);
	else
		ft_sortradix(lst1, &lst2, len);
	ft_freestack(lst1);
}
