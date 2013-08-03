
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringx.h"

int main (int argc, const char * argv[])
{

    //test string_start & string_end


    char* startTestString="This string starts with this";
    if(string_startsWith(startTestString,"This"))
    {
        puts("string does start with This");
    }
    else
    {
        puts("test failed for startTestString");
    }

    char* endTestString="This string ends with that";
    if(string_endsWith(endTestString,"that"))
    {
        puts("string does end with that");
    }
    else
    {
        puts("test failed for endTestString");
    }

 
    
    
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
    
    
    char* one="the first";
    char* two=" the last";
    
    char* sj=string_join(one, two);
    
    echo(sj);
    
    free(sj);
    
    char* lt={"Unu Dece"};
    char* llt=string_toLower(lt);
    echo(llt);
    if(llt!=NULL)free(llt);


    char* ut={"a small one"};
    char* uret=string_toUpper(ut);
   echo(uret);
    free(uret);

    char* aaa={"qwerty"};
    char* aaa2=(char*)calloc(1,2*strlen(aaa)+1);
    strcpy(aaa2,aaa);
    puts(aaa2);
    printf("SIZE: %lu \n",(unsigned long)strlen(aaa2));

    free(aaa2);
     
    char* ddc=string_htmlEncode("/unu/doi?par=43&name=re done&val='32' ");
    echo(ddc);
    free(ddc); 
    return 0;
}

