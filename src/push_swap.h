/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:30:57 by besalort          #+#    #+#             */
/*   Updated: 2023/07/11 18:17:51 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_lst
{
	int		value;
	int		indice;
	void	*next;
}	t_lst;

typedef struct s_data
{
	int		coups;
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
// VERIF.C
int		ft_count_pile(t_lst *pile);
int		is_double_in_lst(t_data *data);
int		is_sort(t_data *data);
int		ft_is_only_number(char **av);
int		verif(t_data *data);
// ALGO_RE-ORDER.C
void	put_right_order(t_data *data, t_lst *pile, char c);
void	put_at_the_start(t_data *data, t_lst *pile, char c, int count);
void	put_at_the_end(t_data *data, t_lst *pile, char c, int count);
// ALGO_BIS.C
int		ft_compare(t_lst *first, t_lst *second);
int		is_pile_sort(t_lst *pile);
int		is_highest(t_lst *pile);
int		is_lowest(t_lst *pile);
void	sort_one_element(t_data *data, t_lst *pile, char c);
// ALGO.C
void	algo(t_data *data);
void	algo_3case(t_data *data);
void	algo_10case(t_data *data);
// UPDATE_INDICE.C
void	ft_update_indice(t_data *data);
//
//
//
//
void	printpile(t_data *data);
//
//
//
#endif