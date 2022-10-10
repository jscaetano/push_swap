/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_simplifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:22:52 by joacaeta          #+#    #+#             */
/*   Updated: 2022/07/24 18:34:20 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_largest_index(long int *list, int size)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < size)
	{
		if (max < list[i])
			max = list[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (max == list[i])
			return (i);
		i++;
	}
	return (0);
}

long int	*array_copy(long int *array, int size)
{
	int			i;
	long int	*copy;

	i = 0;
	copy = (long int *)malloc(sizeof(long int) * size);
	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}
	return (copy);
}

long int	*simplify(long int *list, int size)
{
	int			s;
	int			i;
	long int	*midarr;

	midarr = array_copy(list, size);
	s = size - 1;
	while (s >= 0)
	{
		i = find_largest_index(midarr, size);
		list[i] = s;
		midarr[i] = -2147483649;
		s--;
	}
	free(midarr);
	return (list);
}

long	*to_int(int size, char **argv)
{
	int		i;
	long	*res;

	i = 0;
	res = malloc(sizeof(long int) * (long int)size + 1);
	while (i < size)
	{
		res[i] = ft_atoi(argv[i]);
		i++;
	}
	return (res);
}

long int	*get_simple_a(long *res, int size)
{
	res = simplify(res, size);
	return (res);
}
