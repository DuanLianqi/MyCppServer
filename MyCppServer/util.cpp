#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void errif(bool condition, const char *errorMsg)
{
    if(condition)
    {
        perror(errorMsg);
        exit(EXIT_FAILURE);
    }
}
