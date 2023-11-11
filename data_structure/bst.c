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
node_t* search(node_t* root, int value){
    if (root == NULL || root->value == value) {
        
        return root;
    }
        
    if (value < root->value){
        
        return search(root->left, value);
    }else {

        return search(root->right, value);
    }
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

        
    /*삽입 및 생성*/
    int arr[10] = {20, 72, 1, 18, 87, 36, 9, 96, 15, 56}; 
    for(int i = 0; i < 10; ++i)
    {
        insert(&root, arr[i]);
    }

    /*출력*/
    printf("트리 중위 순회 결과 : ");
    traversal(root);
    printf("\n");

    /*검색 테스트*/
    node_t* found = search(root, 9);
    if (found != NULL) {
        printf("값 9을 찾았습니다\n");
    } else {
        printf("값 9을 찾지 못했습니다.\n");
    }

    found = search(root, 100);
    if (found != NULL) {
        printf("값 100을 찾았습니다\n");
    } else {
        printf("값 100을 찾지 못했습니다.\n");
    }



    /*트리 소멸*/
    free_tree(root);
    return 0;
}