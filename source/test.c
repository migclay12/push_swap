/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:59:11 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_list2 **stack)
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

int	ft_find_max(t_list2 **stack)
{
	t_list2	*head;
	int		max;

	head = *stack;
	max = head->index;
	while (head != NULL)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

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

void	ft_test4(t_list2 **stack_a, t_list2 **stack_b)
{
	t_list2	*head;

	while (ft_lstsize2(*stack_a) != 3)
	{
		head = *stack_a;
		if (head->index == 1)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	ft_test3(stack_a);
	pa(stack_a, stack_b);
}

void	ft_test5(t_list2 **stack_a, t_list2 **stack_b)
{
	t_list2	*head;
	int		max;

	max = ft_find_max(stack_a);
	while (ft_lstsize2(*stack_a) != 3)
	{
		head = *stack_a;
		if (max == head->index || head->index == 1)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	ft_test3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	head = *stack_a;
	if (max == head->index)
		ra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}
