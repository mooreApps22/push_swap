/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:44:06 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:45:42 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_of(t_stack *head)
{
	int	min;

	min = head->n;
	while (head)
	{
		if (head->n < min)
			min = head->n;
		head = head->next;
	}
	return (min);
}

int	max_of(t_stack *head)
{
	int	max;

	max = head->n;
	while (head != NULL)
	{
		if (head->n > max)
			max = head->n;
		head = head->next;
	}
	return (max);
}
