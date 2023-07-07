/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:36 by besalort          #+#    #+#             */
/*   Updated: 2023/07/07 18:44:39 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3case(t_data *data)
{
	(void)data;
}

void	algo(t_data *data)
{
	printf("Il y a %i elements dans la pile a\n", ft_count_pile(data->pile_a));
	printf("Il y a %i elements dans la pile b\n", ft_count_pile(data->pile_b));
	
	// reverse_rotate(data, 'a');
	// rotate(data, 'a');
	// push(data, 'b');
	// swap(data, 'a');
}
