/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:40:41 by MP9               #+#    #+#             */
/*   Updated: 2025/09/09 23:22:40 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*rrotate(int *stack, int len)
{
	int	i2;
	int	value;
	
	i2 = (len - 1);
	value = stack[i2];
	while (i2 > -1)
	{
		stack[i2] = stack[i2 - 1];
		i2--;
	}
	stack[0] = value;
	return (stack);
}

int *rotate(int *stack, int len)
{
	int i;
	int value;

	i = 0;
	value = stack[0];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = value;
	return (stack);
}

int *pushnrotate(int *stack_a, int *stack_b, int len)
{
	stack_b[0] = stack_a[0];
	stack_a[0] = '\0';
	ft_printf("pb && stack_b: %i\n", stack_b[0]);
	stack_a = rotate(stack_a, len);
	ft_printf("ra && stack_a: %i\n", stack_a[0]);
	stack_b = rrotate(stack_b, len);
	ft_printf("rrb && stack_b: %i\n", stack_b[0]);
	return (stack_b);
}