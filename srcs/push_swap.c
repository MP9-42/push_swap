/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/08 17:16:48 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int			*numbers;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_node		*nums;

	stack_b = NULL;
	stack_a = NULL;
	numbers = error_handle(argv, argc);
	numbers = stackerror(argv, numbers);
	stack_a = create_stack_a(numbers);
	stack_b = create_stack_b(stack_a);
	nums = stack_a->head;
	while (nums)
	{
		ft_printf("stack_a number value: %i\n", nums->number);
		ft_printf("stack_a number value: %i\n", nums->number);
		nums = nums->next;
	}
	return (0);
}
