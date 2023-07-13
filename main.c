/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:37:30 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/13 22:08:33 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**tab;
	t_list	*lst;
	int		i;

	lst = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		if (check_null(argc, argv))
			tab = arg_to_tab(argc, argv);
		else
			exit (0);
	}
	if (valid_lst_tab(tab) && dup_checker(tab))
	{
		init_lst(tab, lst);
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	make_lst_str(t_list **lst, char *str)
{
	int		nb;
	t_list	*var;

	nb = ft_atoi(str);
	var = ft_lstnew(nb);
	ft_lstadd_back(lst, var);
	return (1);
}

char	**arg_to_tab(int argc, char *argv[])
{
	int		i;
	char	*str;
	char	**tab;
	char	*tmp;

	i = 2;
	str = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = tmp;
		i++;
	}
	tab = ft_split(str, ' ');
	free(str);
	return (tab);
}

int	valid_lst_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!valid_str(tab[i]))
		{
			ft_putstr_fd(ERR, 2);
			return (0);
		}
		if (ft_atoi(tab[i]) != ft_atol(tab[i]))
		{
			ft_putstr_fd(ERR, 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
