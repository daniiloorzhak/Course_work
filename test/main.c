#include <stdio.h>

#define CTEST_MAIN

// uncomment lines below to enable/disable features. See README.md for details
#define CTEST_SEGFAULT
//#define CTEST_NO_COLORS
//#define CTEST_COLOR_OK

#include "ctest.h"

int main(int argc, const char *argv[])
{
    printf("\n");
    int result = ctest_main(argc, argv);

    printf("\nTests finished\n");
    return result;
}


