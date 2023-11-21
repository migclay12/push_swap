/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:55 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/15 11:20:54 by miggonza         ###   ########.fr       */
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

//NEW LISTS
t_list2	*ft_lstnew2(int num);
t_list2	*ft_lstlast2(t_list2 *lst);
void	ft_lstadd_back2(t_list2 **lst, t_list2 *new);
int		ft_lstsize2(t_list2 *lst);

//PREVIOUS COMPROBATIONS
void	ft_printerror(char *error);
int		ft_isnum(char *num);
int		ft_check_rep(int num, char **argv, int i);
void	ft_get_num(int argc, char **argv);

//INSTRUCTIONS
void	sa(t_list2 **stack_a);
void	sb(t_list2 **stack_b);
void	ss(t_list2 **stack_a, t_list2 **stack_b);
void	pa(t_list2 **stack_a, t_list2 **stack_b);
void	pb(t_list2 **stack_b, t_list2 **stack_a);
void	ra(t_list2 **stack_a);
void	rb(t_list2 **stack_b);
void	rr(t_list2 **stack_a, t_list2 **stack_b);
void	rra(t_list2 **stack_a);
void	rrb(t_list2 **stack_b);
void	rrr(t_list2 **stack_a, t_list2 **stack_b);

void	ft_swap(t_list2 **stack);
void	ft_push(t_list2 **stack_a, t_list2 **stack_b);
void	ft_rotate(t_list2 **stack);
void	ft_reverse_rotate(t_list2 **stack);

//SAVE LIST
void	ft_sort_num(t_list2 **stack_a, int argc, char **argv);
void	ft_add_index(t_list2 **stack_a);

//TESTS
int		ft_sorted(t_list2 **stack);
void	ft_test3(t_list2 **stack_a);
void	ft_test5(t_list2 **stack_a, t_list2 **stack_b);
void	ft_testall(t_list2 **stack_a, t_list2 **stack_b);

//MINE
void	ft_print_stack(char c, t_list2 **stack);

#endif