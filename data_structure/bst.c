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
void free_tree(node_t* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

/*삽입, 루트노드의 존재를 확인 후 현재 노드보다 작으면 왼쪽, 크면 오른쪽에 노드를 생성해 삽입.*/
node_t* insert(node_t* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}


/*삭제*/
node_t* delete(node_t* root, int value) {
    if (root == NULL) {
        return root;
    }

    //삭제할 노드 찾기
    if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        //삭제할 노드를 찾은 경우

        // 경우 1 : 리프 노드인 경우
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
    }
}

/*검색*/
node_t* search(node_t* root, int value){
    if (root == NULL || root->value == value) {
        
        return root;
    }
        
    if (value < root->value){
        
        return search(root->left, value);
    }else 
    {

        return search(root->right, value);
    }
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

    /*트리 소멸*/
    free_tree(root);
    return 0;
}