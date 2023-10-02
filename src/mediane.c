/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:44:01 by besalort          #+#    #+#             */
/*   Updated: 2023/09/26 12:34:59 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_tab(t_data *data)
{
	int		i;
	t_lst	*tmp;


	i = 0;
	tmp = data->pile_a;
	data->tab = malloc(sizeof(int) * data->nb_elem);
	while (tmp)
	{
		data->tab[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
}

void	sort_tab(t_data *data, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = size-1;
	while (i >= 1)
	{
		j = 0;
		while (j < i)
		{
			if (data->tab[j] > data->tab[i])
			{
				tmp = data->tab[i];
				data->tab[i] = data->tab[j];
				data->tab[j] = tmp;
			}
			j++;
		}
		i--;
	}
}

void	mediane(t_data *data, int nb)
{
	int		i;

	i = 0;
	create_tab(data);
	sort_tab(data, nb);
	if (nb %2 != 0)
		nb = nb/2 +1;
	else
		nb = nb/2;
	while (nb > 0)
	{
		nb--;
		i++;
	}
	data->mediane = data->tab[i];
}
