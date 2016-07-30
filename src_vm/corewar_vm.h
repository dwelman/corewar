/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:35:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/30 11:46:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

#include "../libft/libft.h"

# define ARG_DUMP(X) ft_strcmp("-dump", argv[X]) == 0
# define BOOL char

enum
{
	FALSE,
	TRUE
};

enum
{
	ER_ARGF = 1,
	ER_FILE,
	ER_NOTNUM,
	ER_DUPNUM,
	ER_MALLOC
};

/*
** t_cor stores information of a player (.cor)
*/

typedef struct	s_cor
{
	char	*file;
	int		p_num;
}				t_cor;

/*
** Environment
*/

typedef struct	s_env
{
	int		p_count;
	BOOL	dump;
	int		dump_cycles;
	t_cor	*players;
}				t_env;


/*
** Input && error checks
*/

void	check_args(int argc, char **argv, t_env *env);

void	arg_err(int err, char *arg);

void	check_player_numbers(int argc, char **argv);

int		check_int(char *arg);

int		is_numeric(char *arg);

void	get_input(int argc, char **argv, t_env *env);

void	new_cor(char *cor_file, int player_num, t_cor *cor);

#endif

