/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:25:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/01 13:21:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	/* make the initial stack null to avoid undefined behaviour  */
	init_stack_null(stk_a, stk_b);
	/* checking for the correct format of args */
	if (!check_args(argc, argv))
		error_exit();
	/* if the args are correct push the numbers in to the stack_a */
	init_stack_a(&stk_a, argv + 1);
	/* if the numbers are not sorted continue  */
	if (!stack_sorted(stk_a))
	{
		if (stack_len(stk_a) == 2)
			sa(&stk_a, false);
		else if (stack_len(stk_a) == 3)
			sort_three(&stk_a);
		else
			turk_algorithm(&stk_a, stk_b);
	}
	free_stack(&stk_a);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	return (0);
}