/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:22:41 by MP9               #+#    #+#             */
/*   Updated: 2025/09/11 18:25:05 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_node(node);
		exit(ft_printf("%s", ERROR_MSG));
	}
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->index = index;
	return (node);
}

void	add_node_into_stack(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		node->next = node;
		node->prev = node;
	}
	if (stack->size > 0)
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
	stack->size++;
}

void	build_stack(t_stack *stack_a, int *numbers, int *sorted_nums)
{
	int		ni;
	int		si;
	t_node	*node;

	ni = ft_stack_oldlen(numbers);
	node = NULL;
	while (ni != -1)
	{
		si = 0;
		while (sorted_nums[si] != '\0')
		{
			if (numbers[ni] == sorted_nums[si])
			{
				node = create_node(numbers[ni], si);
				add_node_into_stack(stack_a, node);
			}
			si++;
		}
		ni--;
	}
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		exit(ft_printf("%s", ERROR_MSG));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	free_node(t_node *node)
{
	while (node->next || node->prev)
	{
		free(node->next);
		node = node->prev;
	}
	if (!node->next || !node->prev)
		free(node);
}
