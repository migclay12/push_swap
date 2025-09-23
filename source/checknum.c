/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:58 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_printerror(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if ((num[0] == '-' || num[0] == '+') && (ft_strlen(num) == 1))
		return (-1);
	else if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_rep(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_get_num(int argc, char **argv)
{
	long	temp;
	char	**str;
	int		i;
	int		count;

	if (argc < 2)
		ft_printerror("Error: No arguments provided");

	i = 0;
	count = 0;

	if (argc == 2)
	{
		if (!argv[1] || ft_strlen(argv[1]) == 0)
			ft_printerror("Error: Empty argument");
		str = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		str = argv;
	}

	// Count actual numbers (skip empty strings from split)
	while (str[i])
	{
		if (ft_strlen(str[i]) > 0)
			count++;
		i++;
	}

	if (count == 0)
		ft_printerror("Error: No valid numbers found");

	// Reset for validation
	i = 0;
	if (argc == 2)
	{
		i = 0;
		str = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		str = argv;
	}

	while (str[i])
	{
		// Skip empty strings
		if (ft_strlen(str[i]) == 0)
		{
			i++;
			continue;
		}

		// Check if it's a valid number
		if (ft_isnum(str[i]))
			ft_printerror("Error: Invalid number format");

		// Convert to long to check for overflow
		temp = ft_atoi(str[i]);

		// Check for integer overflow
		if (temp > INT_MAX || temp < INT_MIN)
			ft_printerror("Error: Number out of range");

		// Check for duplicates
		if (ft_check_rep((int)temp, str, i))
			ft_printerror("Error: Duplicate numbers found");

		i++;
	}

	// Free split array if it was created
	if (argc == 2)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}
