
#ifndef _PUSH_SWAP_H_
# define _PUSH_SWAP_H_

#include "./libft/libft.h"

typedef struct s_lst
{
	int 	value;
	int		indice;
	void	*next;
}	t_lst;

typedef struct s_data
{
	t_lst	*pile_a;
	t_lst	*pile_b;
}	t_data;

// PUSH_SWAP.C
t_lst	*create_elements(int size, char **elements, int indice);
void	push_swap(int ac, char **av);
// PUSH.C
t_lst	*push(t_lst *pile, t_lst *element);
// ROTATE.C
void	rotate(t_lst *pile);
//SWAP.C
void	swap(t_lst	*pile);
// LOAD.C
void	load(t_data *data, int ac, char **av);
// VERIF.C
int	is_double_in_lst(t_data *data);
int	is_sort(t_data *data);
int	verif(t_data *data);
// ALGO.C
void	algo(t_data *data);

////////// POUR LES TESTS UNIQUEMENT !!! PENSER A ENLEVER LE FICHIER PRINTPILE ///////
void	printpile(t_data *data);
#endif