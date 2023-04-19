/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:59:11 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/19 21:31:04 by miggonza         ###   ########.fr       */
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
	if ((n[0] > n[1] && n[0] < n[2]) || (n[0] > n[1] && n[1] > n[2]))
	{
		sa(stack_a);
		if (n[0] > n[1] && n[1] > n[2])
			rra(stack_a);
	}
	else if (n[0] > n[1] && n[1] < n[2])
		ra(stack_a);
	else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (n[0] < n[1] && n[0] > n[2])
		rra(stack_a);
}

int	is_sorted(t_list2 **stack)
{
	t_list2	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_test5(t_list2 **stack_a, t_list2 **stack_b)
{
	t_list2	*head;

	head = *stack_a;
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	ft_test3(stack_a);
	//ft_print_stack('a', stack_a);
	pa(stack_a, stack_b);
	ft_test3(stack_a);
	/*
	while (!is_sorted(stack_a))
	{
		//ft_print_stack('a', stack_a);
		pb(stack_b, stack_a);
		ft_test3(stack_a);
		pa(stack_a, stack_b);
	}
	*/
	//ft_print_stack('a', stack_a);
	pa(stack_a, stack_b);
	ft_test3(stack_a);
	if (!is_sorted(stack_a))
		ft_test5(stack_a, stack_b);
}
