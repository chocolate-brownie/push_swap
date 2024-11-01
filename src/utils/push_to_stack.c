/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/01 17:15:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*split_and_push(char *str)
{
	char	**nums;
	t_list	*stk;
	int		i;

	stk = NULL;
	i = 0;
	nums = ft_split(str, ' ');
	if (!nums)
		error_exit();
	while (nums[i])
	{
		if (!is_valid_input(nums[i]))
		{
			free_split(nums);
			free_stack(&stk);
			error_exit();
		}
		stk = push_numbers_to_stack(nums[i], stk);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (stk);
}

bool	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

t_list	*push_numbers_to_stack(char *str, t_list *stk)
{
	long num;
	t_list *new_node;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		free_stack(&stk);
		error_exit();
	}

	new_node = create_node((int)num);
	new_node->next = stk;
	if (stk != NULL)
		stk->prev = new_node;

	return (new_node);
}