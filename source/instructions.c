/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:11:42 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list2 **stack)
{
	t_list2	*head;
	t_list2	*next;
	int		num;
	int		index;

	head = *stack;
	next = head->next;
	num = head->number;
	index = head->index;
	head->number = next->number;
	head->index = next->index;
	next->number = num;
	next->index = index;
}

void	ft_push(t_list2 **stack_to, t_list2 **stack_from)
{
	t_list2	*head_to;
	t_list2	*head_from;
	t_list2	*temp;

	if (stack_from == NULL)
		return ;
	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		temp->next = head_to;
		*stack_to = temp;
	}
}

void	ft_rotate(t_list2 **stack)
{
	t_list2	*head;
	t_list2	*tail;

	head = *stack;
	tail = ft_lstlast2(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ft_reverse_rotate(t_list2 **stack)
{
	t_list2	*head;
	t_list2	*tail;

	head = *stack;
	tail = ft_lstlast2(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}
