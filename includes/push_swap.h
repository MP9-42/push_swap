/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/09/04 20:26:38 by MP9              ###   ########.fr       */
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

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

void		free_matrix(char **matrix);
void		*ft_memmove(void *dst, const void *src, size_t len);
long		ft_atoli(char *str);
char		*ft_inputjoin(char const *s1, char const *s2);
char		*take_input(char **argv, int argc);
char		**error_handle(char **argv, int argc);
char		**error_handle2(char **bigstr);
int			*get_nums(char **bigstr);
int			*stackerror(char **matrix, int *stack_a);
int			ft_stacklen(int *stack);
char		**check_dup(char **matrix);

t_stack		init_list(t_stack *s_a, t_stack *s_b, int *nums);

#endif