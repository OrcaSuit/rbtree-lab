#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h> // size_t와 같은 타입 정의를 포함하는 표준 헤더

// 레드-블랙 트리에서 사용할 색상 열거형 (RED 또는 BLACK)
typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

// 키 값을 위한 타입 정의
typedef int key_t;

// 레드-블랙 트리의 노드 구조체
typedef struct node_t {
  color_t color;         // 노드의 색상
  key_t key;             // 노드의 키 값
  struct node_t *parent; // 부모 노드를 가리키는 포인터
  struct node_t *left;   // 왼쪽 자식 노드를 가리키는 포인터
  struct node_t *right;  // 오른쪽 자식 노드를 가리키는 포인터
} node_t;

// 레드-블랙 트리 구조체
typedef struct {
  node_t *root; // 트리의 루트 노드를 가리키는 포인터
  node_t *nil;  // sentinel(보초) 노드를 위한 포인터. 모든 리프의 끝과 비어있는 자식을 대표
} rbtree;

// 레드-블랙 트리 생성 및 초기화 함수
rbtree *new_rbtree(void);

// 레드-블랙 트리 메모리 해제 함수
void delete_rbtree(rbtree *);

// 레드-블랙 트리에 새로운 키를 삽입하는 함수
node_t *rbtree_insert(rbtree *, const key_t);

// 레드-블랙 트리에서 주어진 키를 가진 노드를 찾는 함수
node_t *rbtree_find(const rbtree *, const key_t);

// 레드-블랙 트리에서 가장 작은 키를 가진 노드를 찾는 함수
node_t *rbtree_min(const rbtree *);

// 레드-블랙 트리에서 가장 큰 키를 가진 노드를 찾는 함수
node_t *rbtree_max(const rbtree *);

// 레드-블랙 트리에서 주어진 노드를 삭제하는 함수
int rbtree_erase(rbtree *, node_t *);

// 레드-블랙 트리의 내용을 배열로 변환하는 함수
int rbtree_to_array(const rbtree *, key_t *, const size_t);

#endif  // _RBTREE_H_
