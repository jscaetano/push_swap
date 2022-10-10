/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:23:21 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 20:13:24 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	issortedlst(t_lst *sa)
{
	t_elem	*tmp;

	tmp = sa->top;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_lst	*to_list(long *a, int size)
{
	int		i;
	t_lst	*list;

	i = size - 1;
	list = ft_stacknew();
	while (i >= 0)
		ft_stackpush(list, a[i--]);
	return (list);
}

long	*to_arr(t_lst *lst)
{
	t_lst	*tmp;
	t_elem	*tmpelem;
	long	*arr;
	int		i;

	i = 0;
	tmp = ft_stackdup(lst);
	tmpelem = tmp->top;
	arr = malloc(sizeof(long) * lst->size);
	while (i < lst->size)
	{
		arr[i] = tmpelem->content;
		i++;
		tmpelem = tmpelem->next;
	}
	ft_stackdestroy(tmp);
	return (arr);
}

t_stacks	*create_lists(long *a, int size)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->sa = to_list(a, size);
	stacks->sb = ft_stacknew();
	stacks->moves = ft_stacknewmoves();
	return (stacks);
}
