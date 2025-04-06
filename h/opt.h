#ifndef OPTIMISATION_H
#define OPTIMISATION_H
//
#include "tree.h"
#include "oper.h"
#include "enum_oper.h"
#include "diff.h"

void First_optimisation                           (Node_t* Node);
void Second_optimisation                          (Node_t** node);
void First_deducr_certain_node                    (Node_t* node);
Node_t* First_optimisation_operation_with_node    (Node_t* node);
Node_t* Second_optimisation_operation_with_node   (Node_t** node);

#endif // OPTIMISATION_H