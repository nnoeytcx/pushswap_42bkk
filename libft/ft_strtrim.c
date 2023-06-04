/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:31:14 by tpoungla          #+#    #+#             */
/*   Updated: 2022/11/06 23:31:14 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	if_trim(char const *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (if_trim(set, s1[start]) == 1)
		start++;
	while (end > start && if_trim(set, s1[end - 1]) == 1)
		end--;
	len = end - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
