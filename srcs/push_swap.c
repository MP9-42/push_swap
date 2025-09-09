/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/09 22:30:58 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int			*stack_a;
	int			*stack_b;
	int			i;
	int			len;

	i = 0;
	stack_a = error_handle(argv, argc);
	stack_a = stackerror(argv, stack_a);
	stack_b = create_stack_b(stack_a);
	len = ft_stacklen(stack_a);
	stack_b = bsort(stack_a, stack_b, len);
	while (i != len)
	{
		ft_printf("stack_a: %i\n", stack_a[i]);
		ft_printf("stack_b: %i\n", stack_b[i]);
		i++;
	}
	return (0);
}
