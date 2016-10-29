#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) ( a > b ? a : b)
#define min(a, b) ( a < b ? a : b)

typedef struct node {
    int val;
    struct node *left;
    struct node *right;  
} NODE, *NODEPTR;

NODEPTR newNode(int val) 
{
    NODEPTR newnode = (NODEPTR) malloc (sizeof(NODE));
    if (newnode) {
        newnode->val = val;
        newnode->left = newnode->right = NULL;    
    }
    return newnode;
}

int maxdepth(NODEPTR root)
{
    if (root == NULL) 
        return 0;
    return 1 + max(maxdepth(root->left), maxdepth(root->right));
}

int mindepth(NODEPTR root)
{
    if (root == NULL)
        return 0;
    return 1 + min(mindepth(root->left), mindepth(root->right));
}

bool is_balanced(NODEPTR root)
{
    return ((maxdepth(root) - mindepth(root)) <= 1);
}

int main()
{
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  NODEPTR root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(is_balanced(root))
    printf("Tree is balanced\n");
  else
    printf("Tree is not balanced\n");    
  return 0;
}
