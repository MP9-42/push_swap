/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/01 16:45:17 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	// int		*stack_a;
	// int		*stack_b;
	int		i;

	numbers = error_handle(argv, argc);
	while (numbers[i] != NULL)
	{
		ft_printf("numbers : %s\n", numbers[i]);
		i++;
	}
	// stack_a = create_stacka(numbers);
	// i = 0;
	// while (stack_a[i] != '\0')
	// {
	// 	ft_printf("stack : %i\n", stack_a);
	// 	i++;
	// }
	// stack_b = (int *)malloc(sizeof(int) * (ft_stacklen(stack_a) + 1));
	// stackerror(numbers, stack_a, stack_b);
	return (0);
}
