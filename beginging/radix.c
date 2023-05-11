/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:05:00 by miggonza          #+#    #+#             */
/*   Updated: 2023/05/11 15:47:06 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	ft_max_bites(t_list *list)
{
	int	nbr_bites;
	int	max;

	max = ft_lstsize(list) - 1;
	nbr_bites = 0;
	while ((max >> nbr_bites) != 0)
		nbr_bites++;
	return (nbr_bites);
}
*/

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

/*
    x & 1 produces a value that is either 1 or 0, depending on the least significant bit of x:
    if the last bit is 1, the result of x & 1 is 1; otherwise, it is 0. This is a bitwise AND operation

    x >>= 1 means "set x to itself shifted by one bit to the right". The expression evaluates to the
    new value of x after the shift


    x & 1 is equivalent to x % 2
    x >> 1 is equivalent to x / 2
*/