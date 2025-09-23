/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:05:00 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list2 **stack)
{
	t_list2	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_testall(t_list2 **stack_a, t_list2 **stack_b)
{
	t_list2	*head;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head = *stack_a;
	size = ft_lstsize2(head);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (ft_lstsize2(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
