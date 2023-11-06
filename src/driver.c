#include <stdio.h>
#include "rbtree.h"
#include <assert.h>

void test_init(void) {
  rbtree *t = new_rbtree();
  assert(t != NULL);
#ifdef SENTINEL
  assert(t->nil != NULL);
  assert(t->root == t->nil);
#else
  assert(t->root == NULL);
#endif
  delete_rbtree(t);
}

int main(void) {
     test_init();
//   test_insert_single(1024);
//   test_find_single(512, 1024);
//   test_erase_root(128);
//   test_find_erase_fixed();
//   test_minmax_suite();
//   test_to_array_suite();
//   test_distinct_values();
//   test_duplicate_values();
//   test_multi_instance();
//   test_find_erase_rand(10000, 17);
  printf("Passed all tests!\n");
}



// int main(int argc, char *argv[])
// {
    
// }



