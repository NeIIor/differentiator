#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "../h/tree.h"
#include "../h/def_oper.h"

struct Node_t* create_Node (char* data, Node_t* Node)
{
    
    assert (data);
    
    struct Node_t* newNode = (struct Node_t*)calloc(1, sizeof(struct Node_t));

    if (Type_definition(data) == X)
    {
        newNode->elem.variable = (char*)calloc(strlen(data) + 1, sizeof(char));
        
        newNode->elem.number = 0;
        newNode->elem.operation = 0;
        strcpy (newNode->elem.variable, data); 

        newNode->type = X;
    }

    if (Type_definition(data) == OPERATION)
    {
        newNode->elem.variable = (char*)calloc(2, sizeof(char)); 

        newNode->elem.number = 0;
        newNode->elem.operation = Defining_operation_for_Node (data); 
        strcpy (newNode->elem.variable, "@");

        newNode->type = OPERATION;
    }

    if (Type_definition(data) == NUMBER)
    {
        newNode->elem.variable = (char*)calloc(2, sizeof(char)); 

        newNode->elem.number = atoi(data);
        newNode->elem.operation = 0;
        strcpy (newNode->elem.variable, "@");

        newNode->type = NUMBER;
    }

    if (Type_definition(data) == EMPTINESS)
    {
        newNode->elem.variable = (char*)calloc(2, sizeof(char)); 
    
        newNode->elem.number = 0;
        newNode->elem.operation = 0;
        strcpy (newNode->elem.variable, "@");

        newNode->type = EMPTINESS;
    }

    newNode->otets = Node;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node_t* Converter_tree (char** arr, Node_t* otets)
{
    assert (arr);

    char word [SIZE_OBJECT] = "";
    
    Read_word (arr, word);

    struct Node_t* Node = create_Node (word, otets);

    arr += Quentity_letters_in_word (*arr);
    
    if (**arr == '{')
    {
        (*arr)++; 
        Node->left = Converter_tree(arr, Node);
        (*arr)++; 
    }

    if (**arr == '{')
    {
        (*arr)++; 
        Node->right = Converter_tree (arr, Node);
        (*arr)++;
    }

    return Node;
}

void Read_word (char** arr, char* word)
{
    assert (arr && word);

    char* remember_position = *arr;

    while (**arr != '{' && **arr != '}' && **arr != '\0')
    {
        (*arr)++;
    }
    
    strncpy (word, remember_position, *arr - remember_position);
}

int Quentity_letters_in_word (char* arr)
{
    assert (arr);

    int i = 0;
    while (arr[i] != '{' && arr[i] != '}' && arr[i] != '\0')
    {
        i++;
    }

    return i;
}

void Deductr (struct Node_t* Node)
{   
    if (Node)
    {
        Deductr   (Node->right);
        Deductr   (Node->left);
        free      (Node->elem.variable);
        free      (Node);
    }
}

enum type_Node Type_definition (char* data)
{
    assert (data);

    if (strcmp (VARIABLE, data) == 0)           {return X;}
    if (strcmp (data, NOTH) == 0)               {return EMPTINESS;} 
    for (const char* p = data; *p != '\0'; p++) {if (!isdigit(*p)) {return OPERATION;}} 
    return NUMBER;
}//