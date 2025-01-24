#include "transfer_to_tex.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "derevtso.h"
#include "defining_operation.h"
#include "optimisation.h"
#include "macros.h"

void Transfer_to_tex (struct Node_t* node, struct Node_t* diff, FILE* file_tex)
{
    fprintf(file_tex, write_tex);

    fprintf (file_tex, "\\[\n");
    fprintf (file_tex, "f(x) = ");
    Print_derivative_to_tex (node, file_tex); 
    fprintf (file_tex, "\n\\]\n"); 

    fprintf (file_tex, "The derivative of your function will look like this:\\\\\n");

    fprintf (file_tex, "\\[\n");
    fprintf (file_tex, "(f(x))' = ");
    Print_derivative_to_tex (diff, file_tex); 
    fprintf (file_tex, "\n\\]\n");

    fprintf (file_tex, "Thank you for using my program, good luck\\\\\n"
                    "\\end{document}");
} 

void Print_derivative_to_tex(struct Node_t* node, FILE* file_tex) 
{
    assert (file_tex);
    {
        if (node == NULL) 
        {
            return;
        }

        if (node->type == OPERATION) 
        {
            if      (node->elem.operation == _DIV)    {TRANSFER_DIV_MUL("{", "\\over ", "}");}
            else if (node->elem.operation == _MUL)    {TRANSFER_DIV_MUL("\\left(", "\\right) \\cdot \\left(", "\\right)");}
            else if (node->elem.operation == _DEG)    {TRANSFER_DEG("%s{", "}");}
            else if (node->elem.operation == _ADD)    {TRANSFER_ADD_SUB("%s", ADD);}
            else if (node->elem.operation == _SUB)    {TRANSFER_ADD_SUB("%s", SUB);}
            else if (node->elem.operation == _SIN)    {PRINT_UNARY_OP(_SIN, SIN);} 
            else if (node->elem.operation == _COS)    {PRINT_UNARY_OP(_COS, COS);} 
            else if (node->elem.operation == _TG)     {PRINT_UNARY_OP(_TG, TG);} 
            else if (node->elem.operation == _CTG)    {PRINT_UNARY_OP(_CTG, CTG);} 
            else if (node->elem.operation == _ARCSIN) {PRINT_UNARY_OP(_ARCSIN, ARCSIN);} 
            else if (node->elem.operation == _ARCCOS) {PRINT_UNARY_OP(_ARCCOS, ARCCOS);} 
            else if (node->elem.operation == _ARCTG)  {PRINT_UNARY_OP(_ARCTG, ARCTG);} 
            else if (node->elem.operation == _ARCCTG) {PRINT_UNARY_OP(_ARCCTG, ARCCTG);} 
            else if (node->elem.operation == _SH)     {PRINT_UNARY_OP(_SH, SH);} 
            else if (node->elem.operation == _CH)     {PRINT_UNARY_OP(_CH, CH);} 
            else if (node->elem.operation == _TH)     {PRINT_UNARY_OP(_TH, TH);} 
            else if (node->elem.operation == _CTH)    {PRINT_UNARY_OP(_CTH, CTH);} 
            else if (node->elem.operation == _LOG)    {PRINT_UNARY_OP(_LOG, LOG);} 
            else if (node->elem.operation == _LN)     {PRINT_UNARY_OP(_LN, LN);}
        }
    }//
        if (node->type == NUMBER) 
        {
            fprintf(file_tex, "%0.2lf ", node->elem.number);
        } 
        else if (node->type == X) 
        {
            fprintf(file_tex, "%s", node->elem.variable);
    }
}
