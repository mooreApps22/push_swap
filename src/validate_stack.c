/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:21:29 by smoore            #+#    #+#             */
/*   Updated: 2024/06/20 15:49:28 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	has_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->n == tmp->n)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	has_outlier(t_stack *a)
{
	t_stack	*cur;

	cur = a;
	while (cur != NULL)
	{
		if (cur->n < INT_MIN || cur->n > INT_MAX)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	check_for_range(t_stack **head, char *s)
{
	int				sign;
	long long int	n;

	n = 0;
	sign = 1;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s)
	{
		n = n * 10 + (*s - '0');
		if (sign * n < INT_MIN || sign * n > INT_MAX || !ft_isdigit(*s))
		{
			clear_stack(head);
			wr_error();
		}
		s++;
	}
}
