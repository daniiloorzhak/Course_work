#include <stdlib.h>
#include <stdio.h>
#include "read_verbs.h"
#include <time.h>

void read_verb(IrrVerb *ans, FILE *f, int line)
{
    int nlcounter = 0;
    while(nlcounter != (line - 1))
    {
        if (fgetc(f) == '\n')
            nlcounter += 1;
    }
    for(int i = 0 ; i < 3; i++)
        fscanf(f, "%s", ans->verb[i]);
    fseek(f, 0, SEEK_SET);
}
