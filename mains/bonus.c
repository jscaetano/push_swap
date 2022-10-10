/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:59:41 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/10 20:58:21 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec_moves(t_stacks *lists, char *move)
{

	if (!ft_strcmp(move, "ra\n"))
		ra(lists);
	if (!ft_strcmp(move, "rb\n"))
		rb(lists);
	if (!ft_strcmp(move, "rr\n"))
		rr(lists);
	if (!ft_strcmp(move, "rra\n"))
		rra(lists);
	if (!ft_strcmp(move, "rrb\n"))
		rrb(lists);
	if (!ft_strcmp(move, "rrr\n"))
		rrr(lists);
	if (!ft_strcmp(move, "sa\n"))
		sa(lists);
	if (!ft_strcmp(move, "sb\n"))
		sb(lists);
	if (!ft_strcmp(move, "ss\n"))
		ss(lists);
	if (!ft_strcmp(move, "pa\n"))
		pa(lists);
	if (!ft_strcmp(move, "pb\n"))
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

	line = get_next_line(0);
	ft_stackpushmove(lists->moves, line);
	tmp = lists->moves->top;
	free(line);
	rmoves(lists);
	line = get_next_line(0);
	while (line)
	{
		ft_stackpushmove(lists->moves, line);
		free(line);
		rmoves(lists);
		tmp = tmp->next;
		line = get_next_line(0);
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
		if (argc == 2)
			free_arrays(argv2);
		free(a);
		return (0);
	}
	a = get_simple_a(a, size);
	lists = create_lists(a, size);
	free(a);
	checker(lists);
	if (argc == 2)
		free_arrays(argv2);
	free_stacks(lists);
	return (0);
}
