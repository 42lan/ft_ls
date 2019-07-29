#include "ft_ls.h"

extern t_argp		g_argp[];

void	display(t_dir *current_dir)
{
	if (g_argp[1].active == 1) // If -l is specified
		display_long(current_dir);
	else
		display_default(current_dir);
}
