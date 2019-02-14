#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void bst_init(bst_t *tree){
	tree->root = NULL;
	tree->size = 0;
	return;
}

int bst_insert(bst_t * tree, char name[]){
	int diff = -1;
	node_t *cur = tree->root;

	if(cur == NULL){
		node_t *new_node = malloc(sizeof(node_t));
		strcpy(new_node->name,name);
		new_node->right = NULL;
		new_node->left = NULL;
		tree->root = new_node;
		return 1;
	}else{
		while(cur != NULL){
			diff = strcmp(name,cur->name);
			if(diff < 0){
				if(cur->left != NULL){
					cur = cur->left;
				}else{
					node_t *new_node = malloc(sizeof(node_t));
					strcpy(new_node->name,name);
					new_node->right = NULL;
					new_node->left = NULL;
					cur->left = new_node;
					return 1;
				}
			}else if(diff > 0){
				if(cur->right != NULL){
					cur = cur->right;
				}else{
					node_t *new_node = malloc(sizeof(node_t));
					strcpy(new_node->name,name);
					new_node->right = NULL;
					new_node->left = NULL;
					cur->right = new_node;
					return 1;
				}
			}else{
				return 0;
			}
		}
	}
	return -1;
}

int bst_find(bst_t *tree, char name[]){
	int diff = -1;
	node_t *cur = tree->root;
	while(cur != NULL){
		diff = strcmp(name,cur->name);
		if(diff < 0){
			cur = cur->left;
		}else if(diff > 0){
			cur = cur->right;
		}else{
			return 1;
		}
	}
	return 0;
}

void bst_clear(bst_t *cur){
	node_remove_all(cur->root);
}

void node_remove_all(node_t *cur){
	node_t *freeit = cur;
	if(freeit == NULL){
		return;
	}
	node_remove_all(freeit->left);
	node_remove_all(freeit->right);
	// node_t *freeit = ptr;
	free(freeit);
}

void bst_print_revorder(bst_t *tree){
	node_print_revorder(tree->root,0);
}

void node_print_revorder(node_t *cur, int indent){
	node_t *printit = cur;
	if(printit == NULL){
		return;
	}
	node_print_revorder(printit->right,indent+1);
	for(int i=0;i<indent;i++){
		printf("  ");
	}
	printf("%s\n",printit->name);
	node_print_revorder(printit->left,indent+1);
}

void bst_print_preorder(bst_t * tree){
	node_write_preorder(tree->root,stdout,0);
}

void bst_save(bst_t *tree, char *fname){
	FILE *fin = fopen(fname,"w");
	node_write_preorder(tree->root,fin,0);
	fclose(fin);
}

void node_write_preorder(node_t *cur, FILE *out, int depth){
	node_t *printit = cur;
	if(printit == NULL){
		return;
	}
	for(int i=0;i<depth;i++){
		fprintf(out,"  ");
	}
	fprintf(out,"%s\n",printit->name);
	node_write_preorder(printit->left,out,depth+1);
	node_write_preorder(printit->right,out,depth+1);
}
