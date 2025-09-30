/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/09/30 01:58:17 by MP9              ###   ########.fr       */
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
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	free(nums);
	free(sorted_nums);
}

int	distance(t_stack *stack)
{
	int		counter;
	t_node	*current;

	if (!stack || !stack->head)
		return (0);
	counter = 0;
	current = stack->head;
	while (current->index != stack->size)
	{
		current = current -> next;
		counter++;
		if (current == stack->head)
			return (-1);
	}
	return (counter);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	i = 0;
	if (!stack || !stack->head)
		return ;
	current = stack->head;
	while (i < stack->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	stack->head = NULL;
	stack->size = 0;
}
