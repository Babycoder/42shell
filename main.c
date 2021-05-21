/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:30:08 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/21 07:39:05 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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


/*void handler(int sig)
{
                                                                                                                                                 if (g_global.forked == 0)
    {
         ft_putendl_fd("\b\b  \b\b", 1);
         write(1,"minishell~$ ",13);
    }
    else
    {
        ft_putchar_fd('\n', 1);
    }
}*/


void    init_pwd(t_node **head)
{
    char *cwd;
    char *tmp;
    
    cwd = getcwd(NULL, 0);
    tmp = ft_strjoin("PWD=", cwd);
    if (check_overwrite(*head, "PWD"))
        deletenode(head, "PWD");
    push_node(head, tmp);
    if (check_overwrite(*head, "PWD"))
        deletenode(head, "OLDPWD");
    push_node(head, "OLDPWD");
    free(cwd);
    free(tmp);
}

int     main(int ac, char **av, char **env)
{
    char *input;
    t_format    *ptr;
    t_node  *head;

    head = get_envp(env);
    shlvl(&head);
    init_pwd(&head);
    //SIGNAL FUN
    //signal(SIGINT, handler);
    while (1)
    {
        ptr = malloc(sizeof(t_format));
        if (parse(input, ptr) == NULL)
            continue ;
        //print_da(ptr);
        ft_exec(ptr, &head);
    }
    return(0);
}
