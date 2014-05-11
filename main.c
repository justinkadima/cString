
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringx.h"

int main (int argc, const char * argv[])
{

    //simple template example

    const char* template="<template><p>Hello $name</p><div>Your value is: $val</div></template>";

    TemplateParam par[2];
	par[0]=(TemplateParam){"$name","John Doe"};
	par[1]=(TemplateParam){"$val","New York"};
    
	
    //parse the text between <template> and </template> and replace the values 
    
    char* pt=string_parseTemplate(template,"<template>","</template>",par,2);
    /*
    par[0].value="Dan";
    par[1].value="Germany";
	char* spt=string_parseTemplate(template,"<template>","</template>",par,2);
	
	
	char* fpt=string_join(pt,spt);
	
	puts(fpt);
	*/
	
	puts(pt);
	
    free(pt);
    // free(spt);
    // free(fpt);
 
        
    return 0;
}

