/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:11:42 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/13 21:08:58 by miggonza         ###   ########.fr       */
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
	next->index	= index;
	
	/*
	t_list2	*temp;
	head = *stack;
	next = head->next;
	
	temp = head;
	head = head->next;
	temp->next = head;
	*stack = temp;
	*/
}

void	ft_push(t_list2 **stack_to, t_list2 **stack_from)
{
	t_list2	*head_a;
	t_list2	*head_b;
	t_list2	*temp;

	if(stack_from == NULL)
		return ;
	head_a = *stack_to;
	head_b = *stack_from;

	temp = head_b;
	head_b = head_b->next;
	*stack_from = head_b;
	if (!head_a)
	{
		head_a = temp;
		head_a->next = NULL;
		*stack_to = head_a;
	}
	else
	{
		temp->next = head_a;
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
	t_list2 *head;
	t_list2	*tail;

	head = *stack;
	tail = ft_lstlast2(head);

	while (head)
	{
		if(head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}