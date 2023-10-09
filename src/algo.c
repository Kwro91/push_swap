/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:36 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 17:05:54 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chose_fastest(t_data *data)
{
	int		indice;
	int		fastest;
	t_lst	*tmp;

	indice = 0;
	fastest = 1000;
	tmp = data->pile_b;
	while (tmp)
	{
		if (tmp->to_sort < fastest)
		{
			fastest = tmp->to_sort;
			indice = tmp->indice;
		}
		tmp = tmp->next;
	}
	return (indice);
}

void	algo_3case(t_data *data)
{
	t_lst	*tmp;

	tmp = data->pile_a;
	tmp = tmp->next;
	if (is_pile_sort(data->pile_a) == 1)
		return ;
	if (is_highest(data->pile_a) == 1)
		rotate(data, 'a');
	else if (ft_compare(data->pile_a, tmp) == 1)
		swap(data, 'a');
	else if (ft_compare(data->pile_a, tmp->next) == 1)
		rotate(data, 'a');
	else
		reverse_rotate(data, 'a');
	if (is_pile_sort(data->pile_a) == 0)
		algo_3case(data);
}

void	algo_final(t_data *data, int elements)
{
	t_lst	*tmp;
	int		count;
	int		fastest;

	count = elements;
	while (count > 3)
	{
		push(data, 'b');
		tmp = data->pile_b;
		if (tmp->value >= data->mediane && count < elements)
			rotate(data, 'b');
		count--;
	}
	algo_3case(data);
	while (ft_count_pile(data->pile_b) > 0)
	{
		update_all_sort_indice(data);
		update_all_sort_time(data);
		fastest = chose_fastest(data);
		prepare_to_sort(data, fastest, using_r(data, fastest));
		sort_all(data);
	}
	reorder_pile(data);
}

void	algo(t_data *data)
{
	data->nb_elem = 0;
	data->nb_elem = ft_count_pile(data->pile_a);
	mediane(data, data->nb_elem);
	if (data->nb_elem == 2)
		swap(data, 'a');
	if (data->nb_elem == 3)
		algo_3case(data);
	else if (data->nb_elem > 3)
		algo_final(data, data->nb_elem);
}
