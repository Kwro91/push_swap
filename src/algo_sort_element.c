/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:20:06 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 17:15:08 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rotate(t_data *data, int indice)
{
	int	count;

	count = 0;
	if (indice == 0 && is_highest(data->pile_a) == 1)
		return ;
	while (count < indice)
	{
		rotate(data, 'a');
		count++;
	}
}

void	sort_reverse(t_data *data, int indice)
{
	int	count;

	count = 0;
	while (count < indice)
	{
		reverse_rotate(data, 'a');
		count++;
	}
}

void	sort_all(t_data *data)
{
	int		count;
	t_lst	*tmp;

	update_all_sort_indice(data);
	tmp = data->pile_b;
	count = tmp->sort_indice;
	if (count != 0 && tmp->sort_indice > (ft_count_pile(data->pile_a) / 2))
	{
		count = ft_count_pile(data->pile_a) - tmp->sort_indice;
		sort_reverse(data, count);
	}
	else if (count != 0)
		sort_rotate(data, count);
	push(data, 'a');
}

void	prepare_to_sort(t_data *data, int indice, int r_done)
{
	t_lst	*tmp;

	indice = indice - r_done;
	tmp = data->pile_b;
	while (tmp && tmp->indice != indice)
		tmp = tmp->next;
	if (tmp)
		tmp->sort_indice = tmp->sort_indice - r_done;
	if (indice > ft_count_pile(data->pile_b) / 2)
	{
		while (tmp && tmp->indice != 0)
			reverse_rotate(data, 'b');
	}
	else
		while (tmp && tmp->indice != 0)
			rotate(data, 'b');
}
