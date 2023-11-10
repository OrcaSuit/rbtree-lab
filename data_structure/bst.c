#include<stdio.h>
#include<stdlib.h>

/* 각 노드는 데이터, 왼쪽 자식 노드에 대한 참조, 오른쪽 자식 노드에 대한 참조를 가짐*/
typedef struct {
    int value;
    node_t* left;
    node_t* right;
} node_t;

/*노드 초기화*/
node_t* create_node(int value){
    node_t* newNode = malloc(sizeof(node_t));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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
void search(){
    
}

/*삭제*/
void deletion(){
    
}

/*순회*/
void traversal(){

}

int main(void){
    node_t* root = NULL;
    
    insert(&root, 3);

    return 0;
}