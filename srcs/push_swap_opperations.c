/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opperations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:40:41 by MP9               #+#    #+#             */
/*   Updated: 2025/09/11 00:10:43 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_old	*rrotate(t_stack_old *stack_a)
{
	t_stack_old	*prev;
	t_stack_old	*last;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	prev = NULL;
	last = stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_a;
	return (last);
}

// int	*rotate(int *stack, int len)
// {
// 	int	i;
// 	int	value;

// 	i = 0;
// 	value = stack[0];
// 	while (i < len - 1)
// 	{
// 		stack[i] = stack[i + 1];
// 		i++;
// 	}
// 	stack[len - 1] = value;
// 	return (stack);
// }

// int	*pushnrotate(int *stack_a, int *stack_b, int len)
// {
// 	stack_b[0] = stack_a[0];
// 	stack_a[0] = '\0';
// 	ft_printf("pb && stack_b: %i\n", stack_b[0]);
// 	stack_a = rotate(stack_a, len);
// 	ft_printf("ra && stack_a: %i\n", stack_a[0]);
// 	stack_b = rrotate(stack_b, len);
// 	ft_printf("rrb && stack_b: %i\n", stack_b[0]);
// 	return (stack_b);
// }

