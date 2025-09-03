/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 05:43:19 by MP9               #+#    #+#             */
/*   Updated: 2025/09/03 08:03:09 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_list(t_struct *stacklist, int *stack_a, int *stack_b)
{
	t_stack	*temp;
	int		size;
	int		i;
	
	i = 0;
	size = ft_stacklen(stack_a);
	stacklist->size = size; 
	temp = stacklist->head;
	while (temp)
	{
		temp ->index = (i);
		temp->stack_a = stack_a[i];
		temp->stack_b = stack_b[i];
		temp = temp->next;
		i++;
	}
}

