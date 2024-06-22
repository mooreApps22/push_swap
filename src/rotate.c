/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:03 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:47:53 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **head)
{
	t_stack		*cur;
	t_stack		*last;

	cur = *head;
	last = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	while (last->next != NULL)
		last = last->next;
	last->next = cur;
	cur->prev = last;
	cur->next = NULL;
}

void	ra(t_stack **a)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	rotate(a);
	if (*b == NULL || (*b)->next == NULL)
		return ;
	rotate(b);
	ft_printf("rr\n");
}
