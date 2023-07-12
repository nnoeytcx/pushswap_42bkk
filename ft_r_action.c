/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:04:08 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/11 14:39:43 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp -> next = NULL;
	ft_lstadd_back(stack, tmp);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp -> next = NULL;
	ft_lstadd_back(stack, tmp);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp -> next = NULL;
	ft_lstadd_back(stack_a, tmp);
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp -> next = NULL;
	ft_lstadd_back(stack_b, tmp);
	ft_putstr_fd("rr\n", 1);
}
