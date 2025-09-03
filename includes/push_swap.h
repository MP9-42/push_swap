/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/09/03 07:59:08 by MP9              ###   ########.fr       */
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

typedef struct s_stack
{
	int				index;
	int				stack_a;
	int				stack_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_struct
{
	t_stack			*head;
	int				size;
}					t_struct;

void	free_matrix(char **matrix);
void	*ft_memmove(void *dst, const void *src, size_t len);
long	ft_atoli(char *str);
char	*ft_inputjoin(char const *s1, char const *s2);
char	*take_input(char **argv, int argc);
char	**error_handle(char **argv, int argc);
char	**error_handle2(char **bigstr);
int		*create_stacka(char **bigstr);
int		*stackerror(char **matrix, int *stack_a);
int		ft_stacklen(int *stack);
char	**check_dup(char **matrix);

void	init_list(t_struct *stacklist, int *stack_a, int *stack_b);

#endif