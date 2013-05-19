
#include <stdio.h>
#include <stdlib.h>
#include "stringx.h"

int main (int argc, const char * argv[])
{
    const char* buf="  aici a fost aici se duce    ";
    char* ret= string_trim(buf," "); 
    puts(ret);
    free(ret);
   
    return 0;
}

