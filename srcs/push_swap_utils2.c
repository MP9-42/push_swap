/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/09/10 21:58:46 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_sort	*create_stacks(int *numbers)
{
	t_sort		*heads;

	heads = NULL;
	heads = (t_sort *)malloc(sizeof(t_sort));
	if (!heads)
	{
		free(numbers);
		return (NULL);
	}
	heads->stack_a = stack_allocate(numbers);
	heads->stack_b = stack_allocate(numbers);
	heads->stack_a = assign_values(heads->stack_a, numbers);
	return (heads);
}

t_stack	*stack_allocate(int *numbers)
{
	t_stack	*head;
	t_stack	*stack;
	int		i;

	head = (t_stack *)malloc(sizeof(t_stack));
	stack = head;
	stack->next = NULL;
	i = 1;
	while (numbers[i])
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (!stack->next)
		{
			free(numbers);
			return (NULL);
		}
		stack = stack->next;
		stack->next = NULL;
		i++;
	}
	return (head);
}

t_stack	*assign_values(t_stack *stack, int *numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != '\0' && stack != NULL)
	{
		stack->value = numbers[i];
		i++;
		stack = stack->next;
	}
	return (stack);
}
