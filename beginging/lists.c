/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:52 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/13 21:11:05 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list2	*ft_lstnew2(int num)
{
	t_list2	*new;

	new = (t_list2 *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->number = num;
	new->next = NULL;
	return (new);
}

t_list2	*ft_lstlast2(t_list2 *lst)
{
	t_list2	*tmp;

	tmp = lst;
	if (!lst)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back2(t_list2 **lst, t_list2 *new)
{
	t_list2	*recive;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	recive = ft_lstlast2(*lst);
	recive->next = new;
}

int	ft_lstsize2(t_list2 *lst)
{
	int	i;
	t_list2	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
