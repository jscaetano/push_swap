/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:52:16 by joacaeta          #+#    #+#             */
/*   Updated: 2022/09/17 21:23:44 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stackpeek(t_lst *list)
{
	return (list->top->content);
}

int	ft_stackpop(t_lst *list)
{
	int		ret;
	t_elem	*tmp;

	tmp = list->top;
	list->top = list->top->next;
	list->size--;
	ret = tmp->content;
	free(tmp);
	return (ret);
}

t_elem	*ft_lstlast(t_lst *lst)
{
	t_elem	*tmp;

	tmp = lst->top;
	if (!lst || !tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_elem	*ft_lstbeforelast(t_lst *lst)
{
	t_elem	*last;
	t_elem	*tmp;

	tmp = lst->top;
	last = ft_lstlast(lst);
	if (lst && tmp && lst->size > 2)
	{
		while (tmp->next != last)
			tmp = tmp->next;
	}
	return (tmp);
}
