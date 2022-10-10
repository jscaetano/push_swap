/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:48:45 by joacaeta          #+#    #+#             */
/*   Updated: 2022/09/17 21:24:01 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_stackdestroy(t_lst *stack)
{
	while (stack->size)
		ft_stackpop(stack);
	free(stack);
}

void	populate(t_elem **dest, t_elem *src)
{
	if (!src)
		return ;
	*dest = malloc(sizeof(t_elem));
	(*dest)->content = src->content;
	populate(&((*dest)->next), src->next);
}

t_lst	*ft_stackdup(t_lst *o)
{
	t_lst	*ret;

	if (!o)
		return (NULL);
	ret = malloc(sizeof(t_lst));
	if (!ret)
		return (NULL);
	populate(&(ret->top), o->top);
	ret->size = o->size;
	return (ret);
}

t_lst	*ft_stacknew(void)
{
	t_lst	*ret;

	ret = malloc(sizeof(t_lst));
	if (!ret)
		return (NULL);
	ret->size = 0;
	ret->top = NULL;
	return (ret);
}

// pushes to top element
void	ft_stackpush(t_lst *stack, int content)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		error_exit(NULL);
	if (!stack)
		stack = ft_stacknew();
	new->content = content;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}
