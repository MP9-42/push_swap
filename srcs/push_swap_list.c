/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 05:43:19 by MP9               #+#    #+#             */
/*   Updated: 2025/09/04 20:21:12 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	create_stack(t_stack *s_a, t_stack *s_b, int *nums)
{
	int		len;
	int		i;
	t_node	*node;

	i = 0;
	len = ft_stacklen(s_a);
	s_a->size = len;
	node = s_a->head;
	while (node)
	{
		node->index = i;
		node->number = nums[i];
		node = node->next;
		i++;
	}
	return (*s_a);
}

