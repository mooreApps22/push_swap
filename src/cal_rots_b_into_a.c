/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_rots_b_into_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:20:58 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:51:02 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cal_ra_rb_b_into_a(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = rank_ba(a, n);
	if (i < find_index(b, n))
		i = find_index(b, n);
	return (i);
}

int	cal_rra_rrb_b_into_a(t_stack *a, t_stack *b, int n)
{
	int		i;	

	i = 0;
	if (rank_ba(a, n))
		i = stack_size(a) - rank_ba(a, n);
	if ((i < (stack_size(b) - find_index(b, n))) && find_index(b, n))
		i = stack_size(b) - find_index(b, n);
	return (i);
}

int	cal_rra_rb_b_into_a(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = 0;
	if (rank_ba(a, n))
		i = stack_size(a) - rank_ba(a, n);
	i = find_index(b, n) + i;
	return (i);
}

int	cal_ra_rrb_b_into_a(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = 0;
	if (find_index(b, n))
		i = stack_size(b) - find_index(b, n);
	i = rank_ba(a, n) + i;
	return (i);
}

int	cal_rots_b_into_a(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	int			i;

	tmp = b;
	i = cal_rra_rrb_b_into_a(a, b, b->n);
	while (tmp)
	{
		if (i > cal_ra_rb_b_into_a(a, b, tmp->n))
			i = cal_ra_rb_b_into_a(a, b, tmp->n);
		if (i > cal_rra_rrb_b_into_a(a, b, tmp->n))
			i = cal_rra_rrb_b_into_a(a, b, tmp->n);
		if (i > cal_ra_rrb_b_into_a(a, b, tmp->n))
			i = cal_ra_rrb_b_into_a(a, b, tmp->n);
		if (i > cal_rra_rb_b_into_a(a, b, tmp->n))
			i = cal_rra_rb_b_into_a(a, b, tmp->n);
		tmp = tmp->next;
	}
	return (i);
}
