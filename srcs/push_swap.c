/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/10 22:00:20 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int				*numbers;
	t_sort			*list;
	t_stack			*next_a;
	t_stack			*next_b;

	numbers = error_handle(argv, argc);
	numbers = stackerror(argv, numbers);
	list = create_stacks(numbers);
	next_a = list->stack_a;
	next_b = list->stack_b;
	next_a = rrotate(next_a);
	while (next_a)
	{
		ft_printf("stack_a: %i\n", next_a->value);
		next_a = next_a->next;
	}
	while (next_b)
	{
		ft_printf("stack_b: %i\n", next_b->value);
		next_b = next_b->next;
	}
	return (0);
}
