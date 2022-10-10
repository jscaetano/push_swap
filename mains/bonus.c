/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:59:41 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/10 02:13:47 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec_moves(t_stacks *lists, char *move)
{
	if (!ft_strcmp(move, "ra"))
		ra(lists);
	if (!ft_strcmp(move, "rb"))
		rb(lists);
	if (!ft_strcmp(move, "rr"))
		rr(lists);
	if (!ft_strcmp(move, "rra"))
		rra(lists);
	if (!ft_strcmp(move, "rrb"))
		rrb(lists);
	if (!ft_strcmp(move, "rrr"))
		rrr(lists);
	if (!ft_strcmp(move, "sa"))
		sa(lists);
	if (!ft_strcmp(move, "sb"))
		sb(lists);
	if (!ft_strcmp(move, "ss"))
		ss(lists);
	if (!ft_strcmp(move, "pa"))
		pa(lists);
	if (!ft_strcmp(move, "pb"))
		pb(lists);
}

void	do_moves(t_stacks *lists)
{
	t_move	*tmp;

	tmp = lists->moves->top;
	while (tmp)
	{
		exec_moves(lists, tmp->move);
		tmp = tmp->next;
	}
}

void	get_moves(t_stacks *lists)
{
	t_move	*tmp;
	char	*line;

	tmp = lists->moves->top;
	line = get_next_line(0);
	// printf("%s\n", get_next_line(0));
	ft_stackpushmove(lists->moves, line);
	free(line);
	rmoves(lists);
	while (tmp)
	{
		line = get_next_line(0);
		ft_stackpushmove(lists->moves, line);
		free(line);
		rmoves(lists);
		tmp = tmp->next;
	}
}

void	checker(t_stacks *lists)
{
	get_moves(lists);
	do_moves(lists);
	if (issortedlst(lists->sa) && lists->sb->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	long		*a;
	int			size;
	char		**argv2;
	t_stacks	*lists;

	argv2 = check_args(argc, argv);
	size = ft_strleng(argv2);
	a = to_int(size, argv2);
	if (issorted(a, size))
	{
		free_arrays(argv2);
		free(a);
		return (0);
	}
	a = get_simple_a(a, size);
	lists = create_lists(a, size);
	free(a);
	checker(lists);
	free_arrays(argv2);
	free_stacks(lists);
	return (0);
}
