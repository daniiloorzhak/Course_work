#include <stdlib.h>
#include <stdio.h>
#include "verb_functions.h"
#include <time.h>

int check_answer(IrrVerb *corr,char *s1,char *s2)
{
    int p = 1;
    for(int i=0;corr->verb[1][i] != '\0' && corr->verb[2][i]!= '\0' ;i++)
    {
        if(corr->verb[1][i] != s1[i] || corr->verb[2][i] != s2[i])
        {
            p=0;
            break;
        }
    }
    return p;
}

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
