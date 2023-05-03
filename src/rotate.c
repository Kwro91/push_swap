/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:15 by besalort          #+#    #+#             */
/*   Updated: 2023/05/03 16:24:22 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst *pile)
{
	int		value;
	t_lst	*last;

	
	value = pile->value;
	last = pile;
	while(last->next)
		last = last->next;
	pile->value = last->value;
	last->value = value;
}