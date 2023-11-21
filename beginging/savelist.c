/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:13:51 by miggonza          #+#    #+#             */
/*   Updated: 2023/11/15 11:26:12 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_num(t_list2 **stack_a, int argc, char **argv)
{
	t_list2	*new;
	char	**idk;
	int		i;

	i = 0;
	if (argc == 2)
		idk = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		idk = argv;
	}
	while (idk[i])
	{
		new = ft_lstnew2(ft_atoi(idk[i]));
		ft_lstadd_back2(stack_a, new);
		i++;
	}
}

//WTF IS THIS FOR???
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
