/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:10 by smoore            #+#    #+#             */
/*   Updated: 2024/06/14 15:59:02 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sa(t_stack **a)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		swap(&((*a))->n, &((*a))->next->n);
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		swap(&((*b))->n, &((*b))->next->n);
		ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != NULL)
		swap(&((*a))->n, &((*a))->next->n);
	if (*b != NULL && (*b)->next != NULL)
		swap(&((*b))->n, &((*b))->next->n);
	ft_printf("ss\n");
}
