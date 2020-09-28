#include <stdlib.h>
#include <stdio.h>

#include "ctest.h"
#include "irrverbs.h"
#include "random_numbers.h"
#include "verb_functions.h"

//readverb
CTEST(read_verb, test1){
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
CTEST(make_arr, test1){
    int numbers[200];
    make_arr(numbers, 200);
    for(int i = 0; i < 200; i++)
        ASSERT_EQUAL(i + 1, numbers[i]);
}

//shuffle
CTEST(shuffle, test1){
    int numbers1[200];
    int numbers2[200];
    make_arr(numbers1, 200);
    make_arr(numbers2, 200);
    shuffle(numbers1, 200);
    shuffle(numbers1, 200);
    int counter = 0;
    for(int i = 0; i < 200; i++){
        if(numbers1[i] == numbers2[i])
            counter++;
    ASSERT_NOT_EQUAL(200, counter);
    }
}