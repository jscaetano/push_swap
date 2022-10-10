/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:57:00 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/10 00:31:13 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	str1 = malloc(i + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

void	ft_stackpushmove(t_moves *stack, char *content)
{
	t_move	*newmove;

	newmove = malloc(sizeof(t_move));
	if (!newmove)
		error_exit(NULL);
	if (!stack)
		stack = ft_stacknewmoves();
	newmove->move = ft_strdup(content);
	newmove->next = stack->top;
	stack->top = newmove;
	stack->size++;
}
