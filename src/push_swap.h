/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:30:57 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:26:28 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int		*tab;
	int		nb_elem;
	int		mediane;
	int		coups;
	int		high_a;
	int		low_a;
	t_lst	*pile_a;
	t_lst	*pile_b;
}	t_data;

// PUSH_SWAP.C
t_lst	*create_elements(int size, char **elements, int indice);
void	push_swap(int ac, char **av);
// PUSH.C
void	push(t_data *data, char p);
// REVERSE_ROTATE.C
void	reverse_rotate(t_data *data, char p);
// ROTATE.C
void	rotate(t_data *data, char p);
//SWAP.C
void	swap(t_data	*data, char p);
// LOAD.C
void	load(t_data *data, int ac, char **av);
// MEDIANE.C
void	create_tab(t_data *data);
void	sort_tab(t_data *data, int size);
void	mediane(t_data *data, int nb);
// VERIF.C
int		is_double_in_lst(t_data *data);
int		is_sort(t_data *data);
int		ft_is_only_number(char **av);
int		ft_is_only_int(char **av);
int		verif(t_data *data);
// ALGO_RE-ORDER.C
int		r_rotate(t_data *data, t_lst *tmp, int indice);
int		r_reverse(t_data *data, t_lst *tmp);
void	reorder_pile(t_data *data);
// ALGO_USE_R.C
int		using_r(t_data *data, int indice);
// ALGO_SORT_ELEMENT.C
void	sort_all(t_data *data);
void	sort_reverse(t_data *data, int indice);
void	sort_rotate(t_data *data, int indice);
void	prepare_to_sort(t_data *data, int indice, int r_done);
// ALGO_BIS.C
int		ft_compare(t_lst *first, t_lst *second);
int		is_pile_sort(t_lst *pile);
int		is_highest(t_lst *pile);
int		is_lowest(t_lst *pile);
int		ft_count_pile(t_lst *pile);
// ALGO.C
void	algo(t_data *data);
void	algo_3case(t_data *data);
void	algo_final(t_data *data, int elements);
int		chose_fastest(t_data *data);
// UPDATE_INDICE.C
void	ft_update_indice(t_data *data);
// ALGO_SORT_INDICE.C
int		value_of_last(t_lst *pile);
int		which_highest(t_lst *pile);
int		which_lowest(t_lst *pile);
int		indice_sort(t_data *data, int value);
// ALGO_UPDATE.C
void	update_all_sort_indice(t_data *data);
void	update_all_sort_time(t_data *data);
// FREE_ALL.C
void	ft_free_ps(t_data *data);
void	ft_free_pile(t_lst *pile);
//
//
//
//
void	printpile(t_data *data);
//
//
//
#endif