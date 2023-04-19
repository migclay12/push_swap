/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:58 by miggonza          #+#    #+#             */
/*   Updated: 2023/04/19 21:37:20 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printerror(char *error)
{
	printf("%s\n", error);
	//ft_putendl_fd(error, 1);
	exit(0);
}

int	ft_check_rep(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_get_num(int argc, char **argv)
{
	long	temp;
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
		temp = ft_atoi(idk[i]);
		if (!ft_isnum(idk[i]))
			ft_printerror("ERROR IS NUM");
		if (temp > 2147483647 || temp < -2147483648)
			ft_printerror("ERROR SIZE");
		if (ft_check_rep(temp, idk, i))
			ft_printerror("ERROR REP");
		i++;
	}
}
