/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:23:44 by smoore            #+#    #+#             */
/*   Updated: 2024/06/20 15:33:05 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				n;
	int				i;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

//	main
void		wr_error(void);
int			is_sorted(t_stack *head);

// init stack a
void		free_splits(char **tmp);
int			make_data(const char *s);
t_stack		*split_arg_into_elements(char **av);
t_stack		*init_stack_a(int ac, char **av);

// validate stack
int			has_dup(t_stack *a);
int			has_outlier(t_stack *a);
void		check_for_range(t_stack **head, char *s);

// t stack utils	t_stack utils
void		clear_stack(t_stack **head);
t_stack		*last_of(t_stack *head);
int			stack_size(t_stack *head);
void		add_to_stack(t_stack **head, t_stack *new);
t_stack		*make_new(int n);

// print utils
void		print_forwards(t_stack *head, char *str);
void		print_backwards(t_stack *head, char *str);

// swap
void		swap(int *a, int *b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

// rotate
void		rotate(t_stack **head);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

// reverse rotate
void		reverse_rotate(t_stack **head);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// push
void		push(t_stack **src, t_stack **dest);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

// sort
void		sort(t_stack **a);

//		max min
int			max_of(t_stack *head);
int			min_of(t_stack *head);

//		index rank a/b
int			find_index(t_stack *a, int n);
int			rank_ab(t_stack *b, int n);
int			rank_ba(t_stack *a, int n);

//		sort three
void		sort_three(t_stack **a);

//		sort into b
void		keep_pushing_until_three(t_stack **a, t_stack **b);
t_stack		*sort_into_b(t_stack **a);

//		cal rots a into b
int			cal_ra_rb_a_into_b(t_stack *a, t_stack *b, int n);
int			cal_rra_rrb_a_into_b(t_stack *a, t_stack *b, int n);
int			cal_rra_rb_a_into_b(t_stack *a, t_stack *b, int n);
int			cal_ra_rrb_a_into_b(t_stack *a, t_stack *b, int n);
int			cal_rots_a_into_b(t_stack *a, t_stack *b);

//		cal rots b into a
int			cal_ra_rb_b_into_a(t_stack *a, t_stack *b, int n);
int			cal_rra_rrb_b_into_a(t_stack *a, t_stack *b, int n);
int			cal_rra_rb_b_into_a(t_stack *a, t_stack *b, int n);
int			cal_ra_rrb_b_into_a(t_stack *a, t_stack *b, int n);
int			cal_rots_b_into_a(t_stack *a, t_stack *b);

//		rot rot push
int			ra_rb_push(t_stack **a, t_stack **b, int n, char stack);
int			rra_rrb_push(t_stack **a, t_stack **b, int n, char stack);
int			ra_rrb_push(t_stack **a, t_stack **b, int n, char stack);
int			rra_rb_push(t_stack **a, t_stack **b, int n, char stack);

//		sort into a
t_stack		**sort_into_a(t_stack **a, t_stack**b);

#endif
