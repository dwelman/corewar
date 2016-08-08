/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:35:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/08 08:23:25 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

#include <libft.h>
#include <op.h>

# define ARG_DUMP(X) ft_strcmp("-dump", argv[X]) == 0
# define BOOL char
# define PLAYER(X) env->players[X]
# define P_CPU(X) env->players[X].cpu
# define P_REG(X, Y) env->players[X].cpu.registers[Y]
# define OP_COUNT 16
# define OP(X) env->op_tab[X]
# define COUNT_BUF 64
# define INST_SIZE(X) PLAYER(X).file_size - ( 4 + PROG_NAME_LENGTH + COMMENT_LENGTH) 

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

typedef struct		t_op    
{
   char			*name;
   char			nbr_args;
   char			type[MAX_ARGS_NUMBER];
   char			code;
   int			nbr_cycles;
}					t_op;

typedef struct	s_cpu
{
	t_op	*pc;
	void	**registers;
	int		carry;
}				t_cpu;

/*
** t_cor stores information of a player (.cor)
** lsc - amout of 'live' executions since last check
*/

typedef struct	s_cor
{
	char	*file;
	int		file_size;
	char	*name;
	char	*comment;
	char	*instructions;
	int		p_num;
	int		size;
	int		lsc;
	t_cpu	cpu;
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
	void	*memory;
	int		cycle_to_die;
	int		checkups;
	t_op	op_tab[OP_COUNT + 1];
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

void			fill_op_tab(t_env *env);

void			fill_1(t_env *env);

void			fill_2(t_env *env);

void			fill_3(t_env *env);

void			fill_4(t_env *env);

void			fill_5(t_env *env);

void			load_programs(t_env *env);

void			reverse_bytes(void *mem, size_t size);

/*
** Output functions
*/

void			print_all_ops(t_op op[OP_COUNT + 1]);

void			print_op(t_op op);

/*
**	Initialize structs
*/

void			init_env(t_env *env);

void			init_cpu(t_cpu *cpu);

void			init_cor(char *cor_file, int player_num, t_cor *cor);


/*
** DOWN TO BUSINESS
*/

void			load_into_vm(t_env *env);

void			run_vm(t_env *env);

void			print_memory(const void *addr, size_t size);

int				read_int(char *ptr);

#endif
