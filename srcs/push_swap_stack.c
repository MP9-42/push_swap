/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:22:41 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 05:46:23 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(char *value, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->prev = NULL;
	node->value = ft_atoli(value);
	if (ft_atoli(value) == INT_MIN + 1)
	{
		free(node);
		return (NULL);
	}
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

void	build_stack(t_stack *a, t_stack *b, char **nums, char **s_nums)
{
	int		ni;
	int		si;
	t_node	*node;

	ni = ft_stack_oldlen(nums) - 1;
	node = NULL;
	while (ni != -1)
	{
		si = 0;
		while (s_nums[si] != NULL)
		{
			if (ft_strcmp(nums[ni], s_nums[si]) == 0)
			{
				node = create_node(nums[ni], si);
				if (node == NULL)
				{
					free_all(a, b, nums, s_nums);
					exit(ft_printf("%s", ERROR_MSG));
				}
				add_node_into_stack(a, node);
			}
			si++;
		}
		ni--;
	}
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack) * 1);
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	free_node(t_node *node)
{
	if (node->next || node->prev)
	{
		free(node->next);
		node = node->prev;
	}
	else
		free(node);
}
