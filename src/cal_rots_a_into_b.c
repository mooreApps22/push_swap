/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_rots_a_into_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:20:46 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:43:21 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cal_ra_rb_a_into_b(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = rank_ab(b, n);
	if (i < find_index(a, n))
		i = find_index(a, n);
	return (i);
}

int	cal_rra_rrb_a_into_b(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = 0;
	if (rank_ab(b, n))
		i = stack_size(b) - rank_ab(b, n);
	if ((i < (stack_size(a) - find_index(a, n))) && find_index(a, n))
		i = stack_size(a) - find_index(a, n);
	return (i);
}

int	cal_rra_rb_a_into_b(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = 0;
	if (find_index(a, n))
		i = stack_size(a) - find_index(a, n);
	i = rank_ab(b, n) + i;
	return (i);
}

int	cal_ra_rrb_a_into_b(t_stack *a, t_stack *b, int n)
{
	int		i;

	i = 0;
	if (rank_ab(b, n))
		i = stack_size(b) - rank_ab(b, n);
	i = find_index(a, n) + i;
	return (i);
}

int	cal_rots_a_into_b(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	int			i;

	tmp = a;
	if (a && b)
		i = cal_rra_rrb_a_into_b(a, b, a->n);
	while (tmp)
	{
		if (i > cal_ra_rb_a_into_b(a, b, tmp->n))
			i = cal_ra_rb_a_into_b(a, b, tmp->n);
		if (i > cal_rra_rrb_a_into_b(a, b, tmp->n))
			i = cal_rra_rrb_a_into_b(a, b, tmp->n);
		if (i > cal_ra_rrb_a_into_b(a, b, tmp->n))
			i = cal_ra_rrb_a_into_b(a, b, tmp->n);
		if (i > cal_rra_rb_a_into_b(a, b, tmp->n))
			i = cal_rra_rb_a_into_b(a, b, tmp->n);
		tmp = tmp->next;
	}
	return (i);
}
