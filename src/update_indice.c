/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_indice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:21:27 by besalort          #+#    #+#             */
/*   Updated: 2023/07/07 16:28:15 by besalort         ###   ########.fr       */
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
		tmp.indice = i;
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
		tmp.indice = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_update_indice(t_data *data)
{
	ft_update_indice_a(data);
	ft_update_indice_b(data);
}