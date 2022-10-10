/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:00:41 by joacaeta          #+#    #+#             */
/*   Updated: 2022/09/17 22:02:42 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = ft_stackpop(stacks->sa);
	tmp2 = ft_stackpop(stacks->sa);
	ft_stackpush(stacks->sa, tmp1);
	ft_stackpush(stacks->sa, tmp2);
	ft_stackpushmove(stacks->moves, "sa");
	if (RMOVES)
		rmoves(stacks);
}

void	sb(t_stacks *stacks)
{
	int	tmp1;
	int	tmp2;

	tmp1 = ft_stackpop(stacks->sb);
	tmp2 = ft_stackpop(stacks->sb);
	ft_stackpush(stacks->sb, tmp1);
	ft_stackpush(stacks->sb, tmp2);
	ft_stackpushmove(stacks->moves, "sb");
	if (RMOVES)
		rmoves(stacks);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_stackpushmove(stacks->moves, "ss");
	if (RMOVES)
		rmoves(stacks);
}

void	pa(t_stacks *stacks)
{
	ft_stackpush(stacks->sa, ft_stackpop(stacks->sb));
	ft_stackpushmove(stacks->moves, "pa");
	if (RMOVES)
		rmoves(stacks);
}

void	pb(t_stacks *stacks)
{
	ft_stackpush(stacks->sb, ft_stackpop(stacks->sa));
	ft_stackpushmove(stacks->moves, "pb");
	if (RMOVES)
		rmoves(stacks);
}
