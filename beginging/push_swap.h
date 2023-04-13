/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:55 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/13 21:06:39 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_list2
{
	int				number;
	int				index;
	struct s_list2	*next;
}				t_list2;

t_list2	*ft_lstnew2(int num);
t_list2	*ft_lstlast2(t_list2 *lst);
void	ft_lstadd_back2(t_list2 **lst, t_list2 *new);

void	ft_printerror(char *error);
int		ft_check_rep(int num, char **argv, int i);
int		ft_isnum(char *num);
void	ft_get_num(int argc, char **argv);
int		ft_lstsize2(t_list2 *lst);

void	ft_swap(t_list2 **stack);
void	ft_push(t_list2 **stack_a, t_list2 **stack_b);
void	ft_rotate(t_list2 **stack);
void	ft_reverse_rotate(t_list2 **stack);

void	sa(t_list2  **stack_a);
void	sb(t_list2  **stack_b);
void	ss(t_list2  **stack_a, t_list2 **stack_b);
void	pa(t_list2 **stack_a, t_list2 **stack_b);
void	pb(t_list2 **stack_b, t_list2 **stack_a);
void	ra(t_list2 **stack_a);
void	rb(t_list2 **stack_b);
void	rr(t_list2 **stack_a, t_list2 **stack_b);
void	rra(t_list2 **stack_a);
void	rrb(t_list2 **stack_b);
void	rrr(t_list2 **stack_a, t_list2 **stack_b);

void    ft_test3(t_list2 **stack_a);

#endif