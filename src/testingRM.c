/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingRM.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:54:14 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 20:16:01 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list(t_lst *list)
{
	t_elem	*tmp;

	tmp = list->top;
	while (tmp->next)
	{
		printf("lcont: %d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("lcont: %d\n", tmp->content);
}

void	print_all_lists(t_stacks *lists)
{
	t_elem	*tmpa;
	t_elem	*tmpb;

	tmpa = lists->sa->top;
	tmpb = lists->sb->top;
	printf("\n==============LISTS==============\n");
	printf("\ta:\t\tb:\n");
	while (tmpa || tmpb)
	{
		printf("\t");
		if (tmpa)
		{
			printf("%d", tmpa->content);
			tmpa = tmpa->next;
		}
		printf("\t\t");
		if (tmpb)
		{
			printf("%d", tmpb->content);
			tmpb = tmpb->next;
		}
		printf("\n");
	}
}

void	print_array(long *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%ld\n", array[i]);
		i++;
	}
}
