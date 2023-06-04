/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:54:57 by tpoungla          #+#    #+#             */
/*   Updated: 2022/07/23 04:40:36 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument < 'a' || argument > 'z') && (argument < 'A' || argument > 'Z')
		&& (argument < '0' || argument > '9'))
		return (0);
	return (1);
}
