/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:57:16 by joacaeta          #+#    #+#             */
/*   Updated: 2022/09/21 23:04:17 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_non_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
				j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_non_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_ai(argv[i]) > 2147483647 || ft_ai(argv[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicate(long int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	error_exit(char *error)
{
	ft_putstr_fd(error, 1);
	exit(EXIT_FAILURE);
}

void	check_errors(int size, char **argv)
{
	long int	*list;

	if (check_non_digit(argv))
		error_exit("Error\n");
	if (check_non_int(argv))
		error_exit("Error\n");
	list = to_int(size, argv);
	if (check_duplicate(list, size))
		error_exit("Error\n");
	free(list);
}
