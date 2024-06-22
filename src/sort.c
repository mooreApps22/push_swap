/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:22:46 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:36:40 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a)
{
	t_stack		*b;
	int			i;

	b = NULL;
	if (stack_size(*a) == 2)
		sa(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else
	{
		b = sort_into_b(a);
		a = sort_into_a(a, &b);
		i = find_index(*a, min_of(*a));
		if (i < stack_size(*a) - i)
		{
			while ((*a)->n != min_of(*a))
				ra(a);
		}
		else
		{
			while ((*a)->n != min_of(*a))
				rra(a);
		}
	}
}
