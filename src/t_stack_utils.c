/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:15 by smoore            #+#    #+#             */
/*   Updated: 2024/06/19 15:50:16 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_stack(t_stack **head)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *head;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

t_stack	*last_of(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_size(t_stack *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	add_to_stack(t_stack **head, t_stack *new)
{
	t_stack	*cur;

	if (*head == NULL)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

t_stack	*make_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		wr_error();
	new->n = n;
	new->next = NULL;
	return (new);
}
