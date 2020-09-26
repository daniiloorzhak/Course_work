#ifndef IRRVERBS_H
#define IRRVERBS_H
    #include "verb_functions.h"
    #include <stdio.h>
    void program_meaning();
    int irrverbs(IrrVerb *correct);
    void read_verb(IrrVerb *ans, FILE *f, int line);
#endif