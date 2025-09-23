/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:50:01 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:30:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(t_list2 **stack_a, t_list2 **stack_b)
{
	t_list2	*temp;

	while (*stack_a)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = temp;
	}
	while (*stack_b)
	{
		temp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = temp;
	}
}

int	main(int argc, char **argv)
{
	t_list2	*stack_a;
	t_list2	*stack_b;

	if (argc < 2)
	{
		ft_printerror("Error: No arguments provided");
		return (1);
	}

	stack_a = NULL;
	stack_b = NULL;

	// Validate input numbers
	ft_get_num(argc, argv);

	// Create and populate stack A
	ft_sort_num(&stack_a, argc, argv);

	// Add indices for sorting algorithm
	ft_add_index(&stack_a);

	// Check if already sorted
	if (ft_sorted(&stack_a))
	{
		ft_free_stacks(&stack_a, &stack_b);
		return (0);
	}
make
	// Apply sorting algorithm
	ft_length(&stack_a, &stack_b);

	// Clean up memory
	ft_free_stacks(&stack_a, &stack_b);
	return (0);
}
