/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:59:39 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 20:06:08 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	long		*a;
	int			size;
	char		**argv2;
	t_stacks	*lists;

	argv2 = check_args(argc, argv);
	size = ft_strleng(argv2);
	a = to_int(size, argv2);
	if (argc == 2)
		free_arrays(argv2);
	if (issorted(a, size))
	{
		free(a);
		return (0);
	}
	a = get_simple_a(a, size);
	lists = create_lists(a, size);
	free(a);
	while (!issortedlst(lists->sa))
		lists = sort(lists);
	print_moves(lists->moves);
	free_stacks(lists);
	return (0);
}
