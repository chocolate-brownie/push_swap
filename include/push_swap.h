/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/10/31 17:46:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/* utils functions */
void				error_exit(void);

/* stack manipulation */
void				add_item_end(t_stack *head, int value);
void				add_item_start(t_stack **head, int value);
int					remove_last(t_stack *head);
void				init_stack(t_stack **a, t_stack **b);

/* args manipulation */
int					check_args(int argc, char **argv);
int					number_args(int argc, char **argv);
int					string_args(char *str);
int					is_valid_number(char *str);

#endif
