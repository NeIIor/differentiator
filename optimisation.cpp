#include "optimisation.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include "dump.h"
#include "macros.h"

void First_optimisation (Node_t* node)
{
    if (node == NULL) {return;}
    if (NODE_NOT_OPERATION_1)
    {
        return;
    }
    if (NODES_NOT_NUMBER)
    {
        First_optimisation (node->left);
    }
    if (ALL_TYPE_NUMBER)
    { 
        First_optimisation_operation_with_node (node);
        return;
    }

    if (NODES_NOT_NUMBER)
    {
        First_optimisation (node->right);
    }
    
    if (ALL_TYPE_NUMBER)
    {
        First_optimisation_operation_with_node (node);
        return;
    }
    
    return;
}

Node_t* First_optimisation_operation_with_node (Node_t* node)
{
    int result = 0;

    if (node->elem.operation == _ADD) {FIRST_OPTIMISATION (node->left->elem.number + node->right->elem.number);}
    if (node->elem.operation == _SUB) {FIRST_OPTIMISATION (node->left->elem.number - node->right->elem.number);}
    if (node->elem.operation == _MUL) {FIRST_OPTIMISATION (node->left->elem.number * node->right->elem.number);}
    if (node->elem.operation == _DIV) {FIRST_OPTIMISATION (node->left->elem.number / node->right->elem.number);}
    if (node->elem.operation == _DEG) {FIRST_OPTIMISATION (pow (node->left->elem.number, node->right->elem.number));}

    return node;
}

void Second_optimisation (Node_t** node)
{
    assert (*node);
    assert (node);

    if (NODE_NOT_OPERATION)
    {
        return;
    }

    if (TYPES_NO_NUMBER_AND_X)
    {
        Second_optimisation (&(*node)->left);
    }
    if (TYPES_NUMBER_AND_X)
    { 
        Second_optimisation_operation_with_node (node);
        return;
    }

    if (TYPES_NO_NUMBER_AND_X)
    {
        Second_optimisation (&(*node)->right);
    }
    
    if (TYPES_NUMBER_AND_X)
    {
        Second_optimisation_operation_with_node (node);
        return;
    }
    
    return;
}

Node_t* Second_optimisation_operation_with_node (Node_t** node)
{
    if (CONDITION_FOR_START_SECOND_OPTIMIZATION)
    {
        if (((*node)->right->elem.number == 0 || (*node)->right->elem.number == 0) && (*node)->elem.operation == _ADD) 
        {
            if ((*node)->right->elem.number == 0) {OPTIMISATION_FOR_ADD_SUB_MUL(right, left);}
            if ((*node)->left->elem.number == 0)  {OPTIMISATION_FOR_ADD_SUB_MUL(left, right);}
        }
    
        if ((*node)->elem.operation == _SUB) {OPTIMISATION_FOR_ADD_SUB_MUL(right, left);} 

        if ((*node)->elem.operation == _MUL && ((*node)->left->type == NUMBER || (*node)->right->type)) 
        {
            if ((*node)->left->elem.number == 1)    {OPTIMISATION_FOR_ADD_SUB_MUL(left, right);}
            if ((*node)->right->elem.number == 1)   {OPTIMISATION_FOR_ADD_SUB_MUL(right, left);}  
            else                                    {OPTIMISATION_FOR_MUL_DIV_DEG(0);}
        }
        
        if ((*node)->right->elem.number == 0 || (*node)->left->elem.number == 0)
        {
            if ((*node)->elem.operation == _DIV)
            {
                if ((*node)->right->type == NUMBER)
                {
                    printf ("Error, you can't divide by zero");
                    abort;
                }

                if ((*node)->left->elem.number == 0 && (*node)->left->type == NUMBER) {OPTIMISATION_FOR_MUL_DIV_DEG(0);}
                
            }
        }

        if ((*node)->elem.operation == _DEG)
        {
            if ((*node)->right->elem.number == 0) {OPTIMISATION_FOR_MUL_DIV_DEG(1);}
            if ((*node)->left->elem.number == 0)  {OPTIMISATION_FOR_MUL_DIV_DEG(0);}
        }
        return *node;
    }
    return *node;
}

void First_deducr_certain_node (Node_t* node)
{
    assert (node);
    
    free (node->left->elem.variable);
    free (node->right->elem.variable);
    free (node->left);
    free (node->right );
    node->left = NULL;
    node->right = NULL;
}