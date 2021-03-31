#include <stdio.h>
#include <stdlib.h>


typedef struct s_node 
{
    char *data;
    struct s_node *next;
}               t_node;


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((s1[i] == '\0' && s2[i] == '\0') || n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int     ft_strlen(char *s)
{
    int i =0;

    while(s[i])
        i++;
    return(i);
}

void push(t_node **head, char *data)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data  = data;
    new_node->next = *head;
    *head=new_node;
}

void printlist(t_node *node)
{
    while (node != NULL)
    {
        printf(" %s ", node->data);
        node = node->next;
    }
}


void    deletenode(t_node **head, char *pos)
{
    int i = 0;
    t_node *tmp;
    t_node *next;
    
    if(*head == NULL)
        return;
    tmp = *head;
    
    // If head needs to be removed
    if(ft_strncmp(tmp->data, pos, ft_strlen(tmp->data)) == 0)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    

    //Find Previous node of the node to be deleted 
    while (ft_strncmp(tmp->next->data, pos, ft_strlen(tmp->next->data)) && tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }

    //If position is more than number of nodes
    if (tmp == NULL || tmp->next == NULL)
        return;
    
    // Node tmp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    
    next = tmp->next->next;
    
    // Unlink the node from linked list

    free(tmp->next); // fre memory
    tmp->next = next;

}
    
int     check_delete(t_node *node, char *s)
{
       int len;
    int len1 = 0;//ft_strlen(node->data);
    int len2 = ft_strlen(s);
    while(node->data[len1] && node->data[len1] != '=')
        len1++;
    if (len1 > len2)
        len = len1;
    else
        len = len2;

    while (node != NULL)
    {
        if  (ft_strncmp(node->data, s, len) == 0)
            return(1);
        node = node->next;
    }
    return(0); 
}

int     arglen(char *s)
{
    int i;
    i = 0;

    while(s[i] && s[i] != '=')
        i++;
    return(i);
}


int     main(int argc, char **argv)
{
    //char s[]= "aymen=ghazali";
    //printf("%d\n", ft_strncmp("AYMEN", "AYMEN", 3));

   /* t_node *head = NULL;

    char s[]= "facebook";
    push(&head, "facebook");
    push(&head, "instagram");
    push(&head, "twitter");
    push(&head, "tiktok");
    printf("Linked List Created:\n\n");
    printlist(head);
    printf("\n\nLinked List After delete \"%s\":\n\n", s);
   // if (check_delete(head, s))
    deletenode(&head, s);
    printlist(head);*/
    printf("%d\n", arglen("s=dfsdfasg"));
    return(0);

}