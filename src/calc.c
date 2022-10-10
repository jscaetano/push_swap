/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:30:21 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 20:24:20 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stringlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long int	ft_ai(const char *nptr)
{
	int				i;
	int				n;
	long long int	res;

	res = 0;
	i = 0;
	n = 1;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + nptr[i] - 48;
		i++;
	}
	return (res * n);
}

int	numberofbits(t_stacks *lists)
{
	int	biggest;
	int	bits;

	bits = 0;
	biggest = lists->sa->size - 1;
	while (biggest >= ft_iterative_power(2, bits))
	{
		bits++;
	}
	return (bits);
}

int	ft_iterative_power(int nb, int power)
{
	int	r;

	r = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		r = r * nb;
		power--;
	}
	return (r);
}

int	upordown(t_lst *lst, int mp)
{
	long	*arr;
	int		u;
	int		d;
	int		len;
	int		i;

	u = 0;
	d = 1;
	i = 0;
	arr = to_arr(lst);
	len = lst->size;
	while (arr[i++] <= mp && u < lst->size)
		u++;
	i = 1;
	while (arr[len - i++] <= mp && u < lst->size)
		d++;
	free(arr);
	if (u < d)
		return (1);
	else
		return (0);
}
