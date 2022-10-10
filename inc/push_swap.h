/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:35:17 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 23:27:10 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define RMOVES 1

typedef struct s_elem
{
	int				content;
	struct s_elem	*next;
}	t_elem;

typedef struct s_lst
{
	int		size;
	t_elem	*top;
}	t_lst;

typedef struct s_move
{
	char			*move;
	struct s_move	*next;
}	t_move;

typedef struct s_moves
{
	int		size;
	t_move	*top;
}	t_moves;

typedef struct s_stacks
{
	t_lst	*sa;
	t_lst	*sb;
	t_moves	*moves;
}	t_stacks;

// simplifier
int				find_largest_index(long int *list, int size);
long int		*array_copy(long int *array, int size);
long int		*simplify(long int *list, int size);
long int		*to_int(int argc, char **argv);
int				issortedlst(t_lst *sa);
int				issorted(long *a, int size);

// errors
void			error_exit(char *error);
int				check_non_digit(char **argv);
int				check_non_int(char **argv);
int				check_duplicate(long int *list, int size);
void			check_errors(int size, char **argv);

// calc
long long int	ft_ai(const char *nptr);
int				stringlen(char *str);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *nptr);
int				upordown(t_lst *lst, int mp);
int				ft_strcmp(char *s1, char *s2);

// printtest
void			print_array(long int *array, int size);
long int		*get_simple_a(long *res, int size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
char			*allnb(int nb, char *alln, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			print_list(t_lst *list);
void			print_all_lists(t_stacks *lists);
void			print_moves(t_moves *list);

// lists
void			ft_stackdestroy(t_lst *stack);
void			ft_stackdestroymoves(t_moves *stack);
void			populate(t_elem **dest, t_elem *src);
t_lst			*ft_stackdup(t_lst *o);
t_lst			*ft_stacknew(void);
t_moves			*ft_stacknewmoves(void);
void			ft_stackpush(t_lst *stack, int content);
void			ft_stackpushmove(t_moves *stack, char *content);
int				ft_stackpeek(t_lst *list);
int				ft_stackpop(t_lst *list);
char			*ft_stackpopmove(t_moves *list);
void			ft_stackprint(t_lst *list, char *(*to_str)(int), char *delim);
t_elem			*ft_lstlast(t_lst *lst);
t_move			*ft_lstlastmove(t_moves *lst);
t_elem			*ft_lstbeforelast(t_lst *lst);
void			free_stacks(t_stacks *lists);
void			free_arrays(char **argv2);
long			*to_arr(t_lst *lst);
t_lst			*to_list(long *a, int size);
t_stacks		*create_lists(long *a, int size);

// moves
void			sa(t_stacks *stacks);
void			sb(t_stacks *stacks);
void			ss(t_stacks *stacks);
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);
void			ra(t_stacks *stacks);
void			rb(t_stacks *stacks);
void			rr(t_stacks *stacks);
void			rra(t_stacks *stacks);
void			rrb(t_stacks *stacks);
void			rrr(t_stacks *stacks);
void			rmoves(t_stacks *stacks);

// push_swap
t_stacks		*push_swap(int argc, char **argv);
int				numberofbits(t_stacks *lists);
int				ft_iterative_power(int nb, int power);
char			**check_args(int argc, char **argv);
int				ft_strleng(char **str);

// checker
char			*get_next_line(int fd);

// sorting
t_stacks		*sort(t_stacks *lists);
t_stacks		*sort_small(t_stacks *lists);
t_stacks		*sort_big(t_stacks *lists, int bits, int sizea);
t_stacks		*sort3(t_stacks *lists);
t_stacks		*sort4(t_stacks *lists);
t_stacks		*sort5(t_stacks *lists);

#endif
