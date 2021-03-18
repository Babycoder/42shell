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
int     ft_pwd(char **cmd);
int     ft_cd(char **cmd);
int     ft_exit(char **cmd);


#endif