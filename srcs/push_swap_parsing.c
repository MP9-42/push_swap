/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:51:52 by MP9               #+#    #+#             */
/*   Updated: 2025/09/12 19:35:36 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*get_nums(char **bigstr)
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

int	*error_handle(char **argv, int argc)
{
	char	**bigstr;
	char	*input;
	int		*numbers;

	input = take_input(argv, argc);
	bigstr = ft_split(input, ' ');
	bigstr = check_dup(bigstr);
	bigstr = error_handle2(bigstr);
	numbers = get_nums(bigstr);
	free(input);
	free_matrix(bigstr);
	return (numbers);
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
				free_matrix(bigstr);
				exit (ft_printf("%s", ERROR_MSG));
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
	numbers = NULL;
	if (argc <= 1)
		exit(ft_printf("%s", ERROR_MSG));
	else if (argc >= 3)
	{
		numbers = ft_inputjoin(argv[argi], argv[argi + 1]);
		argi++;
		while (argv[argi + 1] != NULL)
		{
			argi++;
			numbers = ft_inputjoin(numbers, argv[argi]);
		}
	}
	else if (argc == 2)
	{
		numbers = (char *)malloc(sizeof(char) * ft_strlen(argv[argi] + 1));
		if (!numbers)
			return (NULL);
		ft_strlcpy(numbers, argv[argi], ft_strlen(argv[argi]) + 1);
	}
	return (numbers);
}

int	*stackerror(char **matrix, int *numbers)
{
	if (!numbers)
	{
		free_matrix(matrix);
		exit(ft_printf("%s", ERROR_MSG));
	}
	else
		return (numbers);
}
