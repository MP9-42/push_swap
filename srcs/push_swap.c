/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/01 18:45:59 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	int		*stack_a;
	int		*stack_b;
	int		i;

	i = 0;
	numbers = error_handle(argv, argc);
	stack_a = create_stacka(numbers);
	stack_b = stackerror(numbers, stack_a);
	while (stack_a[i] != '\0')
	{
		stack_b[i] = stack_a[i];
		i++;
	}
	i = 0;
	while (stack_a[i] != '\0')
	{
		ft_printf("stack : %d\n", stack_a[i]);
		ft_printf("stack : %d\n", stack_b[i]);
		i++;
	}
	return (0);
}
