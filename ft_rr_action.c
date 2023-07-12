/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:04:10 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/11 14:57:10 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = ft_lstlast((*stack));
	(*stack)->next = tmp;
	while (tmp->next != (*stack))
		tmp = tmp ->next;
	tmp->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = ft_lstlast((*stack));
	(*stack)->next = tmp;
	while (tmp->next != (*stack))
		tmp = tmp ->next;
	tmp->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = ft_lstlast((*stack_a));
	(*stack_a)->next = tmp;
	while (tmp->next != (*stack_a))
		tmp = tmp ->next;
	tmp->next = NULL;
	tmp = (*stack_b);
	(*stack_b) = ft_lstlast((*stack_b));
	(*stack_b)->next = tmp;
	while (tmp->next != (*stack_b))
		tmp = tmp ->next;
	tmp->next = NULL;
	ft_putstr_fd("rrr\n", 1);
}
