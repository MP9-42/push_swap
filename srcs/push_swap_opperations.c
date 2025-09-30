/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opperations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:40:41 by MP9               #+#    #+#             */
/*   Updated: 2025/09/29 22:12:00 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	rrotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (stack->size == 2)
		stack->tail = first;
}

void	push(t_stack *dest, t_stack *src)
{
	t_node	*first;
	t_node	*second;

	first = src->head;
	second = first->next;
	if (!src || !src->head)
		return ;
	if (src->head == src->tail)
	{
		src->head = NULL;
		src->tail = NULL;
		src->size = 0;
	}
	else
	{
		first->next = NULL;
		first->prev = NULL;
		src->head = second;
		src->tail->next = second;
		second->prev = src->tail;
		src->size--;
	}
	add_node_into_stack(dest, first);
}
