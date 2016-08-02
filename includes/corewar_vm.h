/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:35:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/02 09:59:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

#include "../libft/libft.h"
#include "op.h"

# define ARG_DUMP(X) ft_strcmp("-dump", argv[X]) == 0
# define BOOL char
# define CPU env->cpu
# define REG(X) CPU.registers[X]

/*
** Opcodes in hex
*/

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR	0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x10

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

typedef struct	s_instr
{
	int		op_code;
	int		cycl_left;
}				t_instr;

/*
** t_cor stores information of a player (.cor)
** lsc - amout of 'live' executions since last check
*/

typedef struct	s_cor
{
	char	*file;
	int		p_num;
	int		lsc;
}				t_cor;

typedef struct	s_cpu
{
	t_instr	*pc;
	void	**registers;
	int		carry;
}				t_cpu;

/*
** Environment
*/

typedef struct	s_env
{
	int		p_count;
	BOOL	dump;
	int		dump_cycles;
	t_cor	*players;
	t_cpu	cpu;
	void	*memory;
	int		cycle_to_die;
	int		checkups;
}				t_env;


/*
** Input && error checks
*/

void			check_args(int argc, char **argv, t_env *env);

void			arg_err(int err, char *arg);

void			check_player_numbers(int argc, char **argv);

int				check_int(char *arg);

int				is_numeric(char *arg);

void			get_input(int argc, char **argv, t_env *env);


/*
**	Initialize structs
*/

void			init_env(t_env *env);

void			init_cpu(t_cpu *cpu);

void			init_cor(char *cor_file, int player_num, t_cor *cor);


/*
** DOWN TO BUSINESS
*/

void			run_vm(t_env *env);

void			print_memory(const void *addr, size_t size);

#endif

