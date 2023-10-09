/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:41:03 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:41:06 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_checker(t_data *data)
{
	ft_printf("Error\n");
	ft_free_ps(data);
	exit(0);
}
