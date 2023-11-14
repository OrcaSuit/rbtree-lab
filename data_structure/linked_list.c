#include<stdio.h>

typedef struct node_t {
    int data;
    node_t* next;
}node_t;

void print_node(const node_t* head)
{
    node_t* p;

    p = head;
    while( p != NULL ){
      printf("%d", p->data);
      p = p->next;
    }
    
}

void destroy(node_t* head)
{
    
}

void insert(node_t** phead, int n)
{

}

void remove(node_t** phead, int n)
{

}

int main(void) {
    node_t* head = NULL;

    //insert(&head, 1);

    //print_node(head);

    //destroy(head);

    return 0;
}

