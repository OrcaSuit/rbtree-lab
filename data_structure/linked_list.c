#include<stdio.h>

typedef struct node_t {
    int data;
    node_t* next;
}node_t;

void print_node(const node_t* head)
{
    node_t* p;

    p = head;
    while( p != NULL){
        printf("%d", p->data);
        p = p->next;
    }
}

void destroy(node_t* head)
{
    node_t* p = head;

    while(p != NULL){
        node_t* next = p->next;
        free(p);
        p = next;
    }
}

void insert(node_t** phead, int n)
{
    node_t* new_node;

    new_node = malloc(sizeof(node_t));
    new_node->data = n;

    new_node->next = *phead;
    *phead = new_node;
}

void remove(node_t** phead, int n)
{

}

int main(void) {
    node_t* head = NULL;
    insert(&head, 1);

    //print_node(head);

    //destroy(head);

    return 0;
}

