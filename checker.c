/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:23:44 by besalort          #+#    #+#             */
/*   Updated: 2023/09/25 09:59:12 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/push_swap.h"

int main(int ac, char **av, char **env)
{
    t_lst   *cpile_a;
    t_lst   *cpile_b;

	pile_a = create_elements(ac - 1, &av[1], 1);
	pile_b = NULL;
    checker();
}