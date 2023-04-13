/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:19 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/13 16:44:01 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list2  **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	pb(t_list2 **stack_b, t_list2 **stack_a)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	rb(t_list2 **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rrb(t_list2 **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}
