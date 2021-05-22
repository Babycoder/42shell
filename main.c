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


void    *full_ws_niet(t_toolbox     *box, t_format *ptr, t_node    **head)
{
	box->check = parse(box->str, box->formaptr);
	if (my_strcmp(box->check, "Unmatched_Quotes") == 0
	|| my_strcmp(box->check, "Back_slash_Error") == 0)
	{
        put_strings("\n>",NULL,NULL,NULL);
        return (NULL);
	}
	else if (my_strcmp(box->check, "Redirection_error") == 0
			|| my_strcmp(box->check, "Syntax_error") == 0)
	{
        put_strings("\n",box->check,"\nminishell~$ ",NULL);
		free(box->str);
		box->str = calloc(1,1);
		box->ptr->line = box->str;
	}
	else
	{
        write(1, "\n", 1);
		ft_exec(box->formaptr, head);
		box->ptr->next = malloc(sizeof(t_history));
		box->tmp = box->ptr;
		box->ptr = box->ptr->next;
		box->str = calloc(1,1);
		init_lst(box);
		box->ptr->previous = box->tmp;
        put_strings("minishell~$ ",NULL,NULL,NULL);
	}
    return ("done");
}

void handler(int sig)
{
    if (g_global.forked == 1)
    {
        put_strings("\nminishell~$ ",NULL,NULL,NULL);
        free(g_global.box->str);
        g_global.box->str = NULL;
        g_global.box->str = my_calloc(1);
    }
    else if (g_global.forked == 0) //cat
    {
        ft_putchar_fd('\n', 1);
    }
}


void    init_pwd(t_node **head)
{
    char *cwd;
    char *tmp;
    
    cwd = getcwd(NULL, 0);
    tmp = ft_strjoin("PWD=", cwd);
    if (check_overwrite(*head, "PWD"))
        deletenode(head, "PWD");
    push_node(head, tmp);
    if (check_overwrite(*head, "OLDPWD"))
        deletenode(head, "OLDPWD");
    push_node(head, "OLDPWD");
    free(cwd);
    free(tmp);
}

void    handler2(int sig)
{
	if (g_global.forked == 0)
    {
        ft_putendl_fd("Quit: 3", 2);
        g_global.forked = 1;
    }
}



int     main(int    argc, char      **argv, char        **env)
{
    char *input;
    t_format    *ptr;
    t_node  *head;

    head = get_envp(env);
    shlvl(&head);
    init_pwd(&head);
    g_global.forked = 1;
    signal(SIGQUIT, handler2);
    signal(SIGINT, handler);
    g_global.box = malloc(sizeof(t_toolbox));
    t_toolbox *box = g_global.box;
    if (box == NULL || init_all(box) == NULL)
        return (1);
    put_strings("minishell~$ ",NULL,NULL,NULL);
    while (1)
    {
		box->ascii = fetch_char(&box->old);
		if (box->ascii >= 32 && box->ascii <= 126)//all printable chars
            printable_key(box);
		else if (box->ascii == DELETE_KEY)//delete char
            delete_key(box);
		else if (box->ascii == ENTER_KEY)//enter
        {
	        tcsetattr(0, TCSANOW, &box->old);
            if (enter_key(box, ptr, &head) == NULL)
                continue ;
        }
		else if (box->ascii == UP_KEY)
            up_key(box);
		else if (box->ascii == DOWN_KEY)
            down_key(box);
		else if (box->ascii == CTRL_D)
            ctrl_d_key(box);
    }
    return (0);
}
