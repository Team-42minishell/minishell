#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/param.h>
# include "../libft/libft.h"
# include "get_next_line.h"

void	builtin_pwd(void);

#endif
