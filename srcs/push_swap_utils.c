/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:24 by MP9               #+#    #+#             */
/*   Updated: 2025/09/04 19:26:31 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacklen(int *numbers)
{
	int	i;

	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i] != '\0')
		i++;
	return (i);
}

long	ft_atoli(char *str)
{
	long	number;
	long	prepoc;

	number = 0;
	prepoc = 1;
	if (ft_strlen(str) > 11)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			prepoc = prepoc * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if ((prepoc * number) < INT_MIN || (prepoc * number) > INT_MAX)
		return (0);
	return (prepoc * number);
}

char	*ft_inputjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	len;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	joinstr = (char *)malloc(sizeof(char) * (len + 2));
	if (!joinstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		joinstr[i] = s1[i];
		i++;
	}
	joinstr[i] = 32;
	while (s2[i2] != '\0')
	{
		i++;
		joinstr[i] = s2[i2];
		i2++;
	}
	joinstr[++i] = '\0';
	return (joinstr);
}

char	**check_dup(char **matrix)
{
	int	i;
	int	i2;

	i = 0;
	while (matrix[i] != NULL)
	{
		(i2 = i + 1);
		while (matrix[i2] != NULL)
		{
			if (ft_strncmp(matrix[i], matrix[i2], 12) == 0)
			{
				ft_printf("%s", ERROR_MSG);
				free_matrix(matrix);
				exit (0);
			}
			i2++;
		}
		i++;
	}
	return (matrix);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

