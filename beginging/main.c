/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:50:01 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/12 21:46:18 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_index(t_list2 **stack_a)
{
	t_list2	*head;
	t_list2	*moving;
	int i;

	head = *stack_a;
	while (head)
	{
		moving = *stack_a;
		i  = 1;
		while (moving)
		{
			if (head->number > moving->number)
				i++;
			moving = moving->next;
		}
		head->index = i;
		printf("%d", head->index);
		head = head->next;
	}
}

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
		printf("%d\n", new->number);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list2	**stack_a;
	t_list2	**stack_b;

	if (argc < 2)
		ft_printerror("ERROR ARG");
	stack_a = (t_list2 **)malloc(sizeof(t_list2));
	stack_b = (t_list2 **)malloc(sizeof(t_list2));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_get_num(argc, argv);
	ft_sort_num(stack_a, argc, argv);
	ft_add_index(stack_a);
	//printf("%d", ft_lstsize2(*stack_a));
	//printf("%s", argv[1]);
	return (0);
}
