#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringx.h"


int string_countOccurence(const char* str,const char* token)
{
    int ret=0;
    
    if(str!=NULL && token!=NULL)
    {
        char* temp=(char*)str;
        
        while((temp=strstr(temp,token))!=NULL)
        {
            temp+=strlen(token)*sizeof(char);
            ret++;
        }
        
    }
    return ret;
}


char* string_trim(const char* str,const char* keys)
{
    
    char* temp=strpbrk(str,keys);
    char* old=(char*)str;
    
    if(temp!=NULL)
    {
      char* buf=(char*)calloc(1,strlen(str)+1); 

    while(1)
    {

        size_t diff=strlen(old)-strlen(temp);
        
        
        if(diff>0)
        {

            strncat(buf,old,diff);
            
        }
        
        old=temp+1;
        temp=strpbrk(old,keys);
        if(temp==NULL)
        {
            strncat(buf,old,strlen(old));
            break;
        }
    }
        return buf;
    }
    
    return NULL;
    
}

char* string_clone(const char* str)
{
    if(str!=NULL)
    {
            char* ret=(char*)calloc(1,(strlen(str)+1)*sizeof(char));
            strcpy(ret,str);
            return ret;
    }
    return NULL;
}