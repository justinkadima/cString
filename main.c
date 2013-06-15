
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

    TemplateParam par[2];
    par[0].name="$name";
    par[0].value="John";
    par[1].name="$val";
    par[1].value="London";
    
    char* pt=string_parseTemplate(template,"<template>","</template>",par,2);
    puts(pt);

    free(pt);
    
    
    char* one={"the first"};
    char* two={" the last"};
    
    char* sj=string_join(one, two);
    
    echo(sj);
    
    free(sj);
    
    return 0;
}

