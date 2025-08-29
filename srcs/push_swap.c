/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/08/29 20:04:11 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// char *handle_errors(int *stack_a)
// {
// 	int	i;
// 	int	i2;
// }

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = create_stacks(argc, argv);
	stack_b = create_stacks(argc, argv);
	i = 0;
	assign_stack(stack_a, argc, argv);
	while (stack_a[i] != '\0')
	{
		printf("stack value %d\n", stack_a[i]);
		i++;
	}
	return (0);
}
