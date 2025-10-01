/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/10/01 19:26:15 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**sort_array(char **nums, int len)
{
	int		swapped;
	int		j;
	char	*temp;
	int		a;
	int		b;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < len && nums[j + 1] != NULL)
		{
			a = ft_atoli(nums[j]);
			b = ft_atoli(nums[j + 1]);
			temp = "\0";
			if (a > b)
				sort_array_support(&nums[j], &nums[j + 1], temp, &swapped);
			j++;
		}
	}
	return (nums);
}

void	sort_array_support(char **num, char **nxt_num, char *temp, int *swap)
{
	temp = *num;
	*num = *nxt_num;
	*nxt_num = temp;
	*swap = 1;
}

int	ft_numcmp(char **numbers)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (numbers[i])
	{
		i2 = i + 1;
		while (numbers[i] != numbers[i2] && numbers[i2] != NULL)
			i2++;
		if (numbers[i] == numbers[i2])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_joinnfree(char *joinstr, const char *s2)
{
	char	*newstr;

	newstr = ft_inputjoin(joinstr, s2);
	free(joinstr);
	return (newstr);
}

int	main(int argc, char **argv)
{
	char	**numbers;
	char	**sorted_nums;
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_empty_stack();
	stack_b = create_empty_stack();
	numbers = error_handle(argv, argc);
	sorted_nums = error_handle(argv, argc);
	len = ft_stack_oldlen(sorted_nums);
	sorted_nums = sort_array(sorted_nums, len);
	build_stack(stack_a, numbers, sorted_nums);
	if (check_sort(stack_a) == 1)
	{
		free_all(stack_a, stack_b, numbers, sorted_nums);
		return (0);
	}
	radix_sort(stack_a, stack_b);
	free_all(stack_a, stack_b, numbers, sorted_nums);
	return (0);
}
