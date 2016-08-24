#include <corewar_vm.h>

void	aff(t_op_run *run, t_env *env)
{
//
	int		player;
	char	c;

	player = run->player;
	c = (char)(*(int *)P_CPU(player).registers[*(int *)run->arg[0] - 1] % 256);
	ft_putchar(c);
}
