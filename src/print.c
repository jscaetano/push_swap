/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:20:55 by joacaeta          #+#    #+#             */
/*   Updated: 2022/07/24 18:27:23 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}

char	*allnb(int nb, char *alln, int fd)
{
	int		a;
	long	b;
	int		mod;

	b = (long)nb;
	a = 9;
	if (b != 0)
	{
		if (b < 0)
		{
			write(fd, "-", 1);
			b = -1 * b;
		}
		while (b > 0)
		{
			mod = (b % 10) + 48;
			alln[a] = mod;
			a--;
			b = b / 10;
		}
	}
	else
		alln[a] = 48;
	return (alln);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	alln[10];
	int		i;
	int		a;

	a = 9;
	i = 0;
	while (a >= 0)
	{
		alln[a] = '\0';
		a--;
	}
	allnb(nb, alln, fd);
	while (i < 10)
	{
		if (alln[i] != '\0')
			write(fd, &alln[i], 1);
		i++;
	}
}

void	ft_stackprint(t_lst *list, char *(*to_str)(int), char *delim)
{
	t_elem	*elem;

	if (list->size > 0)
	{
		if (!list)
			return ;
		elem = list->top;
		if (to_str && elem)
			ft_putstr_fd(to_str(elem->content), 1);
		else if (elem)
			ft_putnbr_fd(elem->content, 1);
		while (elem->next)
		{
			elem = elem->next;
			ft_putstr_fd(delim, 1);
			if (to_str)
				ft_putstr_fd(to_str(elem->content), 1);
			else
				ft_putnbr_fd(elem->content, 1);
		}
	}
	ft_putstr_fd("\n", 1);
}
