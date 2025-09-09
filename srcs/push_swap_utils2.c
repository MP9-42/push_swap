/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/09/09 23:05:41 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *create_stack_b(int *nums)
{
	int		*stack_b;
	int		len;

	len = ft_stacklen(nums);
	stack_b = (int *)ft_calloc(sizeof(int) , len);
	if (!stack_b)
	{
		free(nums);
		return (NULL);
	}
	return (stack_b);
}

