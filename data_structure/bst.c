#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 각 노드는 데이터, 왼쪽 자식 노드에 대한 참조, 오른쪽 자식 노드에 대한 참조를 가짐*/
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node_t;

/*생성자*/
node_t* create_node(int value){
    node_t* newNode = malloc(sizeof(node_t));

    if(newNode == NULL) {
        fprintf(stderr, "메모리 할당 실패.");
        return NULL;
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*소멸자*/
void free_tree(node_t* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

/*삽입, 루트노드의 존재를 확인 후 현재 노드보다 작으면 왼쪽, 크면 오른쪽에 노드를 생성해 삽입.*/
void insert(node_t** root, int value){  
    if (*root == NULL) {
        *root = create_node(value);
        return;
    }

    if (value < (*root)->value) { 
        insert(&((*root)->left), value); 
    } else {
        insert(&((*root)->right), value);
    }
}

/*검색*/
void search(node_t *root, int value){

}

/*삭제*/
void deletion(){
    
}

/*순회*/
void traversal(node_t* root){
    if (root != NULL) {
        traversal(root->left);
        printf(" %d ", root->value);
        traversal(root->right);
    }
}

int main(void){
    node_t* root = NULL;
    
    srand(time(NULL)); 
    for(int i = 0; i < 8; i++){
        int randomValue = (rand() % 11) * 4;
        insert(&root, randomValue);
        printf(" %d ", randomValue);
    }
    printf("\n");

    printf("트리 중위 순회 결과 : ");
    traversal(root);
    printf("\n");

    /*소멸*/
    free_tree(root);
    return 0;
}