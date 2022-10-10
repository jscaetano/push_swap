/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:50:24 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/10 20:52:51 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_strleng(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

// Checks for input errors
char	**check_args(int argc, char **argv)
{
	char	**argv2;

	argv2 = argv;
	if (argc == 1)
		error_exit("argc = 1");
	if (argc == 2)
		argv2 = ft_split(argv[1], ' ');
	else
		argv2++;
	check_errors(ft_strleng(argv2), argv2);
	return (argv2);
}

t_stacks	*sort(t_stacks *lists)
{
	int	sizea;
	int	bits;

	sizea = lists->sa->size;
	bits = numberofbits(lists);
	if (sizea == 2)
	{
		if (lists->sa->top->content > lists->sa->top->next->content)
			ra(lists);
		return (lists);
	}
	if (sizea > 5)
		lists = sort_big(lists, bits, sizea);
	else
		lists = sort_small(lists);
	return (lists);
}
