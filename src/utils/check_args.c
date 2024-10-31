/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:44:15 by mgodawat          #+#    #+#             */
/*   Updated: 2024/10/31 18:20:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_args(int argc, char **argv)
{
	if (argc > 2)
		return (number_args(argc, argv));
	else if (argc == 2)
		return (string_args(argv[1]));
	return (0);
}

int	number_args(int argc, char **argv)
{
	int	i;

	printf("Running number args\n");
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	string_args(char *str)
{
	int	i;

	printf("Running string args\n");
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}