/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:20:14 by besalort          #+#    #+#             */
/*   Updated: 2023/10/06 18:25:30 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

void    ft_free_pile(t_lst *pile)
{
    if (pile->next)
        ft_free_pile(pile->next);
    free(pile);
}

void    ft_free_ps(t_data *data)
{
    if (data->pile_a)
        ft_free_pile(data->pile_a);
    if (data->pile_b)
    ft_free_pile(data->pile_b);
}