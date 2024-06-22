/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:22:58 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:40:10 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	keep_pushing_until_three(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	int			i;

	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		tmp = *a;
		i = cal_rots_a_into_b(*a, *b);
		while (i >= 0)
		{
			if (i == cal_ra_rb_a_into_b(*a, *b, tmp->n))
				i = ra_rb_push(a, b, tmp->n, 'a');
			else if (i == cal_rra_rrb_a_into_b(*a, *b, tmp->n))
				i = rra_rrb_push(a, b, tmp->n, 'a');
			else if (i == cal_ra_rrb_a_into_b(*a, *b, tmp->n))
				i = ra_rrb_push(a, b, tmp->n, 'a');
			else if (i == cal_rra_rb_a_into_b(*a, *b, tmp->n))
				i = rra_rb_push(a, b, tmp->n, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_into_b(t_stack **a)
{
	t_stack		*b;

	b = NULL;
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, &b);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, &b);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		keep_pushing_until_three(a, &b);
	if (!is_sorted(*a))
		sort_three(a);
	return (b);
}
