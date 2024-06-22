/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rot_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:22:12 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:52:37 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ra_rb_push(t_stack **a, t_stack **b, int n, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->n != n && rank_ab(*b, n) > 0)
			rr(a, b);
		while ((*a)->n != n)
			ra(a);
		while (rank_ab(*b, n) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->n != n && rank_ba(*a, n) > 0)
			rr(a, b);
		while ((*b)->n != n)
			rb(b);
		while (rank_ba(*a, n) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	rra_rrb_push(t_stack **a, t_stack **b, int n, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->n != n && rank_ab(*b, n) > 0)
			rrr(a, b);
		while ((*a)->n != n)
			rra(a);
		while (rank_ab(*b, n) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->n != n && rank_ba(*a, n) > 0)
			rrr(a, b);
		while ((*b)->n != n)
			rrb(b);
		while (rank_ba(*a, n) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

int	ra_rrb_push(t_stack **a, t_stack **b, int n, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->n != n)
			ra(a);
		while (rank_ab(*b, n) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (rank_ba(*a, n) > 0)
			ra(a);
		while ((*b)->n != n)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}

int	rra_rb_push(t_stack **a, t_stack **b, int n, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->n != n)
			rra(a);
		while (rank_ab(*b, n) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (rank_ba(*a, n) > 0)
			rra(a);
		while ((*b)->n != n)
			rb(b);
		pa(a, b);
	}
	return (-1);
}
