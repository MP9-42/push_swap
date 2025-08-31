/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/08/31 21:23:23 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

void	*ft_memmove(void *dst, const void *src, size_t len);
long	ft_atoli(char *str);
char	*ft_inputjoin(char const *s1, char const *s2);
char	*take_input(char **argv, int argc);
char	**error_handle(char **argv, int argc);
char	**error_handle2(char **argv, int argc);
int		*create_stacks(char **argv);
int		check_dup(char **matrix);

#endif