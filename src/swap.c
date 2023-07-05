/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:28 by besalort          #+#    #+#             */
/*   Updated: 2023/07/05 17:23:36 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	int	value;
	t_lst	*second;

	value = data->pile_a->value;
	second = data->pile_a->next;
	data->pile_a->value = second->value;
	second->value = value;
}

void	swap_b(t_data *data)
{
	int	value;
	t_lst	*second;

	value = data->pile_b->value;
	second = data->pile_b->next;
	data->pile_b->value = second->value;
	second->value = value;
}

void	swap(t_data	*data, char p)
{
	if (p == 'a' && (ft_count_pile(data->pile_a) > 1))
		swap_a(data);
	else if (p == 'b' && (ft_count_pile(data->pile_b) > 1))
		swap_b(data);
	else
		printf("Impossible de swap\n");
}
