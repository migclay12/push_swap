/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:36:09 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/13 16:44:02 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list2  **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	pa(t_list2 **stack_a, t_list2 **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	ra(t_list2 **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_list2 **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}