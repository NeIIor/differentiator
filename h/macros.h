#ifndef MACROS_H
#define MACROS_H
//
#include "tree.h"

#define FIRST_OPTIMISATION(operation_) \
{ \
    result = (operation_); \
    node->elem.number = result; \
    node->type = NUMBER; \
    node->elem.operation = 0; \
    First_deducr_certain_node(node); \
} 

#define NODES_NOT_NUMBER (node->left->type != NUMBER || node->right->type != NUMBER)
#define ALL_TYPE_NUMBER  (node->left->type == NUMBER && node->right->type == NUMBER) 
#define CONDITION_FOR_START_SECOND_OPTIMIZATION (((*node)->left->type == NUMBER && (*node)->left->elem.number == 0) || \
                                                ((*node)->left->type == NUMBER && (*node)->left->elem.number == 1) || \
                                                ((*node)->right->type == NUMBER && (*node)->right->elem.number == 0) || \
                                                ((*node)->right->type == NUMBER && (*node)->right->elem.number == 1))

#define NODE_NOT_OPERATION ((*node)->type == NUMBER || (*node)->type == X || (*node)->type == EMPTINESS)
#define NODE_NOT_OPERATION_1 (node->type == NUMBER || node->type == X || node->type == EMPTINESS)
#define TYPES_NO_NUMBER_AND_X (!((*node)->left->type == NUMBER || (*node)->right->type == NUMBER))
                            
#define TYPES_NUMBER_AND_X ((*node)->left->type == NUMBER || (*node)->right->type == NUMBER)

#define RESULT(type_, value_) \
{ \
    node->type = type_; \
    node->elem.operation = 0; \
    if (type_ == X) \
    { \
        strcpy(node->elem.variable, VARIABLE); \
    } \
    else if (type_ == NUMBER) \
    { \
        node->elem.number = value_; \
    } \
    First_deducr_certain_node(node); \
    return node; \
}

#define OPTIMISATION_FOR_ADD_SUB_MUL(cleared_node, replaceable_node) \
{ \
    Deductr ((*node)->cleared_node); \
    (*node) = (*node)->replaceable_node; \
    return *node; \
}

#define OPTIMISATION_FOR_MUL_DIV_DEG(elemik) \
{ \
    (*node)->type = NUMBER; \
    (*node)->elem.number = elemik; \
    (*node)->elem.variable = 0; \
    Deductr ((*node)->left); \
    Deductr ((*node)->right); \
    (*node)->left = NULL; \
    (*node)->right = NULL; \
    return *node; \
}

#define TRANSFER_DIV_MUL(first, second, third) \
{ \
    fprintf (file_tex, first); \
    Print_derivative_to_tex (node->left, file_tex); \
    fprintf (file_tex, second); \
    Print_derivative_to_tex (node->right, file_tex); \
    fprintf (file_tex, third); \
}

#define TRANSFER_DEG(first, second) \
{ \
    Print_derivative_to_tex (node->left, file_tex); \
    fprintf (file_tex, first, DEG); \
    Print_derivative_to_tex (node->right, file_tex); \
    fprintf (file_tex, second); \
}

#define TRANSFER_ADD_SUB(first, operation) \
{ \
    Print_derivative_to_tex (node->left, file_tex); \
    fprintf (file_tex, first, operation); \
    Print_derivative_to_tex (node->right, file_tex); \
}


#define PRINT_UNARY_OP(op, func) \
    fprintf(file_tex, "%s(", func); \
    Print_derivative_to_tex(node->right, file_tex); \
    fprintf(file_tex, ")");

#endif //MACROS_H
