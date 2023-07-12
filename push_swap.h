/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:43:12 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/12 22:45:16 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

# define ERR "Error\n"
# define ARG_AREN_INT "some arguments aren't integers\n"
# define ARG_BIGG_INT "some arguments are bigger than an integer\n"
# define DUP_ARG "there are duplicate arguments\n"

int		make_lst_str(t_list **lst, char *str);
char	**arg_to_tab(int argc, char *argv[]);
int		valid_lst_tab(char **tab);
void	ft_putstr_fd(char *s, int fd);

//lst prop1
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_print_lst(t_list **lst);

//lst prop2
int		ft_lstsize(t_list *lst);
void	get_lst_pos(t_list *lst, int *num);
void	ft_print_lstind(t_list **lst);
int		is_sorted(t_list *lst);
void	ft_freestack(t_list **lst);

//tool1
int		ft_strlen(const char *s);
void	ft_get_str(char const *s, char c, char **res);
void	ft_get_tab(char const *s, char c, char **res);
char	**ft_split(char *s, char c);
int		ft_isdigit(int arg);

//tool2
int		get_num(const char *str, int i);
int		check_space(const char *c, int i);
int		ft_atoi(const char *str);
long	get_longnum(const char *str, int i);
long	ft_atol(const char *str);

//tool3
int		valid_str(char *str);
int		dup_checker(char **tab);
char	*ft_strjoin(char *s1, char *s2);
int		*get_arr(t_list *lst);
int		*sort_arr(int *num, int len);

//ft_push_swap
void	pushswap_init(t_list **lst1);
void	ft_split5(t_list **lst1, t_list **lst2);
void	sort_5(t_list **lst1, t_list **lst2);
void	ft_sortradix(t_list **lst1, t_list **lst2, int len);
void	sort_3(t_list **stack);

//ft_p_action
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
char	*ft_strdup(const char *str);
void	init_lst(char **tab, t_list *lst);
int		check_null(int argc, char *argv[]);

//ft_r_action
void	ft_ra(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_rr(t_list **stack_a, t_list **list_b);

//ft_rr_action
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_a, t_list **list_b);

//ft_s_action
void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);

#endif
