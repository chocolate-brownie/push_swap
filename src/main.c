/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:25:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/10/31 18:28:23 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	init_stack(&stk_a, &stk_b);
	if (!check_args(argc, argv))
		error_exit();
	return (0);
}
