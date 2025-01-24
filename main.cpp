#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//
#include "derevtso.h"
#include "fillbuf.h"
#include "dump.h"
#include "optimisation.h"
#include "copy_tree.h"
#include "differentiator.h"
#include "transfer_to_tex.h"

int main()
{
    size_t helper_1 = 0;
    size_t helper_2 = 0;

    FILE* file_derevtso = fopen ("function.txt", "r");
    assert (file_derevtso);

    char* arr =  Filling_buffer (file_derevtso, &arr);
    char* to_free = arr;

    arr++;

    struct Node_t* Node = Сonverter_tree (&arr, NULL);
    assert (Node);

    Dump_moment (Node);

    while (helper_1 != 10)
    {
        First_optimisation (Node);
        Second_optimisation (&Node);
        helper_1++;
    }

    Dump_moment (Node);
    
    struct Node_t* Diff = Differentiator (Node);
    assert (Diff);

    Dump_moment (Diff);

    while (helper_2 != 10)
    {
        First_optimisation (Diff);
        Second_optimisation (&Diff);
        helper_2++;
    }

    Dump_moment (Diff);

    FILE* file_tex = fopen ("derivative.tex", "w");
    assert (file_tex);

    Transfer_to_tex (Node, Diff, file_tex);

    fclose (file_tex);

    system ("latexmk derivative.tex");

    Deductr (Node);
    Deductr (Diff);
    free (to_free); 

    return 0;

}