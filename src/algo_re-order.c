/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_re-order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:45:22 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:35:54 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reorder_pile(t_data *data)
{
	int	chose;

	chose = which_lowest(data->pile_a);
	if (ft_count_pile(data->pile_a) / 2 > chose)
	{
		while (which_lowest(data->pile_a) != 0)
			reverse_rotate(data, 'a');
	}
	else
	{
		while (which_lowest(data->pile_a) != 0)
			rotate(data, 'a');
	}
}
