/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:13:51 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_num(t_list2 **stack_a, int argc, char **argv)
{
	t_list2	*new;
	char	**num;
	int		i;

	i = 0;
	if (argc == 2)
		num = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		num = argv;
	}
	while (num[i])
	{
		new = ft_lstnew2(ft_atoi(num[i]));
		ft_lstadd_back2(stack_a, new);
		i++;
	}
}

void	ft_add_index(t_list2 **stack_a)
{
	t_list2	*head;
	t_list2	*moving;
	int		i;

	head = *stack_a;
	while (head)
	{
		moving = *stack_a;
		i = 1;
		while (moving)
		{
			if (head->number > moving->number)
				i++;
			moving = moving->next;
		}
		head->index = i;
		head = head->next;
	}
}

void	ft_length(t_list2 **stack_a, t_list2 **stack_b)
{
	if (ft_lstsize2(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize2(*stack_a) == 3)
		ft_test3(stack_a);
	else if (ft_lstsize2(*stack_a) == 4)
		ft_test4(stack_a, stack_b);
	else if (ft_lstsize2(*stack_a) == 5)
		ft_test5(stack_a, stack_b);
	else
		ft_testall(stack_a, stack_b);
}
