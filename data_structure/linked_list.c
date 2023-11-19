#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void insert_front(node_t** phead, int n) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
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
        node_t* next = p->next; // 수정된 부분
        free(p);
        p = next;
    }
}

void print_node(const node_t* head) {
    const node_t* p; // 'const'로 변경

    p = head;
    while (p != NULL) {
        printf("%d ", p->val); // 출력 후 공백 추가
        p = p->next;
    }
    printf("\n"); // 모든 노드 출력 후 줄바꿈
}

int main(void) {
    node_t* head = NULL;

    insert_front(&head, 1);
    print_node(head);
    destroy(head);
    head = NULL;
    
    return 0;
}
