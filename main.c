
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringx.h"

int main (int argc, const char * argv[])
{

    //simple template example

    const char* template="<template><p>Hello $name</p><div>Your value is: $val</div></template>";

	//set up the  parameters to pass to the template
    TemplateParam par[2];
	par[0]=(TemplateParam){"$name","John Doe"};
	par[1]=(TemplateParam){"$val","New York"};
    
	
    //parse the text between <template> and </template> and replace the values 
    
    char* pt=string_parseTemplate(template,"<template>","</template>",par,2);
	
	puts(pt);
	
    free(pt);
    
 
        
    return 0;
}

