/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:21:09 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:29:16 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_index(t_stack *a, int n)
{
	int		i;

	i = 0;
	while (a->n != n)
	{
		i++;
		a = a->next;
	}
	a->i = 0;
	return (i);
}

int	rank_ab(t_stack *b, int n)
{
	t_stack		*tmp;
	t_stack		*last;
	int			i;

	i = 1;
	last = last_of(b);
	if (n > b->n && n < last->n)
		i = 0;
	else if (n > max_of(b) || n < min_of(b))
		i = find_index(b, max_of(b));
	else
	{
		tmp = b->next;
		while (b->n < n || tmp->n > n)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	rank_ba(t_stack *a, int n)
{
	t_stack		*tmp;
	int			i;

	i = 1;
	if (n < a->n && n > last_of(a)->n)
		i = 0;
	else if (n > max_of(a) || n < min_of(a))
		i = find_index(a, min_of(a));
	else
	{
		tmp = a->next;
		while (a->n > n || tmp->n < n)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
