/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:14:26 by MP9               #+#    #+#             */
/*   Updated: 2025/09/30 21:46:31 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_idx;
	int	max_bits;
	int	i;

	if (!a || a->size <= 1)
		return ;
	size = a->size;
	max_idx = a->size - 1;
	max_bits = 0;
	while ((max_idx >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_support(a, b, &i, &size);
	}
}

void	radix_support(t_stack *a, t_stack *b, int *i, int *size)
{
	int	j;

	j = 0;
	while (j < *size)
	{
		if (((a->head->index >> *i) & 1) == 0)
		{
			push(b, a);
			ft_printf("pb\n");
		}
		else
		{
			rotate(a);
			ft_printf("ra\n");
		}
		j++;
	}
	while (b->size > 0)
	{
		push(a, b);
		ft_printf("pa\n");
	}
	(*i)++;
}

int	check_sort(t_stack *stack)
{
	t_node	*temp;
	int		counter;

	counter = 0;
	temp = stack->head;
	while (temp->next && counter != stack->size - 1)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
		counter++;
	}
	return (1);
}
