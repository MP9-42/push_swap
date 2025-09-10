/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:14:26 by MP9               #+#    #+#             */
/*   Updated: 2025/09/11 00:10:43 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	*sort(int *stack_a, int *stack_b)
// {
// 	int	len;

// 	len = ft_stack_oldlen(stack_a);
// 	while (ft_stack_oldlen(stack_b) != len)
// 	{

// 	}
// }

int	*asort(int *stack_a, int len)
{
	int	i2;

	i2 = 1;
	while (i2 != len - 1)
	{
		if (stack_a[0] > stack_a[i2])
		{
			stack_a = rrotate(stack_a, len);
			i2 = 1;
			ft_printf("rra\n");
		}
		while (stack_a[0] < stack_a[i2] && i2 < (len - 1))
			i2++;
	}
	return (stack_a);
}

int	*bsort(int *stack_a, int *stack_b, int len)
{
	int	i;

	i = 0;
	while (i != len)
	{
		stack_a = asort(stack_a, len);
		stack_b = pushnrotate(stack_a, stack_b, len);
		i++;
	}
	return (stack_b);
}
