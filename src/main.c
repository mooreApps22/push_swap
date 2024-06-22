/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:21:29 by smoore            #+#    #+#             */
/*   Updated: 2024/06/20 14:24:45 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	wr_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	is_sorted(t_stack *head)
{
	t_stack	*cur;

	cur = head;
	while (cur->next != NULL)
	{
		if (cur->n > cur->next->n)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac <= 1)
		return (0);
	a = init_stack_a(ac, av);
	if (has_dup(a))
	{
		clear_stack(&a);
		wr_error();
	}
	if (!is_sorted(a))
		sort(&a);
	clear_stack(&a);
	return (0);
}
