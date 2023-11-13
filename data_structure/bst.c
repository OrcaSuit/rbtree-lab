#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 각 노드는 데이터, 왼쪽 자식 노드에 대한 참조, 오른쪽 자식 노드에 대한 참조를 가짐*/
typedef struct node_t {
    int value;
    struct node_t* left;
    struct node_t* right;
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
void free_tree(node_t* node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

/*삽입, 루트노드의 존재를 확인 후 현재 노드보다 작으면 왼쪽, 크면 오른쪽에 노드를 생성해 삽입.*/
node_t* insert(node_t* node, int value) {
    if (node == NULL) {
        return create_node(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

node_t* find_min(node_t* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/*삭제*/
node_t* delete(node_t* node, int value) {
    if (node == NULL) {
        return node;
    }

    //삭제할 노드 찾기
    if (value < node->value) {
        node->left = delete(node->left, value);
    } else if (value > node->value) {
        node->right = delete(node->right, value);
    } else {
        //삭제할 노드를 찾은 경우
        // 경우 1 : 리프 노드인 경우
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
        } 
        // 경우 2 : 자식이 하나인 경우
        else if (node->left == NULL){
            node_t* temp = node;
            node = node->right;
            free(temp);
        } else if (node->right == NULL){
            node_t* temp = node;
            node = node->left;
            free(temp);
        }
        // 경우 3 : 자식이 둘인 경우
        else { 
            //왼쪽 서브트리에서 가장 큰 값을 찾아 대체
            node_t* temp = find_min(node->right);
            node->value = temp->value;
            node->left = delete(node->left, temp->value);
        }
    }

    return node;
}



/*검색*/
node_t* search(node_t* node, int value){
    if (node == NULL || node->value == value) {
        
        return node;
    }
        
    if (value < node->value){
        
        return search(node->left, value);
    }else 
    {

        return search(node->right, value);
    }
}

/*순회*/
void traversal(node_t* node){
    if (node != NULL) {
        traversal(node->left);
        printf(" %d ", node->value);
        traversal(node->right);
    }
}

int main(void){
    node_t* root = NULL;
        
    /*삽입 및 생성*/
    int arr[10] = {20, 72, 1, 18, 87, 36, 9, 96, 15, 56};
    for(int i = 0; i < 10; ++i) {
        root = insert(root, arr[i]);
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

    /*삭제 테스트*/
    root = delete(root, 18);
    printf("트리 중위 순회 결과 : ");
    traversal(root);
    printf("\n");   

    /*삭제 후 검색 테스트*/
    found = search(root, 18);
    if(found != NULL) {
        printf("값 18을 찾았습니다.");
    } else {
        printf("값 18을 찾지 못했습니다.");
    }

    /*트리 소멸*/
    free_tree(root);
    return 0;
}