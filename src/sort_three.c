/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:20:46 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:44:41 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **a)
{
	if (min_of(*a) == (*a)->n)
	{
		rra(a);
		sa(a);
	}
	else if (max_of(*a) == (*a)->n)
	{
		ra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else
	{
		if (find_index(*a, max_of(*a)) == 1)
			rra(a);
		else
			sa(a);
	}
}
