/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:59:25 by besalort          #+#    #+#             */
/*   Updated: 2023/10/08 17:49:16 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    load_bonus(t_data *data, int ac, char **av)
{
	data->pile_a = create_elements_bonus(ac - 1, &av[1], 0);
	data->pile_b = NULL;
    data->cmds = malloc(sizeof(char *));
    data->cmds = NULL;
}
