/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:40:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/01 16:54:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_list **stk)
{
	t_list *current;
	t_list *next;

	if (!stk || !*stk)
		return ;
	current = *stk;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stk = NULL;
}