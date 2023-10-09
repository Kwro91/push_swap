/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:44:19 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 11:33:24 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_pile(t_lst *pile)
{
	if (pile->next)
		ft_free_pile(pile->next);
	free(pile);
}

void	ft_free_ps(t_data *data)
{
	free(data->tab);
	if (data->pile_a)
		ft_free_pile(data->pile_a);
	if (data->pile_b)
		ft_free_pile(data->pile_b);
}
