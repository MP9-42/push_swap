/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 04:07:51 by MP9               #+#    #+#             */
/*   Updated: 2025/09/08 17:15:23 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*allocate_node(t_node *why, int *nums)
{
	why = (t_node *)malloc(sizeof(t_node));
	if (!why)
	{
		free(nums);
		exit(ft_printf("%s", ERROR_MSG));
	}
	return (why);
}

