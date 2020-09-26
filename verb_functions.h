#ifndef VERB_FUNCTIONS_H
#define VERB_FUNCTIONS_H
    typedef struct {
        char verb[3][14];
    }IrrVerb;
    int check_answer(IrrVerb *corr,char *s1,char *s2);
    
#endif