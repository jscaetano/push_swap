/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:01:03 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 20:14:27 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stacks *stacks)
{
	t_elem	*first;
	t_elem	*last;

	last = ft_lstlast(stacks->sa);
	first = stacks->sa->top;
	stacks->sa->top = stacks->sa->top->next;
	first->next = NULL;
	last->next = first;
	ft_stackpushmove(stacks->moves, "ra");
	if (RMOVES)
		rmoves(stacks);
}

void	rb(t_stacks *stacks)
{
	t_elem	*first;
	t_elem	*last;

	last = ft_lstlast(stacks->sb);
	first = stacks->sb->top;
	stacks->sb->top = stacks->sb->top->next;
	first->next = NULL;
	last->next = first;
	ft_stackpushmove(stacks->moves, "rb");
	if (RMOVES)
		rmoves(stacks);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_stackpushmove(stacks->moves, "rr");
	if (RMOVES)
		rmoves(stacks);
}

void	rmoves(t_stacks *stacks)
{
	t_move	*first;
	t_move	*last;

	if (stacks->moves->size < 2)
		return ;
	last = ft_lstlastmove(stacks->moves);
	first = stacks->moves->top;
	stacks->moves->top = stacks->moves->top->next;
	first->next = NULL;
	last->next = first;
}
