/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:15:57 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/02 22:17:05 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stacks	*sort_big(t_stacks *lists, int bits, int sizea)
{
	int	i;

	i = 0;
	while (i < bits)
	{
		sizea = lists->sa->size;
		while (sizea)
		{
			if (!(lists->sa->top->content >> i & 1))
				pb(lists);
			else
				ra(lists);
			sizea--;
		}
		while (lists->sb->size > 0)
			pa(lists);
		i++;
	}
	return (lists);
}

t_stacks	*sort_small(t_stacks *lists)
{
	if (lists->sa->size == 3)
		lists = sort3(lists);
	if (lists->sa->size == 4)
		lists = sort4(lists);
	if (lists->sa->size == 5)
		lists = sort5(lists);
	return (lists);
}

t_stacks	*sort3(t_stacks *lists)
{
	if (issortedlst(lists->sa))
		return (lists);
	if (lists->sa->top->content == 0)
	{
		sa(lists);
		ra(lists);
	}
	if (lists->sa->top->content == 1)
	{
		if (ft_lstlast(lists->sa)->content > 1)
			sa(lists);
		else
			rra(lists);
	}
	if (lists->sa->top->content == 2)
	{
		ra(lists);
		if (lists->sa->top->content == 1)
			sa(lists);
	}
	return (lists);
}

t_stacks	*sort4(t_stacks *lists)
{
	while (lists->sa->size > 3)
	{
		if (lists->sa->top->content == 3)
			pb(lists);
		else
			ra(lists);
	}
	sort3(lists);
	pa(lists);
	ra(lists);
	return (lists);
}

t_stacks	*sort5(t_stacks *lists)
{
	while (lists->sa->size > 3)
	{
		if (lists->sa->top->content > 2)
			pb(lists);
		else
		{
			if (upordown(lists->sa, 2))
				ra(lists);
			else
				rra(lists);
		}
	}
	sort3(lists);
	pa(lists);
	pa(lists);
	if (lists->sa->top->content == 4)
		sa(lists);
	ra(lists);
	ra(lists);
	return (lists);
}
