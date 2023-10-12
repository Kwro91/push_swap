/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:23:44 by besalort          #+#    #+#             */
/*   Updated: 2023/10/12 21:14:34 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_lst	*create_elements_bonus(int size, char **elements, int indice)
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
		element->next = create_elements_bonus(size - 1,
				&elements[1], indice + 1);
		if (element->next == NULL && (size -1) > 0)
			return (free(element), NULL);
	}
	return (element);
}

void	checker_ps(int ac, char **av)
{
	t_data	data;
	int		is_sort;

	data = (t_data){};
	is_sort = 0;
	if (ft_is_only_number(av) == -1 || ft_is_only_int(av) == -1)
		error_checker(&data);
	load_bonus(&data, ac, av);
	if (verif(&data) == -1)
		error_checker(&data);
	read_all(&data);
	is_sort = do_cmds(&data);
	if (is_sort == 1)
		ft_printf("OK\n");
	else if (is_sort == 0)
		ft_printf("KO\n");
	else
		ft_printf("Error\n");
	ft_free_ps(&data);
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac >= 3)
		checker_ps(ac, av);
}
