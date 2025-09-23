/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:36:09 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list2 **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	pa(t_list2 **stack_a, t_list2 **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	ra(t_list2 **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rra(t_list2 **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}
