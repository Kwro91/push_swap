/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_use_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:04:42 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:32:26 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_rotate(t_data *data, t_lst *tmp, int indice)
{
	int	count;

	count = 0;
	if (tmp->sort_indice < ft_count_pile(data->pile_a) / 2)
	{
		while (count < indice && count < tmp->sort_indice)
		{
			rotate(data, 'r');
			count++;
		}
	}
	return (count);
}

int	r_reverse(t_data *data, t_lst *tmp)
{
	int	count;

	count = 0;
	if (tmp->sort_indice >= ft_count_pile(data->pile_a) / 2)
	{
		while (count < (ft_count_pile(data->pile_a)
				- tmp->sort_indice) && tmp->indice > 0)
		{
			reverse_rotate(data, 'r');
			count++;
		}
	}
	count = -(count);
	return (count);
}

int	using_r(t_data *data, int indice)
{
	t_lst	*tmp;
	int		count;

	count = 0;
	tmp = data->pile_b;
	while (tmp && tmp->indice != indice)
		tmp = tmp->next;
	if (tmp->to_sort == 0 || indice == 0)
		return (count);
	if (indice < ft_count_pile(data->pile_b) / 2)
	{
		count = r_rotate(data, tmp, indice);
	}
	else
	{
		count = r_reverse(data, tmp);
	}
	return (count);
}
