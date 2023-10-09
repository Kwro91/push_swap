/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:21:25 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 15:43:49 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double_in_lst(t_data *data)
{
	t_lst	*element;
	t_lst	*check;

	check = data->pile_a;
	while (check->next)
	{
		element = check->next;
		while (element)
		{
			if (check->value == element->value)
			{
				return (1);
			}
			element = element->next;
		}
		check = check->next;
	}
	return (0);
}

int	is_sort(t_data *data)
{
	t_lst	*element;
	t_lst	*check;

	check = data->pile_a;
	while (check->next)
	{
		element = check->next;
		while (element)
		{
			if (check->value >= element->value)
			{
				return (0);
			}
			element = element->next;
		}
		check = check->next;
	}
	return (1);
}

int	ft_is_only_number(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_only_int(char **av)
{
	int			i;
	long int	value;

	i = 1;
	while (av[i])
	{
		value = ft_atoi_long(av[i]);
		if (value > 2147483647 || value < -2147483648)
			return (-1);
		i++;
	}
	return (1);
}

int	verif(t_data *data)
{
	if (is_sort(data) == 1)
		return (-1);
	if (is_double_in_lst(data) == 1)
		return (-1);
	return (0);
}
