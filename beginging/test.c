/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:59:11 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/13 22:04:58 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test3(t_list2 **stack_a)
{
	t_list2	*head;
	int		n[3];

	head = *stack_a;
	n[0] = head->index;
	n[1] = head->next->index;
	n[2] = head->next->next->index;
	if (n[0] > n[1] && n[1] < n[2])
		sa(stack_a);
	if (n[0] == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (n[0] == 3 && n[1] == 2)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (n[0] == 3 && n[1] == 1)
		ra(stack_a);
	if (n[0] == 2 && n[1] == 3)
		rra(stack_a);
}
