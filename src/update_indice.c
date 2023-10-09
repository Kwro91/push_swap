/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_indice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:21:27 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 11:29:09 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_indice_a(t_data *data)
{
	t_lst	*tmp;
	int		i;

	tmp = data->pile_a;
	i = 0;
	while (tmp)
	{
		tmp->indice = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_update_indice_b(t_data *data)
{
	t_lst	*tmp;
	int		i;

	tmp = data->pile_b;
	i = 0;
	while (tmp)
	{
		tmp->indice = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_update_high_a(t_data *data)
{
	t_lst	*tmp;
	int		count;
	int		indice;

	tmp = data->pile_a;
	count = 0;
	indice = which_highest(data->pile_a);
	while (tmp && count < indice)
	{
		tmp = tmp->next;
		count++;
	}
	data->low_a = tmp->value;
}

void	ft_update_low_a(t_data *data)
{
	t_lst	*tmp;
	int		count;
	int		indice;

	tmp = data->pile_a;
	count = 0;
	indice = which_lowest(data->pile_a);
	while (tmp && count < indice)
	{
		tmp = tmp->next;
		count++;
	}
	data->low_a = tmp->value;
}

void	ft_update_indice(t_data *data)
{
	ft_update_indice_a(data);
	ft_update_indice_b(data);
	ft_update_high_a(data);
	ft_update_low_a(data);
}
