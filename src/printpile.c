/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:59 by besalort          #+#    #+#             */
/*   Updated: 2023/05/03 17:44:57 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printpile(t_data *data)
{
	ft_printf("Voici la pile A:\n");
	while (data->pile_a)
	{
		ft_printf("%i\n", data->pile_a->value);
		data->pile_a = data->pile_a->next;
	}
	ft_printf("Voici la pile B:\n");
	while (data->pile_b)
	{
		ft_printf("%i\n", data->pile_b->value);
		data->pile_b = data->pile_b->next;
	}
}
