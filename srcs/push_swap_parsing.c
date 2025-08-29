/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:51:52 by MP9               #+#    #+#             */
/*   Updated: 2025/08/29 23:53:10 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	*assign_stack(int *stack_a, char **argv)
// {
// 	int	i;

// 	i = 1;
// 	while (argv[argi] != NULL)
// 	{
// 		stack_a[i - 1] = ft_atoli(argv[i]);
// 		if (ft_atoli(argv[i]) == 0)
// 			return (NULL);
// 		i++;
// 	}
// 	stack_a[i] = '\0';
// 	return (stack_a);
// }

int	*create_stacks(char **argv)
{
	int	*stack;
	int	argi;
	int	argi2;
	int	counter;

	argi = 1;
	argi2 = 0;
	counter = 0;
	while (argv[argi] != NULL)
	{
		while (argv[argi][argi2] != '\0')
		{
			if (argv[argi][argi2] == ' ')
				counter++;
			argi2++;
		}
		argi++;
	}
	stack = (int *)malloc(sizeof(char) * (argi2 - counter + 1));
	if (!stack)
		return (NULL);
	return (stack);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	len;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	joinstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!joinstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		joinstr[i] = s1[i];
		i++;
	}
	joinstr[i++] = ' ';
	while (s2[i2] != '\0')
	{
		joinstr[i] = s2[i2];
		i++;
		i2++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
// 	int	argi;
// 	int	argi2;
// 	int	counter;

// 	argi = 1;
// 	argi2 = 0;
// 	counter = 0;
// 	while (argv[argi] != NULL)
// 	{
// 		while (argv[argi][argi2] != '\0')
// 		{
// 			if (argv[argi][argi2] == ' ')
// 				counter++;
// 			argi2++;
// 		}
// 		argi++;
// 	}
// 	stack = (int *)malloc(sizeof(char) * (argi2 - counter + 1));
// 	if (!stack)
// 		return (NULL);
// 	return (stack);
// }

char	*input_parsing(char **argv, int argc)
{
	int		argi;
	char	*numbers;

	argi = 1;
	if (argc >= 3)
	{
		numbers = ft_strjoin(argv[argi], argv[argi + 1]);
		argi++;
		while (argv[argi + 1] != NULL)
		{
			argi++;
			numbers = ft_strjoin(numbers, argv[argi]);
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
