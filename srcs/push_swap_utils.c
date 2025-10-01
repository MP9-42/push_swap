/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:24 by MP9               #+#    #+#             */
/*   Updated: 2025/10/01 15:16:02 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_oldlen(char **numbers)
{
	int	i;

	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i] != NULL)
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
	if (*str == '+' || *str == '-')
		exit(printf("%s", ERROR_MSG));
	ft_atoli_support(str, &number, &prepoc);
	return (prepoc * number);
}

void	ft_atoli_support(char *str, long *number, long *prepoc)
{
	while (*str >= '0' && *str <= '9')
	{
		*number = *number * 10 + (*str - '0');
		str++;
		if (*str == '+' || *str == '-')
			exit(printf("%s", ERROR_MSG));
	}
	if ((*prepoc * *number) < INT_MIN || (*prepoc * *number) > INT_MAX)
		exit(ft_printf("%s", ERROR_MSG));
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

void	check_dup(char **matrix)
{
	if (ft_numcmp(matrix) == 1)
	{
		free_matrix(matrix);
		exit(ft_printf("%s", ERROR_MSG));
	}
}
