/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/08/31 19:42:19 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// char *handle_errors(int *stack_a)
// {
// 	int	i;
// 	int	i2;
// }

int	main(int argc, char **argv)
{
	char	**numbers;
	int		i;

	numbers = error_handle2(argv, argc);
	while (numbers[i] != NULL)
	{
		ft_printf("stack value %s\n", numbers[i]);
		i++;
	}
	return (0);
}
