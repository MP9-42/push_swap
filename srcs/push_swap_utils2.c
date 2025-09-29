/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/09/29 18:42:41 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	print_stack(t_stack *stack)
{
	int		i;
	t_node	*current;

	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		ft_printf("node [%d]: value = (%d),", i, current->value);
		ft_printf("index = (%d)\n", current->index);
		current = current->next;
		i++;
	}
}

void	print_array(int *array_num, char *name_array)
{
	int	i;

	i = 0;
	while (array_num[i] != '\0')
	{
		ft_printf("%s[%d]: %d\n", name_array, i, array_num[i]);
		i++;
	}
}

void	free_all(t_stack *a, t_stack *b, int *nums, int *sorted_nums)
{
	while (a->head != NULL)
	{
		free_node(a->head);
		a->head = a->head->next;
	}
	while (b->head != NULL)
	{
		free_node(b->head);
		b->head = b->head->next;
	}
	free(nums);
	free(sorted_nums);
}

int	distance(t_stack *stack)
{
	int	counter;

	counter = 0;
	while (stack->head && stack->head->index != stack->size)
	{
		stack->head = stack->head->next;
		counter++;
	}
	return (counter);
}
