#include "rbtree.h"
#include <stdlib.h>

rbtree *new_rbtree(void)
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  if (p == NULL)
  {
    return NULL; // 메모리 할당에 실패하면 NULL 반환
  }

#ifdef SENTINEL
  // 센티넬 노드를 사용하는 경우
  p->nil = (node_t *)calloc(1, sizeof(node_t));
  if (p->nil == NULL)
  {
    free(p); // 센티넬 노드 할당에 실패하면 할당한 메모리 해제
    return NULL;
  }
  p->nil->color = RBTREE_BLACK;
  p->nil->left = p->nil->right = p->nil->parent = p->nil;
  p->root = p->nil;
#else
  // 센티넬 노드를 사용하지 않는 경우
  p->root = NULL; // 루트 노드를 NULL로 초기화
#endif

  return p;
}

void delete_node_recursive(rbtree *t, node_t *node)
{
  if (node != t->nil)
  {                                        // 센티넬 노드가 아닌지 확인
    delete_node_recursive(t, node->left);  // 왼쪽 자식 노드를 재귀적으로 삭제
    delete_node_recursive(t, node->right); // 오른쪽 자식 노드를 재귀적으로 삭제
    free(node);                            // 현재 노드 메모리 해제
  }
}

void delete_rbtree(rbtree *t)
{
  delete_node_recursive(t, t->root); // 루트 노드부터 재귀적으로 삭제 시작
#ifdef SENTINEL
  free(t->nil); // 센티넬 노드 메모리 해제
#endif
  free(t); // 레드-블랙 트리 구조체 메모리 해제
}

node_t *rbtree_insert(rbtree *t, const key_t key)
{
  // TODO: implement insert
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t)
{
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p)
{
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n)
{
  // TODO: implement to_array
  return 0;
}
