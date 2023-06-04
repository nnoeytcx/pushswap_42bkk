/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:24:37 by tpoungla          #+#    #+#             */
/*   Updated: 2022/08/09 00:24:37 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int pos, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	slen;

	if (str == NULL)
		return (NULL);
	if ((int)pos > ft_strlen(str))
		slen = 0;
	else if ((ft_strlen(str) - pos) >= len)
		slen = len;
	else
		slen = ft_strlen(str) - pos;
	sub = (char *)malloc(sizeof(char) * (slen + 1));
	if (!sub || sub == NULL)
		return (0);
	i = pos;
	j = 0;
	while (j < slen)
		sub[j++] = str[i++];
	sub[j] = '\0';
	return (sub);
}
