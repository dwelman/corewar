#include <corewar_vm.h>

int	*no_n_byte(void)
{
	int	*ret;
	int	i;
	
	ret = malloc(sizeof(int) * 4);
	i = 0;
	ret[i] = T_DIR;
	while (++i < 4)
	{
		ret[i] = NO_TYPE;
	}
	return (ret);
}
