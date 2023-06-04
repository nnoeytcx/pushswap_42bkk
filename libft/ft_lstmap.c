/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:01:45 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/16 03:46:32 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*sec;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew(f(lst -> content));
	if (!res)
		return (NULL);
	sec = res;
	next = lst -> next;
	while (next != NULL)
	{
		sec -> next = ft_lstnew(f(next -> content));
		if (!sec)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		next = next -> next;
		sec = sec -> next;
	}
	return (res);
}
