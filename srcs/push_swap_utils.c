/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:24 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 05:27:06 by MP9              ###   ########.fr       */
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
		return (INT_MIN + 1);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			prepoc = prepoc * (-1);
		str++;
	}
	if (*str == '+' || *str == '-')
		return (INT_MIN + 1);
	return (ft_atoli_support(str, &number, &prepoc));
}

long	ft_atoli_support(char *str, long *number, long *prepoc)
{
	while (*str >= '0' && *str <= '9')
	{
		*number = *number * 10 + (*str - '0');
		str++;
		if (*str == '+' || *str == '-')
			return (INT_MIN + 1);
	}
	if ((*prepoc * *number) < INT_MIN || (*prepoc * *number) > INT_MAX)
		return (INT_MIN + 1);
	return (*prepoc * *number);
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

int	check_dup(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	int		i2;

	i = stack->size - 1;
	if (!stack)
		return (1);
	current = stack->head;
	while (i > 0)
	{
		compare = current->next;
		i2 = i - 1;
		while (i2 > 0)
		{
			if (compare->value == current->value)
				return (1);
			compare = compare->next;
			i2--;
		}
		current = current->next;
		i--;
	}
	return (0);
}
