/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noleaks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:21:56 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/10 20:55:32 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Frees all lists (sa, sb, moves)
void	free_stacks(t_stacks *lists)
{
	ft_stackdestroy(lists->sa);
	ft_stackdestroy(lists->sb);
	ft_stackdestroymoves(lists->moves);
	free(lists);
}

// Frees the tmp argv array
void	free_arrays(char **argv2)
{
	int	i;

	i = 0;
	while (argv2[i] != NULL)
	{
		free(argv2[i]);
		i++;
	}
	free(argv2);
}
