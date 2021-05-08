/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:02:30 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/06 15:39:36 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int    ft_setpipes(t_format *ptr, t_node **head)
{
   
    t_format *tmp = ptr;


    int commands_len = 2;
	int **pipes_fd;
	int *forks;
	
	forks = malloc(commands_len * (sizeof(int*)));
	pipes_fd = malloc((commands_len - 1) * (sizeof(int*)));

	int j = 0;
	while (j < commands_len)
	{
		pipes_fd[j] = malloc(2 * sizeof(int));
		
		if (pipe(pipes_fd[j]) == -1)
		{
			return (1);
		}
		j++;
	}

	int i = 0;
    while(tmp->pipes != NULL)
    {
        // printf("%s\n", tmp->pipes->line);


		forks[i] = fork();
		if (forks[i] < 0)
		{
			return (2);
		}
		if (forks[i] == 0)
		{
			// Child process 
			if (i == 0) // first fork
			{
				dup2(pipes_fd[0][1], 1);
			}
			else if (i == (commands_len - 1)) // last fork
			{
				dup2(pipes_fd[i - 1][0], 0);
			}
			else
			{
				dup2(pipes_fd[i - 1][0], 0);
				dup2(pipes_fd[i][1], 1);
			}
			
			
			
			
			close(pipes_fd[0][0]);
			close(pipes_fd[0][1]);
			close(pipes_fd[1][0]);
			close(pipes_fd[1][1]);
			// close(pipes_fd[2][0]);
			// close(pipes_fd[2][1]);
			
            //exec

        //    execlp(tmp->pipes->command, tmp->pipes->command, tmp->pipes->arguments, NULL);
        
        	if (i == 0)
			{
				execlp("ls", "ls", NULL);
			}
			else if (i == 1)
			{
				execlp("grep", "grep", "p", NULL);
			}
			else if (i == 2)
			{
				execlp("grep", "grep", "par", NULL);
			}
			else if (i == 3)
			{
				execlp("grep", "grep", "main2.k", NULL);
			}


			
			exit(0);
		}
        tmp->pipes = tmp->pipes->next;

		i++;
	}
	


	
	close(pipes_fd[0][0]);
	close(pipes_fd[0][1]);
	close(pipes_fd[1][0]);
	close(pipes_fd[1][1]);
	// close(pipes_fd[2][0]);
	// close(pipes_fd[2][1]);
		
	waitpid(forks[0], NULL, 0);
	waitpid(forks[1], NULL, 0);
	waitpid(forks[2], NULL, 0);
	// waitpid(forks[3], NULL, 0);













/*

	int commands_len = 4;
	int **pipes_fd;
	int *forks;
	
	forks = malloc(commands_len * (sizeof(int*)));
	pipes_fd = malloc((commands_len - 1) * (sizeof(int*)));

	int j = 0;
	while (j < commands_len)
	{
		pipes_fd[j] = malloc(2 * sizeof(int));
		
		if (pipe(pipes_fd[j]) == -1)
		{
			return (1);
		}
		j++;
	}

	int i = 0;
	while (i < commands_len)
	{
		forks[i] = fork();
		if (forks[i] < 0)
		{
			return (2);
		}
		if (forks[i] == 0)
		{
			// Child process 
			if (i == 0) // first fork
			{
				dup2(pipes_fd[0][1], 1);
			}
			else if (i == (commands_len - 1)) // last fork
			{
				dup2(pipes_fd[i - 1][0], 0);
			}
			else
			{
				dup2(pipes_fd[i - 1][0], 0);
				dup2(pipes_fd[i][1], 1);
			}
			
			
			
			
			close(pipes_fd[0][0]);
			close(pipes_fd[0][1]);
			close(pipes_fd[1][0]);
			close(pipes_fd[1][1]);
			close(pipes_fd[2][0]);
			close(pipes_fd[2][1]);
			
			
			if (i == 0)
			{
				execlp("ls", "ls", NULL);
			}
			else if (i == 1)
			{
				execlp("grep", "grep", "main", NULL);
			}
			else if (i == 2)
			{
				execlp("grep", "grep", "main2", NULL);
			}
			else if (i == 3)
			{
				execlp("grep", "grep", "main2.k", NULL);
			}

			
			exit(0);
		}
		i++;
	}
	


	
	close(pipes_fd[0][0]);
	close(pipes_fd[0][1]);
	close(pipes_fd[1][0]);
	close(pipes_fd[1][1]);
	close(pipes_fd[2][0]);
	close(pipes_fd[2][1]);
		
	waitpid(forks[0], NULL, 0);
	waitpid(forks[1], NULL, 0);
	waitpid(forks[2], NULL, 0);
	waitpid(forks[3], NULL, 0);

    */
   return (0);
}