/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:14:26 by MP9               #+#    #+#             */
/*   Updated: 2025/09/14 19:54:46 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	k_sort(t_stack *a, t_stack *b)
{
	int	count;
	int	range;

	count = 0;
	range = ft_sqrt(a->size) * 1,6;
	while (a->size > 0)
	{
		if (a->head->index <= count)
		{
			push(b, a);
			ft_printf("pb\n");
			rotate(b);
			ft_printf("rb\n");
			count++;
		}
		else if (index < count + range)
		{
			push(b, a);
			ft_printf("pb\n");
			count++;
		}
		else
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
	push_back(a, b);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	
	while (stack_b->size > 0)
	{
		if (stack_b->head->index == stack_b->size - 1)
		{
			push(stack_a, stack_b);
			ft_printf("pa\n");
			stack_b->size--;
		}
		else if ()
	}
}
