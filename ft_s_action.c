/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:04:11 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/11 14:54:02 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp -> next = (*stack)->next;
	(*stack)->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp -> next = (*stack)->next;
	(*stack)->next = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp -> next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp -> next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	ft_putstr_fd("ss\n", 1);
}
