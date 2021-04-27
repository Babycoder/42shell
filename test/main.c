#include <stdio.h>
#include <string.h>
#include <unistd.h>


int     main(int ac, char **av, char **env)
{
    char *s[]= {"echo", NULL};
    //printf("%s\n", s[0]);
    execve("/bin/ls", s, env);
    return(0);
}

















/* 
int    get_option(t_red *red)
{
    int option;
    option = 0;
    if (red->type && red->type[0] == '>' && red->type[1] != '>')
        option = O_CREAT | O_WRONLY | O_TRUNC;
    else if (red->type && red->type[0] == '<')
        option = O_RDONLY;
    else if (red->type && !ft_strcmp(red->type, ">>"))
        option = O_CREAT | O_WRONLY | O_APPEND;
    return option;
}
void    setup_redirection(t_cmd *cmd)
{
    t_red *red;
    red = cmd->red;
    cmd->fdout = 0;
    cmd->fdin = 0;
    while (red)
    {
        if (red && red->type[0] == '<')
            cmd->fdin = open(red->file, get_option(red), S_IRWXU);
        if (red && red->type[0] == '>')
            cmd->fdout = open(red->file, get_option(red), S_IRWXU);
        if ((cmd->fdin < 0 || cmd->fdout< 0))
        {
            g_sh.error = 1;
            ft_putstr_fd("minishell: ", 2);
            ft_putstr_fd(red->file, 2);
            ft_putstr_fd(": ", 2);
            ft_putendl_fd(strerror(errno), 2);
            g_sh.status = 1;
        }
        if (red->next && cmd->fdout && red->next->type[0] != '<')
            close(cmd->fdout);
        if (red->next && cmd->fdin && red->next->type[0] == '<')
            close(cmd->fdin);
        red = red->next;
    }
    if (cmd->fdout)
        dup2(cmd->fdout, 1);
    if (cmd->fdin)
        dup2(cmd->fdin, 0);
}
5:26
if (cmd)
        {
            pid = fork();
            if (pid == 0) {
                if (cmds.red)
                {
                    if (!(ft_strcmp(cmds.red[0], ">")))
                    {
                        file = open(cmds.file[0], O_WRONLY | O_CREAT | O_TRUNC, 0777);
                        dup2(file, STDOUT_FILENO);
                    }
                    else if (!(ft_strcmp(cmds.red[0], ">>")))
                    {
                        file = open(cmds.file[0], O_WRONLY | O_CREAT | O_APPEND, 0777);
                        dup2(file, STDOUT_FILENO);
                    }
                    else if (!(ft_strcmp(cmds.red[0], "<")))
                    {
                        file = open(cmds.file[0], O_RDONLY, 0777);
                        dup2(file, STDIN_FILENO);
                    }
                }
                execve(cmd, cmds.args, g_minishell.envp);
            }
            else
            {
                wait(NULL);
            }
*/