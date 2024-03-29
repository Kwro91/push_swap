/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:24:09 by besalort          #+#    #+#             */
/*   Updated: 2023/10/06 16:45:26 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load(t_data *data, int ac, char **av)
{
	t_lst	*pile_a;
	t_lst	*pile_b;

	pile_a = create_elements(ac - 1, &av[1], 0);
	pile_b = NULL;
	data->pile_a = pile_a;
	data->pile_b = pile_b;
}
