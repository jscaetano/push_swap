/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:01:39 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 20:14:31 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stacks *stacks)
{
	t_elem	*last;
	t_elem	*prelast;

	last = ft_lstlast(stacks->sa);
	prelast = ft_lstbeforelast(stacks->sa);
	last->next = stacks->sa->top;
	stacks->sa->top = last;
	prelast->next = NULL;
	ft_stackpushmove(stacks->moves, "rra");
	if (RMOVES)
		rmoves(stacks);
}

void	rrb(t_stacks *stacks)
{
	t_elem	*last;
	t_elem	*prelast;

	last = ft_lstlast(stacks->sb);
	prelast = ft_lstbeforelast(stacks->sb);
	last->next = stacks->sb->top;
	stacks->sb->top = last;
	prelast->next = NULL;
	ft_stackpushmove(stacks->moves, "rrb");
	if (RMOVES)
		rmoves(stacks);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_stackpushmove(stacks->moves, "rrr");
	if (RMOVES)
		rmoves(stacks);
}
