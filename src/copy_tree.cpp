#include "../h/copy_tree.h"
#include "../h/tree.h"
//w     
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node_t* Copy_tree (Node_t* node){ 
    if (node == NULL){
        return NULL;
    }
    
    Node_t* copynode = (struct Node_t*)calloc(1, sizeof(struct Node_t));
    copynode->elem.variable = (char*)calloc(2, sizeof(char));

    copynode->elem.number = node->elem.number;
    copynode->elem.operation = node->elem.operation;
    strcpy (copynode->elem.variable, node->elem.variable); 

    copynode->type = node->type;
    copynode->left = Copy_tree(node->left);
    copynode->right = Copy_tree (node->right);

    return copynode;
}