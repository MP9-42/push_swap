/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:40:20 by MP9               #+#    #+#             */
/*   Updated: 2025/08/29 20:38:36 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	edge_case(int n)
{
	if (n == INT_MIN)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
	}
	return (11);
}

int	ft_putnbr(int n)
{
	char	digit;
	int		count;
	int		temp;

	count = 0;
	if (n == INT_MIN)
		return (edge_case(n));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		temp = ft_putnbr(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	digit = '0' + (n % 10);
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (count + 1);
}
