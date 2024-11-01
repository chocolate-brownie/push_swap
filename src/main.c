/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:25:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/01 17:17:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	init_stack_null(&stk_a, &stk_b);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		error_exit();
	else if (argc == 2)
	{
		stk_a = split_and_push(argv[1]);
		print_list(stk_a);
		printf("\n");
		print_list(stk_b);
	}
	/*
	if (!stk_a || check_duplicates(stk_a))
		error_exit();
	if (!stack_sorted(stk_a))
	{
		if (stack_len(stk_a) == 2)
			sa(&stk_a, false);
		else if (stack_len(stk_a) == 3)
			sort_three(&stk_a);
		else
			turk_algorithm(&stk_a, stk_b);
	}
	*/
	free_stack(&stk_a);
	return (0);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}