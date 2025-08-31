/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:51:52 by MP9               #+#    #+#             */
/*   Updated: 2025/08/31 21:27:41 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	*create_stacka(char **bigstr)
// {

// }

char	**error_handle(char **argv, int argc)
{
	char	**bigstr;
	char	*input;

	input = take_input(argv, argc);
	bigstr = ft_split(input, ' ');
	check_dup(bigstr);
	return (bigstr);
}

char	**error_handle2(char **argv, int argc)
{
	int		bi;
	int		si;
	char	**bigstr;

	bi = 0;
	si = 0;
	bigstr = error_handle(argv, argc);
	while (bigstr[bi] != NULL)
	{
		while (bigstr[bi][si])
		{
			if ((bigstr[bi][si] < '0' && bigstr[bi][si] > '9')
				&& bigstr[bi][si] != ' ')
			{
				ft_printf("%s", ERROR_MSG);
				free(bigstr);
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
