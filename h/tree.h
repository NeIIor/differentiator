#ifndef DEREVTSO_H
#define DEREVTSO_H

static const int SIZE_FILENAME = 100;
static const int SIZE_COMMAND  = 256;
static const int SIZE_OBJECT   = 25;
static const char VARIABLE[]   = "x";
static const char NOTH[]       = "";

enum type_Node 
{
    X           = 1,     
    NUMBER      = 2,     
    OPERATION   = 3,    
    EMPTINESS   = 4, 
};

struct Elem_t
{
    int operation;
    char* variable;
    double number;
};

struct Node_t
{
    Elem_t elem;
    Node_t* left;
    Node_t* right;
    Node_t* otets;
    type_Node type;
};

struct Node_t* Converter_tree    (char** arr, Node_t* otets);
void Read_word                   (char** arr, char* word);
Node_t* create_Node              (char* data, Node_t* Node);
int Quentity_letters_in_word     (char* arr);
void Deductr                     (struct Node_t* Node);
enum type_Node Type_definition   (char* data);

#endif // DEREVTSO_H//