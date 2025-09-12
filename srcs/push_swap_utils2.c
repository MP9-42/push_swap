/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/09/12 19:34:13 by MP9              ###   ########.fr       */
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
