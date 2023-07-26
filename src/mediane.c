/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:44:01 by besalort          #+#    #+#             */
/*   Updated: 2023/07/26 23:46:24 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_tab(t_data *data, int count)
{
	data->tab = malloc(sizeof(int) * count);
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = data->pile_a;
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

	i = 0;
	while (i < size)
	{
		j = i + i;
		while (j < size)
		{
			if (data->tab[j] < data->tab[i])
			{
				tmp = data->tab[i];
				data->tab[i] = data->tab[j];
				data->tab[j] = tmp;
			}
			j++;
		}
		printf("%i\n", data->tab[i]);
		i++;
	}
}

void	mediane(t_data *data, int nb) // il faut lui donner un tableau trie
{
	int		i;

	i = 0;
	create_tab(data, nb);
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
	printf("la medianne est de %i\n", data->mediane);
}