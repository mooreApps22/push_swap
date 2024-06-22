/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:42:37 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:34:56 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_forwards(t_stack *head, char *str)
{
	ft_printf("%s", str);
	while (head != NULL)
	{
		ft_printf("%d ", head->n);
		head = head->next;
	}
	ft_printf("\n");
}

void	print_backwards(t_stack *head, char *str)
{
	t_stack	*last;

	ft_printf("%s", str);
	while (head != NULL)
	{
		last = head;
		head = head->next;
	}
	while (last != NULL)
	{
		ft_printf("%d ", last->n);
		last = last->prev;
	}
	ft_printf("\n");
}
