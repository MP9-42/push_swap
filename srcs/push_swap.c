/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:11 by MP9               #+#    #+#             */
/*   Updated: 2025/09/11 01:49:12 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

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

void	print_stack(t_stack *stack)
{
	int i = 0;

	t_node *current = stack->head;
	while (i < stack->size)
	{
		ft_printf("node [%d]: value = (%d), index = (%d)\n",i, current->value, current->index);
		current = current->next;
		i++;
	}
}
// Funktion zum Sortieren mit Bubble Sort (nur mit while)
int	*sort_array(int *array_num)
{
    int	i;
	int	n;
	int	swapped;
	int	j;
	int	temp;

	i = 0;
    while (array_num[i] != '\0')
        i++;
    n = i;
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

// Hauptprogramm zum Testen
// int main() {
//     // -1 als Endmarkierung
//     int arr[] = {64, 34, 25, 12, 22, 11, 90, -1};

//     sort_array(arr);

//     printf("Sortiertes Array: ");
//     int i = 0;
//     while (arr[i] != -1) {
//         printf("%d ", arr[i]);
//         i++;
//     }
//     return 0;
// }

void	free_node(t_node *node)
{
	while (node->next || node->prev)
	{
		free(node->next);
		node = node->prev;
	}
	if (!node->next || !node->prev)
		free(node);
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		exit(ft_printf("%s", ERROR_MSG));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_node(node);
		exit(ft_printf("%s", ERROR_MSG));
	}
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->index = index;
	return (node);
}

void	add_node_into_stack(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		node->next = node;
		node->prev = node;
	}
	if (stack->size > 0)
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
	stack->size++;
}

void build_stack(t_stack *stack_a, int *numbers, int *sorted_nums)
{
	int		ni;
	int		si;
	t_node	*node;

	ni = 0;
	node = NULL;
	while (sorted_nums[ni] != '\0')
	{
		si = 0;
		while (numbers[si] != '\0')
		{
			if (numbers[si] == sorted_nums[ni])
			{
				node = create_node(numbers[si], ni);
				add_node_into_stack(stack_a, node);
			}
			si++;
		}
		ni++;
	}
}

int	main(int argc, char **argv)
{
	int				*numbers;
	int				*sorted_nums;

	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = create_empty_stack();
	stack_b = create_empty_stack();
	if (stack_a == NULL || stack_b == NULL)
		return(1);
		
	// t_sort			*list;
	// t_stack_old			*next_a;
	// t_stack_old			*next_b;
	numbers = error_handle(argv, argc);
	print_array(numbers , "numbers1");
	numbers = stackerror(argv, numbers);
	print_array(numbers , "numbers3");
	sorted_nums = sort_array(numbers);
	print_array(sorted_nums , "sorted_nums");
	print_array(numbers , "nums");
	build_stack(stack_a, numbers, sorted_nums);
	print_stack(stack_a);
	// list = create_stacks(numbers);
	// next_a = list->stack_a;
	// next_b = list->stack_b;
	// next_a = rrotate(next_a);
	// i = 0;
	// while (sorted_nums[i] != '\0')
	// {
	// 	ft_printf("sorted_nums: %i\n", sorted_nums[i]);
	// 	i++;
	// }
	return (0);
}
