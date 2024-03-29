/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:59 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 11:38:38 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printpile(t_data *data)
{
	t_lst	*tmp;
	t_lst	*tmpb;

	tmp = data->pile_a;
	ft_printf("Voici la pile A:\n");
	while (tmp)
	{
		ft_printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("Voici la pile B:\n");
	tmpb = data->pile_b;
	while (tmpb)
	{
		ft_printf("%i\n", tmpb->value);
		tmpb = tmpb->next;
	}
	ft_printf("%i coups pour trier\n", data->coups);
	if (is_pile_sort(data->pile_a) == 1)
		ft_printf("la pile A est triee\n");
	if (is_pile_sort(data->pile_b) == 1)
		ft_printf("la pile B est triee\n");
}
