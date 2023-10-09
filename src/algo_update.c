/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:17:23 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:29:21 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_all_sort_time(t_data *data)
{
	t_lst	*tmp;
	int		move_in_pile_b;

	tmp = data->pile_b;
	while (tmp)
	{
		move_in_pile_b = tmp->indice;
		if (tmp->indice > ft_count_pile(data->pile_b) / 2)
			move_in_pile_b = (ft_count_pile(data->pile_b) - tmp->indice);
		if (tmp->sort_indice == 0)
			tmp->to_sort = 1 + move_in_pile_b;
		else if (tmp->sort_indice <= ft_count_pile(data->pile_a) / 2)
			tmp->to_sort = 1 + tmp->sort_indice - 1 + move_in_pile_b;
		else if (tmp->sort_indice == ft_count_pile(data->pile_a))
			tmp->to_sort = 1 + move_in_pile_b;
		else
		{
			tmp->to_sort = 1 + (ft_count_pile(data->pile_a)
					- tmp->sort_indice) + move_in_pile_b;
		}
		tmp = tmp->next;
	}
}

void	update_all_sort_indice(t_data *data)
{
	t_lst	*tmp;

	tmp = data->pile_b;
	while (tmp)
	{
		tmp->sort_indice = indice_sort(data, tmp->value);
		tmp = tmp->next;
	}
}
