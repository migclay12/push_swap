/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:19 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/15 11:33:15 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list2 **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	pb(t_list2 **stack_b, t_list2 **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}

void	rb(t_list2 **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rrb(t_list2 **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}
