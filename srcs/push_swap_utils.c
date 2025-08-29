/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:24 by MP9               #+#    #+#             */
/*   Updated: 2025/08/29 20:04:43 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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
		return ((long) NULL);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			prepoc = prepoc * -1;
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*sorc;
	char		*dest;

	i = 0;
	sorc = (const char *)src;
	dest = (char *)dst;
	if (dst > src)
	{
		while (len != 0)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
	}
	if (dst < src)
	{
		while (i != len)
		{
			dest[i] = sorc[i];
			i++;
		}
	}
	return (dst);
}

