/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:38 by besalort          #+#    #+#             */
/*   Updated: 2023/10/12 21:12:27 by besalort         ###   ########.fr       */
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
		element->sort_indice = 0;
		element->to_sort = 0;
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
	if (ft_is_only_number(av) == -1 || ft_is_only_int(av) == -1)
	{
		ft_printf("Error\n");
		return ;
	}
	load(&data, ac, av);
	if (verif(&data) == -1)
		return ;
	algo(&data);
	ft_free_ps(&data);
}

int	main(int ac, char **av)
{
	if (ac >= 3)
		push_swap(ac, av);
}
