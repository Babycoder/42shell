#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int	ft_strcmp(char *s1, char *s2);
int     ft_echo(char **cmd);


#endif