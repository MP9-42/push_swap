/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/09/10 21:54:25 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
}				t_stack;

typedef struct s_sort
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_sort;

//utils
void		free_matrix(char **matrix);
void		*ft_memmove(void *dst, const void *src, size_t len);
long		ft_atoli(char *str);
char		*ft_inputjoin(char const *s1, char const *s2);
int			ft_stacklen(int *stack);
char		**check_dup(char **matrix);

//stack creation
t_sort		*create_stacks(int *numbers);
t_stack		*stack_allocate(int *numbers);
t_stack		*assign_values(t_stack *stack, int *numbers);

//parsing
int			*error_handle(char **argv, int argc);
char		**error_handle2(char **bigstr);
char		*take_input(char **argv, int argc);
int			*get_nums(char **bigstr);
int			*stackerror(char **matrix, int *stack_a);

//algorithm
t_stack		*rrotate(t_stack *stack);
int			*asort(int *stack_a, int len);
int			*bsort(int *stack_a, int *stack_b, int len);
int			*pushnrotate(int *stack_a, int *stack_b, int len);
int			*rotate(int *stack, int len);

#endif
