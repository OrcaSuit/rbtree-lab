#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void insert_front(node_t** phead, int n) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t)); //노드에 메모리 할당
    if (!new_node) {
        // 메모리 할당 실패 처리
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new_node->val = n; 
    new_node->next = *phead; 
    *phead = new_node;
}

void destroy(node_t* head) {
    node_t* p = head;
    while (p != NULL) {
        node_t* next = p->next; 
        free(p);
        p = next;
    }
}

void print_node(const node_t* head) {
    const node_t* p; // 'const'로 변경

    p = head;
    while (p != NULL) {
        printf("%d ", p->val); 
        p = p->next;
    }
    printf("\n"); 
}

int main(void) {
    node_t* head = NULL;

    insert_front(&head, 1);
    insert_front(&head, 3);
    insert_front(&head, 5);
    print_node(head);
    destroy(head);
    head = NULL;
    
    return 0;
}
