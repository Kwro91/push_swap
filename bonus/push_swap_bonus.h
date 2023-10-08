/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:37:40 by besalort          #+#    #+#             */
/*   Updated: 2023/10/08 18:47:59 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS
# define PUSH_SWAP_BONUS

# include "./libft/libft.h"

typedef struct s_lst
{
	int		value;
	int		indice;
	int		sort_indice;
	int		to_sort;
	void	*next;
}	t_lst;

typedef struct s_data
{
	int		coups;
    char    **cmds;
	t_lst	*pile_a;
	t_lst	*pile_b;
}	t_data;

// CHECKER_BONUS.C
void    checker_ps(int ac, char **av);
t_lst	*create_elements_bonus(int size, char **elements, int indice);
// DO_CMDS.C
int    do_cmds(t_data *data);
// ERROR_CHECKER.C
void    error_checker(t_data *data);
// FREE_ALL_BONUS.C
void    ft_free_ps(t_data *data);
void    ft_free_pile(t_lst *pile);
// IS_SORT.C
int		is_pile_sort(t_lst *pile);
int		ft_count_pile(t_lst *pile);
// LOAD_BONUS.C
void    load_bonus(t_data *data, int ac, char **av);
// PUSH_BONUS.C
void	push(t_data *data, char p);
// READ_ALL.C
void    read_all(t_data *data);
void    cmd_stack(t_data *data, char *line);
void    free_cmds(t_data *data);
// REVERSE_ROTATE_BONUS.C
void	reverse_rotate(t_data *data, char p);
// ROTATE_BONUS.C
void	rotate(t_data *data, char p);
// SWAP_BONUS.C
void	swap(t_data	*data, char p);
// VERIF_BONUS.C
int		verif(t_data *data);
int		ft_is_only_int(char **av);
int		ft_is_only_number(char **av);
int		is_sort(t_data *data);
#endif