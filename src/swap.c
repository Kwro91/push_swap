/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:28 by besalort          #+#    #+#             */
/*   Updated: 2023/05/03 18:46:09 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst	*pile)
{
	int	value;
	t_lst	*second;

	value = pile->value;
	second = pile->next;
	pile->value = second->value;
	second->value = value;
}

// REVOIR CAR PLUSIEURS PROBLEMES (J'ai inverse les piles a l'interieur visiblement (envoie du a vers le b) mais le resultat est inverse lorsque je print)
// AUTRE PROBLEME JE PUSH A LA FIN AU LIEU DU DEBUT DE LA PILE (PTN T'ES CON LOL)