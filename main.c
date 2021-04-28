
#include "./minishell.h"


void    shlvl(t_node **head)
{
    int lvl;
    char **s;
    char *shlvl;
    t_node *tmp;

    lvl = 1;
    tmp = *head;
    while(tmp != NULL)
    {
        s = ft_split(tmp->data, '=');
        if (ft_strcmp(s[0], "SHLVL") == 0)
        {
            lvl += ft_atoi(s[1]);
            free(s[1]);
            s[1] = ft_itoa(lvl);
            shlvl = ft_strjoin("SHLVL=", s[1]);
            deletenode(head, "SHLVL");
            push_node(head, shlvl);
            free(shlvl);
            ft_free_split(s);
            return ;
        }
        else
            ft_free_split(s);
        tmp = tmp->next;
        if (tmp == NULL)
            push_node(head, "SHLVL=1");
    }
}

int     main(int ac, char **av, char **env)
{
    char *input;
    t_format    *ptr;
    t_node  *head;

    //env = shlvl(env);
    head = get_envp(env);
    shlvl(&head);
    while (1)
    {
        ptr = malloc(sizeof(t_format));
        if (parse(input, ptr) == NULL)//formatted data is now stored in ptr
            continue ;
        //printf("hello\n");
        ft_execution(ptr, &head);
        //print_da(ptr);//if you want to print the output
        ft_freedom(ptr);//free func
    }
    return(0);
}






































































/*#include "minishell.h"
#include "libft/libft.h"



int     main(int argc, char **argv, char **env)
{
    int ret = 0;
    t_node  *head;

    head = get_envp(env);
    //print_list(head);

    char *cmd[] = {"ls", NULL};
    char*test[] = {"export", "aymen=ghazali", "ghazali=aymen", "city", NULL};

    if (ft_strcmp(cmd[0], "echo") == 0)
        ft_echo(cmd);
    else if (ft_strcmp(cmd[0], "pwd") == 0)
        ft_pwd(cmd);
    else if (ft_strcmp(cmd[0], "cd") == 0)
    {
        if(ft_cd(cmd) == 0)
            printf("No such file or directory\n");
    }
    else if (ft_strcmp(cmd[0], "exit") == 0)
        ft_exit(cmd);
    else if (ft_strcmp(cmd[0], "env") == 0)
    {
        //ft_export(&head, test);
        ft_env(head, cmd);
    }
    else if (ft_strcmp(cmd[0], "export") == 0)
        ft_export(&head, cmd);
    else if (ft_strcmp(cmd[0], "unset") == 0)
    {   
        //ft_export(&head, test);
        ft_unset(&head,cmd);
    }
   else 
        ft_path(cmd, head);
    //else
    //printf("command not found\n");
    //ft_env(head);
    //printf("\n======================================================\n");
    //print_list(head);

    return(0);
}*/