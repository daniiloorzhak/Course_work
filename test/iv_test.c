#include <stdlib.h>
#include <stdio.h>

#include "ctest.h"
#include "irrverbs.h"
#include "random_numbers.h"
#include "verb_functions.h"

//irrverbs
CTEST(suite1, test1){
    char* expected = "beat";
    IrrVerb* irrverb = malloc(sizeof(IrrVerb));
    FILE* cur = fopen("src/IV.txt","r");
    read_verb(irrverb, cur, 5) ;
    char* real = irrverb->verb[0];
    //beat beat beaten 
    ASSERT_STR(expected, real);
    ASSERT_STR("beat", irrverb->verb[1]);
    ASSERT_STR("beaten", irrverb->verb[2]);
}

//make_arr
CTEST(suite, test2)
{
//ASSERT_DATA(exp, expsize, real, realsize)
    int *exp = malloc(sizeof(int) * 200);
    for(int i = 0; i < 200; i++)
        exp[i] = i + 1;
    int *real = malloc(sizeof(int) * 200); 
    make_arr(real, 200);
    ASSERT_DATA(exp, 200, real, 200);
}