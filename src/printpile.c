/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:59 by besalort          #+#    #+#             */
/*   Updated: 2023/07/10 17:27:22 by besalort         ###   ########.fr       */
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
	ft_printf("\n");
}
