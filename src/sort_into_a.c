/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:22:53 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:39:20 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	**sort_into_a(t_stack **a, t_stack**b)
{
	t_stack		*tmp;
	int			i;

	pb(a, b);
	pb(a, b);
	while (*b)
	{
		tmp = *b;
		i = cal_rots_b_into_a(*a, *b);
		while (i >= 0)
		{
			if (i == cal_ra_rb_b_into_a(*a, *b, tmp->n))
				i = ra_rb_push(a, b, tmp->n, 'b');
			else if (i == cal_ra_rrb_b_into_a(*a, *b, tmp->n))
				i = ra_rrb_push(a, b, tmp->n, 'b');
			else if (i == cal_rra_rrb_b_into_a(*a, *b, tmp->n))
				i = rra_rrb_push(a, b, tmp->n, 'b');
			else if (i == cal_rra_rb_b_into_a(*a, *b, tmp->n))
				i = rra_rb_push(a, b, tmp->n, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}
