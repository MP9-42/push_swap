/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 05:43:19 by MP9               #+#    #+#             */
/*   Updated: 2025/09/08 17:13:04 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_stack_a(int *nums)
{
	int		len;
	t_node	*node;
	t_stack	*stack;

	len = ft_stacklen(nums);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		free(nums);
		exit(ft_printf("%s", ERROR_MSG));
	}
	node = create_nodes(nums, NULL);
	stack->size = len;
	stack->head = node;
	return (stack);
}

t_node	*create_nodes(int *nums, t_node	*head)
{
	int		i;
	int		len;
	t_node	*new_node;
	t_node	*prev_node;

	i = 0;
	len = ft_stacklen(nums);
	head = NULL;
	prev_node = NULL;
	while (i < len)
	{
		new_node = allocate_node(new_node, nums);
		new_node->index = i;
		new_node->number = nums[i];
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
			prev_node->next = new_node;
		prev_node = new_node;
		i++;
	}
	free(nums);
	return (head);
}

t_stack	*create_stack_b(t_stack *stack_a)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		free(stack_a);
		exit(ft_printf("%s", ERROR_MSG));
	}
	stack->size = 0;
	stack->head = NULL;
	return (stack);
}

