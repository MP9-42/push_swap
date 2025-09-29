/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/24 18:00:43 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*sort_array(int *array_num, int len)
{
	int	n;
	int	swapped;
	int	j;
	int	temp;

	n = len;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < n - 1)
		{
			if (array_num[j] > array_num[j + 1])
			{
				temp = array_num[j];
				array_num[j] = array_num[j + 1];
				array_num[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
	}
	return (array_num);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		*sorted_nums;
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_empty_stack();
	stack_b = create_empty_stack();
	numbers = error_handle(argv, argc);
	numbers = stackerror(argv, numbers);
	len = ft_stack_oldlen(numbers);
	sorted_nums = error_handle(argv, argc);
	sorted_nums = stackerror(argv, sorted_nums);
	sorted_nums = sort_array(sorted_nums, len);
	build_stack(stack_a, numbers, sorted_nums);
	k_sort(stack_a, stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_all(stack_a, stack_b, numbers, sorted_nums);
	return (0);
}
