/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:51:52 by MP9               #+#    #+#             */
/*   Updated: 2025/09/01 18:42:10 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*create_stacka(char **bigstr)
{
	int	*stack_a;
	int	i;

	i = 0;
	while (bigstr[i] != NULL)
		i++;
	stack_a = (int *)malloc(sizeof(int) * i + 1);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (bigstr[i] != NULL)
	{
		stack_a[i] = ft_atoli(bigstr[i]);
		i++;
	}
	stack_a[i] = '\0';
	return (stack_a);
}

char	**error_handle(char **argv, int argc)
{
	char	**bigstr;
	char	*input;

	input = take_input(argv, argc);
	bigstr = ft_split(input, ' ');
	check_dup(bigstr);
	error_handle2(bigstr);
	return (bigstr);
}

char	**error_handle2(char **bigstr)
{
	int		bi;
	int		si;

	bi = 0;
	si = 0;
	while (bigstr[bi] != NULL)
	{
		si = 0;
		while (bigstr[bi][si])
		{
			if (!(bigstr[bi][si] >= '0' && bigstr[bi][si] <= '9')
				&& bigstr[bi][si] != '-' && bigstr[bi][si] != '+')
			{
				ft_printf("%s", ERROR_MSG);
				free_matrix(bigstr);
				exit (0);
			}
			si++;
		}
		bi++;
	}
	return (bigstr);
}

char	*take_input(char **argv, int argc)
{
	int		argi;
	char	*numbers;

	argi = 1;
	if (argc >= 3)
	{
		numbers = ft_inputjoin(argv[argi], argv[argi + 1]);
		argi++;
		while (argv[argi + 1] != NULL)
		{
			argi++;
			numbers = ft_inputjoin(numbers, argv[argi]);
		}
	}
	else
	{
		numbers = (char *)malloc(sizeof(char) * ft_strlen(argv[argi] + 1));
		if (!numbers)
			return (NULL);
		ft_strlcpy(numbers, argv[argi], ft_strlen(argv[argi]) + 1);
	}
	return (numbers);
}

int	*stackerror(char **matrix, int *stack_a)
{
	int	i;
	int	*stack_b;

	if (!stack_a)
	{
		free_matrix(matrix);
		ft_printf("%s", ERROR_MSG);
		exit(0);
	}
	i = ft_stacklen(stack_a);
	stack_b = (int *)malloc(sizeof(int) * (i + 1));
	if (!stack_b)
	{
		free_matrix(matrix);
		free(stack_a);
		ft_printf("%s", ERROR_MSG);
		exit(0);
	}
	else
		return (stack_b);
}
