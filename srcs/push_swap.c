/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/04 20:33:27 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int			*numbers;
	t_stack		stack_a;
	t_stack		stack_b;
	int			i;

	i = 0;
	argv = error_handle(argv, argc);
	numbers = get_nums(argv);
	numbers = stackerror(argv, numbers);
	stack_a = init_list(&stack_a, &stack_b, numbers);
	stack_a->head;
	while ()
	{
		
	}
	return (0);
}
