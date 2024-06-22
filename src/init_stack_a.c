/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:21:19 by smoore            #+#    #+#             */
/*   Updated: 2024/06/20 15:29:12 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_splits(char **tmp)
{
	if (!tmp)
		return ;
	while (*tmp)
		free(*tmp++);
	*tmp = NULL;
}

int	make_data(const char *s)
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
		s++;
	}
	return (sign * n);
}

t_stack	*split_arg_into_elements(char **av)
{
	t_stack		*a;
	char		**tmp;
	int			i;
	int			data;

	a = NULL;
	i = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i])
	{
		data = make_data(tmp[i]);
		add_to_stack(&a, make_new(data));
		check_for_range(&a, tmp[i]);
		i++;
	}
	free_splits(tmp);
	free(tmp);
	return (a);
}

t_stack	*init_stack_a(int ac, char **av)
{
	t_stack		*a;	
	int			i;
	int			data;

	i = 1;
	a = NULL;
	if (ac < 2)
		wr_error();
	else if (ac == 2)
		a = split_arg_into_elements(av);
	else
	{
		while (i < ac)
		{
			data = make_data(av[i]);
			add_to_stack(&a, make_new(data));
			check_for_range(&a, av[i]);
			i++;
		}
	}
	return (a);
}
