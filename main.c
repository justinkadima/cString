
#include <stdio.h>
#include <stdlib.h>
#include "stringx.h"

int main (int argc, const char * argv[])
{
    const char* buf="  aici a fost aici se duce    ";
    char* ret= string_trimMultiple(buf," ,i"); 
    puts(ret);
    free(ret);


    const char* template="<html><body><h1>Title</h1><template><p>Hello $name</p><div>Your value is: $val</div></template></body></html>";

    TemplateParam p1={"$name","John"};
    char* pt=string_parseTemplate(template,"<template>","</template>",&p1,1);
    puts(pt);
    return 0;
}

