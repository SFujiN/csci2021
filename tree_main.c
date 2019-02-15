#include <stdio.h>
#include <string.h>
#include "tree.h"

int main(int argc, char *argv[]){
  int echo = 0;
  if(argc > 1 && strcmp("-echo",argv[1])==0) {
    echo=1;
  }
  printf("BST Demo\n");
  printf("Commands:\n");
  printf("  print:          shows contents of the tree in reverse sorted order\n");
  printf("  clear:          eliminates all elements from the tree\n");
  printf("  quit:           exit the program\n");
  printf("  add <name>:     inserts the given string into the tree, duplicates ignored\n");
  printf("  find <name>:    prints FOUND if the name is in the tree, NOT FOUND otherwise\n");
  printf("  preorder:       prints contents of the tree in pre-order which is how it will be saved\n");
  printf("  save <file>:    writes the contents of the tree in pre-order to the given file\n");
  printf("  load <file>:    clears the current tree and loads the one in the given file\n");

  char cmd[128];
  bst_t tree;
  int success;
  bst_init(&tree);

  while(1){
    printf("BST> ");
    success = fscanf(stdin,"%s",cmd);
    if(success==EOF){
      printf("\n");
      break;
    }

    if(strcmp("quit", cmd)==0){
      if(echo){
        printf("quit\n");
      }
      bst_clear(&tree);
      break;
    }

    else if(strcmp("add", cmd)==0){
      fscanf(stdin,"%s",cmd);
      if(echo){
        printf("add %s\n",cmd);
      }

      success = bst_insert(&tree,cmd);
      if (!success) {
        printf("insert failed\n");
      }
    }

    else if(strcmp("print", cmd)==0){
      if(echo){
        printf("print\n");
      }

      bst_print_revorder(&tree);
    }

    else if(strcmp("preorder", cmd)==0){
      if(echo){
        printf("preorder\n");
      }

      bst_print_preorder(&tree);
    }

    else if(strcmp("save", cmd)==0){
      fscanf(stdin,"%s",cmd);
      if(echo){
        printf("save %s\n",cmd);
      }

      bst_save(&tree,cmd);
    }

    else if(strcmp("load", cmd)==0){
      fscanf(stdin,"%s",cmd);
      if(echo){
        printf("load %s\n",cmd);
      }

      bst_load(&tree,cmd);
    }

    else if(strcmp("clear", cmd)==0){
      if(echo){
        printf("clear\n");
      }

      bst_clear(&tree);
    }

    else if(strcmp("find", cmd)==0){
      fscanf(stdin,"%s",cmd);
      if(echo){
        printf("find %s\n",cmd);
      }

      success = bst_find(&tree,cmd);
      if(success){
        printf("FOUND\n");
      }else{
        printf("NOT FOUND\n");
      }
    }

    else{                                 // unknown command
      if(echo){
        printf("%s\n",cmd);
      }
      printf("Unknown command \'%s\'\n",cmd);
    }
  }

  bst_clear(&tree);
  return 0;
}
