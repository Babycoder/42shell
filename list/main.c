#include <stdio.h>
#include <stdlib.h>


typedef struct s_node 
{
    int data;
    struct s_node *next;
}               t_node;



void push(t_node **head, int data)
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
        printf(" %d ", node->data);
        node = node->next;
    }
}


void    deletenode(t_node **head, int pos)
{
    int i = 0;
    t_node *tmp;
    t_node *next;
    
    if(*head == NULL)
        return;
    tmp = *head;
    
    // If head needs to be removed
    if(pos == 0)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    

    //Find Previous node of the node to be deleted 
    while (i < pos - 1 && tmp != NULL)
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
    
  



int     main(int argc, char **argv)
{

    printf("%d\n", ft_strncmp("ZYMEN", "AMGH", 3));

    /*t_node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printf("Linked List Created:\n\n");
    printlist(head);
    printf("\n\nLinked List After deleton at Position 0:\n\n");
    deletenode(&head, 0);
    deletenode(&head, 1);
    deletenode(&head, 2);
    printlist(head);*/

}