/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:51:52 by MP9               #+#    #+#             */
/*   Updated: 2025/10/01 16:23:28 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_nums(char **bigstr)
{
	if (ft_numcmp(bigstr) == 1)
	{
		free_matrix(bigstr);
		exit(ft_printf("%s", ERROR_MSG));
	}
}

char	**error_handle(char **argv, int argc)
{
	char	**bigstr;
	char	*input;

	input = take_input(argv, argc);
	bigstr = ft_split(input, ' ');
	free(input);
	check_dup(bigstr);
	error_handle2(bigstr);
	get_nums(bigstr);
	return (bigstr);
}

void	error_handle2(char **bigstr)
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
}

char	*take_input(char **argv, int argc)
{
	int		argi;
	char	*numbers;

	argi = 1;
	numbers = NULL;
	if (argc <= 1)
		exit(1);
	else if (argc >= 3)
	{
		numbers = ft_inputjoin(argv[argi], argv[argi + 1]);
		argi++;
		while (argv[argi + 1] != NULL)
		{
			argi++;
			numbers = ft_joinnfree(numbers, argv[argi]);
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
