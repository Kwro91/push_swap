/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:38 by besalort          #+#    #+#             */
/*   Updated: 2023/07/10 17:28:45 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*create_elements(int size, char **elements, int indice)
{
	t_lst	*element;

	element = NULL;
	if (size > 0)
	{
		element = malloc(sizeof(t_lst));
		if (!element)
			return (NULL);
		element->indice = indice;
		element->value = ft_atoi(elements[0]);
		element->next = create_elements(size - 1, &elements[1], indice + 1);
		if (element->next == NULL && (size -1) > 0)
			return (free(element), NULL);
	}
	return (element);
}

void	push_swap(int ac, char **av)
{
	t_data	data;

	data = (t_data){};
	if (ft_is_only_number(av) == -1) // + BESOINS DE VERIF QUE TOUT LES NOMBRES SONT BIEN COMPRIS DANS UN INT
	{
		ft_printf("Invalid values, please put only numbers\n");
		return ;
	}
	load(&data, ac, av);
	if (verif(&data) == -1)
	{
		ft_printf("Invalid values (sorted or double)\n");
		return ;
	}
	algo(&data);
	printpile(&data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
}

int	main(int ac, char **av)
{
	if (ac >= 3)
		push_swap(ac, av);
	else
		ft_printf("Error, wrong number of argument");
}
