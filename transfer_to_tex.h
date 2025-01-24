#ifndef TRANSFER_TO_TEX_H
#define TRANSFER_TO_TEX_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//
const char write_tex[] = "\\documentclass{article}\n"
                        "\\usepackage{graphicx}\n"
                        "\\usepackage[T1]{fontenc}\n"
                        "\\usepackage[utf8]{inputenc}\n"
                        "\\usepackage{amsmath,amssymb}\n"
                        "\\usepackage[russian,english]{babel}\n"
                        "\\begin{document}\n"
                        "Hello, user.\\\\\n" 
                        "I see you need help with taking the derivative.\\\\\n"
                        "Well, let's get started\\\\\n"
                        "Your function looks like this\\\\\n";

void Print_derivative_to_tex (struct Node_t* node, FILE* file_tex);
void Transfer_to_tex         (struct Node_t* node, struct Node_t* diff, FILE* file_tex);

#endif //TRANSFER_TO_TEX_H

