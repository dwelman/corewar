/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/09 12:27:34 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	clean_active_ops(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (CUR_OP(p).to_exec > 1)
			clear_op(&CUR_OP(p), env);
		p++;
	}
}

void	cleanup_env(t_env *env)
{
	int	r;
	int	p;

	r = 0;
	p = 0;
	ft_memdel((void**)&env->memory);
	while (p < env->p_count)
	{
		r = 0;
		while (r < REG_NUMBER)
		{
			ft_memdel(&P_REG(p, r));
			r++;
		}
		ft_memdel((void**)&P_CPU(p).registers);
		ft_memdel((void**)&PLAYER(p).name);
		ft_memdel((void**)&PLAYER(p).comment);
		ft_memdel((void**)&PLAYER(p).instructions);
		p++;
	}
	clean_active_ops(env);
	ft_memdel((void*)&env->players);
}
