#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "./parse/functions_headerfile.h"

typedef struct s_node 
{
    char *data;
    struct s_node *next;
}               t_node;

int     ft_echo(char **cmd);
int     ft_pwd(t_format *ptr);
int     ft_cd(t_format *ptr);
int     ft_exit(char **cmd);
int     ft_env(t_node *head, char **cmd);
int     ft_export(t_node **head, char **cmd);
int     ft_unset(t_node **head, char **cmd);



void	ft_free_split(char **split);
int     ft_strcmp(char *s1, char *s2);
int			ft_isabsolute(char *s);
int			ft_ispath(char *s);
int     ft_path(char  **cmd, t_node *head);
void	print2d(char **s);
char	*ft_join(char const *s1, char const *s2);
void    push_node(t_node **head, char *newdata);
void    print_list(t_node *node);
t_node     *get_envp(char **env);
char     *check_command(char **split, char *cmd);
char    *get_path(t_node *node);
char	*ft_equal(char	*s1);
void    export_error(char *s, int fd);
int     valid_id(char *s);
void    print_export(t_node *node, int fd);
void    print_cases(char *s, int ret);
int     check_value(char *s);
void    deletenode(t_node **head, char *pos);
int     arglen(char *s);
int     get_arglen(char *s1, char *s2);
int     check_overwrite(t_node *node, char *s);
int     isequal(char *s);
void    deletelist(t_node **head_ref);
t_node  *copyList(t_node* head);
t_node  *sort_list(t_node *start);
void    swap(t_node *a, t_node *b);
int      ft_execution(t_format *ptr, char **env);

#endif