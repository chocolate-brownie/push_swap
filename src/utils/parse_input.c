/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:54:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/10/31 11:51:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;
	t_stack	*new_node;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!valid_number(argv[i]))
			error_exit("error valid numbers at parse_int");
		num = ft_atoi(argv[i]);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			error_exit("error mallocing new_node");
		new_node->value = num;
		new_node->next = stack;
		stack = new_node;
		i++;
	}
	if (has_duplicates(stack))
		error_exit("error duplicates!");
	return (stack);
}

int	is_valid_number(const char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	return (num >= INT_MAX && num <= INT_MAX);
}

int	has_duplicates(t_stack *stack)
{
	t_stack *outer = stack;
	while (outer)
	{
		t_stack *inner = outer->next;
		while (inner)
		{
			if (outer->value == inner->value)
				return (1);
			inner = outer->next;
		}
		outer = outer->next;
	}
	return (0);
}