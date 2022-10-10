/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:23:08 by joacaeta          #+#    #+#             */
/*   Updated: 2022/09/21 22:56:57 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_stackpopmove(t_moves *list)
{
	char	*ret;
	t_move	*tmp;

	tmp = list->top;
	if (list->size > 1)
		list->top = list->top->next;
	list->size--;
	ret = tmp->move;
	free(tmp);
	return (ret);
}

t_move	*ft_lstlastmove(t_moves *lst)
{
	t_move	*tmp;

	tmp = lst->top;
	if (!lst || !tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stackdestroymoves(t_moves *stack)
{
	while (stack->size)
		free(ft_stackpopmove(stack));
	free(stack);
}

t_moves	*ft_stacknewmoves(void)
{
	t_moves	*ret;

	ret = malloc(sizeof(t_moves));
	if (!ret)
		return (NULL);
	ret->size = 0;
	ret->top = NULL;
	return (ret);
}

void	print_moves(t_moves *list)
{
	t_move	*tmp;

	tmp = list->top;
	while (tmp->next)
	{
		ft_putstr_fd(tmp->move, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd(tmp->move, 1);
	ft_putstr_fd("\n", 1);
}
