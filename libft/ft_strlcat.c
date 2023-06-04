/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:05:42 by tpoungla          #+#    #+#             */
/*   Updated: 2022/08/05 22:05:42 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	start;

	if (size == 0)
		return (ft_strlen(src));
	i = (size_t)ft_strlen(dst);
	if (i >= size)
		return (size + ft_strlen(src));
	start = i;
	if (size != 0)
	{
		while (i < size - 1 && src[i - start])
		{
			dst[i] = src[i - start];
			i++;
		}
		dst[i] = '\0';
	}
	return (start + ft_strlen(src));
}
