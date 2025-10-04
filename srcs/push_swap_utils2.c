/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 05:45:18 by MP9              ###   ########.fr       */
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

void	free_all(t_stack *a, t_stack *b, char **numbers, char **sorted_nums)
{
	if (a && b)
	{
		free_stack(a);
		free_stack(b);
		free(a);
		free(b);
	}
	if (numbers && sorted_nums)
	{
		free_matrix(numbers);
		free_matrix(sorted_nums);
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
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
