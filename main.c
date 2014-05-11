
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
    
	//a more complex example
	
	const char* template2="<html><body> \
	<p>Website template</p> \
	<div><ul><articles><li>$title</li></articles></ul></div> \
	<div> By: <author>$name</author> </div> \
	</body></html>";

	const char* author="Peter Erz";
	//char* titles[]={"Long road ahead","The mimic","Godlieb"};
    
	
	TemplateParam pp[2]={(TemplateParam){"$title","unu"},(TemplateParam){"$title","doi"}};
	char* rr=string_parseTemplateFragment(template2,"<articles>","</articles>",pp,2);
	TemplateParam autp[1]={(TemplateParam){"$name",author}};
	char* fin=string_parseTemplateFragment(rr,"<author","</author>",autp,1);
	free(rr);
	
	puts(fin);
	free(fin);
    
    return 0;
}

