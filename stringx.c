#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringx.h"


const char* safe_string(const char* str)
{
	if(str==NULL)return "NULL";
	if(str[0]=='\0')return "EMPTY";
	return str;
	 
}

int string_isNullOrEmpty(const char* str)
{
	if(str!=NULL && str[0]!='\0')return 0;
	return 1;

}

int string_countOccurence(const char* str,const char* token)
{
	int x=0;
	if(!string_isNullOrEmpty(str) && !string_isNullOrEmpty(token))
	{
		
		char* temp=(char*)str;
		while((temp=strstr(temp,token))!=NULL)
		{
			temp+=strlen(token);
			x++;
		}
	}
	return x;
}



char* string_replace(const char* str,const char* oldval,const char* newval)
{
	if(!string_isNullOrEmpty(str) && !string_isNullOrEmpty(oldval) && !string_isNullOrEmpty(newval))
	{

		int oc=string_countOccurence(str,oldval);

		if(oc>0)
		{
			size_t diff=strlen(newval)-strlen(oldval);
			size_t nsize=strlen(str)+oc*diff+1;
			
			char* buff=(char*) calloc(1,nsize);

			if(buff!=NULL)
			{
				char* temp=NULL;
				char* mark=(char*)str;

				while((temp=strstr(mark,oldval))!=NULL)
				{
					
					size_t off=strlen(mark)-strlen(temp);

					strncat(buff,mark,off);
					strncat(buff,newval,strlen(newval));

					temp+=strlen(oldval);
					mark=temp;
				}

				strncat(buff,mark,strlen(mark));

				return buff;
			}

			free(buff);

		}

	}
	return NULL;
}


char* string_extractBetweenTokens(const char* str,const char* tokenstart,const char* tokenend)
{
	if(!string_isNullOrEmpty(str) && !string_isNullOrEmpty(tokenstart) && !string_isNullOrEmpty(tokenend))
	{
		char* tok1=strstr((char*)str,tokenstart);
		if(tok1!=NULL)
		{
			tok1+=strlen(tokenstart);
			char* tok2=strstr(tok1,tokenend);

			if(tok2!=NULL)
			{
				size_t off=strlen(tok1)-strlen(tok2);
				char* buff=(char*)calloc(1,off+1);
				strncpy(buff,tok1,off);
				return buff;
			}

		}

	}
	return NULL;

}



char* string_replaceBetweenTokens(const char* str,const char* tokenstart,const char* tokenend,const char* val,TokensInclusion withtokens)
{
	if(!string_isNullOrEmpty(str) && !string_isNullOrEmpty(tokenstart) && !string_isNullOrEmpty(tokenend) && !string_isNullOrEmpty(val))
	{
		char* tok1=strstr((char*)str,tokenstart);
		if(tok1!=NULL)
		{
			if(withtokens==In)
			{
				tok1+=strlen(tokenstart);
				
			}
			
			size_t dift1=strlen(str)-strlen(tok1);
			char* tok2=strstr(tok1,tokenend);

			if(tok2!=NULL)
			{
				if(withtokens==Out)
				{
					tok2+=strlen(tokenend);
				}
				size_t newsize=dift1+strlen(val)+strlen(tok2);
				char* buff=(char*)calloc(1,newsize+1);

				strncat(buff,str,dift1);
				strcat(buff,val);
				strcat(buff,tok2);

				return buff;


			}

		}


	}

	return NULL;
}


unsigned int string_startsWith(const char* str,const char* token)
{	
        if(strncmp(str,token,strlen(token))==0)return 1;
        return 0;
}

unsigned int string_endsWith(const char* str,const char* token)
{
	
        if(!string_isNullOrEmpty(str) && !string_isNullOrEmpty(token))
		{
           int off=strlen(str)-strlen(token);
           if(off>=0)
           {
               char* temp=(char*)str;
               temp+=off;
               if(strncmp(temp,token,strlen(token))==0)return 1;
           }
        }
        return 0;

}




SplitResult* string_split(const char* str,const char* sep)
{
	if(!string_isNullOrEmpty(str) && !string_isNullOrEmpty(sep))
	{
		SplitResult* res=(SplitResult*)calloc(1,sizeof(SplitResult));
		res->nr=0;

		if(res!=NULL)
		{
			int oc=string_countOccurence(str,sep);
			if(oc>0)
			{
				int dim=oc+1;

				if(string_startsWith(str,sep))dim--;
				if(string_endsWith(str,sep))dim--;

				res->fragments=(char**)calloc(dim,sizeof(char*));
				if(res->fragments!=NULL)
				{
					char* temp=NULL;
					char* old=(char*)str;

					while(1)
					{
						temp=strstr(old,sep);

						size_t dif=0;

						if(temp==NULL)
						{
							dif=strlen(old);
						}
						else
						{
							dif=strlen(old)-strlen(temp);
						}
						
						if(dif>0)
						{
							res->nr++;
							*(res->fragments)=(char*)calloc(dif+1,sizeof(char));
							strncpy(*(res->fragments),old,dif);
							if(res->nr<dim)
							{
								res->fragments+=sizeof(char*);
							}
						}

						if(temp==NULL)break;

						temp+=strlen(sep);
						old=temp;
					}
					res->fragments-=sizeof(char*)*(res->nr-1);
					return res;

				}
			}

		}

	}
	return NULL;
}


char* string_trimLeft(const char* str)
{
	if(!string_isNullOrEmpty(str))
	{
		int off=0;
		while(1)
		{
			
			if(str[off]==' ')
			{
				off++;
			}
			else
			{
				break;
			}
		}

		if(off>0 && off<strlen(str))
		{
			char* temp=NULL;
			char* ret=(char*)calloc(strlen(str)-off+1,sizeof(char));
			if(ret!=NULL)
			{
				temp=(char*)str;
				temp+=off*sizeof(char);
				strncpy(ret,temp,strlen(str)-off);
				return ret;
			}
		}
		

	}
	return NULL;
}

char* string_trimRight(const char* str)
{
	if(!string_isNullOrEmpty(str))
	{
		int off=0;
                int x;
                
		for(x=(int)(strlen(str)-1);x>=0;x--)
		{
			
			if(str[x]==' ')
			{
				off++;
			}
			else
			{
				break;
			}

		}

		if(off>0 && off<strlen(str))
		{
			
			char* ret=(char*)calloc(strlen(str)-off+1,sizeof(char));
			if(ret!=NULL)
			{
				strncpy(ret,str,strlen(str)-off);
				return ret;
			}
		}

	}

	return NULL;
}


char* string_trim(const char* str)
{
    if(!string_isNullOrEmpty(str))
    {
        char* temp=string_trimLeft(str);
        char* sec=NULL;
        if(temp==NULL)
        {
            sec=(char*)str;
        }
        else
        {
            sec=temp;
        }
        char* res=string_trimRight(sec);
        if(temp!=NULL)
        {
            if(res==NULL)res=temp;
            else free(temp);
            
        }
        return res;
    }
    return NULL;
}


char* string_parseTemplate(const char* templ,const char* starttoken,const char* endtoken,TemplateParam* params,int paramnr)
{

    char* ret=NULL;

	if(!string_isNullOrEmpty(templ) && !string_isNullOrEmpty(starttoken) && !string_isNullOrEmpty(endtoken) && params!=NULL && paramnr>0)
	{
		
			
			char* ex=string_extractBetweenTokens(templ,starttoken,endtoken);
			if(!string_isNullOrEmpty(ex))
			{
                                
                                
				int t=0;
				char* back=string_clone(ex);
				
				
				while(t<paramnr)
				{
                                         
					char* temp=string_replace(back,params[t].name,params[t].value);
					
                                        
					if(!string_isNullOrEmpty(temp))
					{
                        free(back);
						back=string_clone(temp);
						free(temp);
                        t++;
					}
					else
					{
                        free(temp);
						break;
					}			
					
				}
                                
                ret=string_replaceBetweenTokens(templ,starttoken,endtoken,back,Out);
                free(back);
                                

			}
			free(ex);
			
	}

	return ret;
}








char* string_trimMultiple(const char* str,const char* keys)
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
            if(ret)
            {
           		strcpy(ret,str);
           		return ret;
            }
    }
    return NULL;
}

char* string_join(const char* str1,const char* str2)
{
    if(str1==NULL && str2==NULL)
    {
        return NULL;
    }
    
    size_t sz1=0;
    size_t sz2=0;
    
    
   
    if(str1!=NULL)sz1=strlen(str1);
    if(str2!=NULL)sz2=strlen(str2);
    
    char* ret=(char*)calloc(sz1+sz2+1,sizeof(char));
    if(ret!=NULL)
    {
        if(str1!=NULL)
        {
            ret=strcat(ret,str1);
        }
        if(str2!=NULL)
        {
            ret=strcat(ret,str2);
        }
        
        return ret;
    }
    
    return NULL;
   
    
}


char* string_toLower(const char* str)
{
    if(str!=NULL)
    {
        char* ret=string_clone(str);
        int x=0;
        int sx=strlen(str);
        while(x<sx)
        {
            ret[x]=tolower(ret[x]);
            x++;
        }
        return ret;
    }
    return NULL;
    
}

char* string_toUpper(const char* str)
{
	if(str!=NULL)
	{
		char* ret=string_clone(str);
		if(ret==NULL)return NULL;
		int x=0,sx=strlen(str);
		
		while(x<sx)
		{
			ret[x]=toupper(ret[x]);
			x++;

		}
		return ret;

	}
	return NULL;

}

char* string_htmlEncode(const char* str)
{
	if(str!=NULL)
	{
		int x=0;
        size_t len=strlen(str);
        char* ret=(char*)calloc(3*len+1,sizeof(char));
        if(ret==NULL)return NULL;
        
        char* buf=(char*)calloc(10,sizeof(char));
        if(buf==NULL)
        {
        	free(ret);
        	return NULL;
        }
        
       
        while(x<len)
        {
        	switch(str[x])
        	{
        		case '&':
        			sprintf(buf,"%s","&amp;");
        		break;
        		case '\"':
        			sprintf(buf,"%s","&quot;");
        		break;
        		case '\'':
        			sprintf(buf,"%s","&apos;");
        		break;
        		case '<':
        			sprintf(buf,"%s","&lt;");
        		break;
        		case '>':
        			sprintf(buf,"%s","&gt;");
        		break;
        		default:
        			sprintf(buf,"%c",str[x]);
        	}
        	strcat(ret,buf);
        	x++;
        }         
		free(buf);
		return ret;

	}
	return NULL;



}

char* string_urlEncode(const char* str)
{

	if(str!=NULL)
	{
		int x=0;
        size_t len=strlen(str);
        char* ret=(char*)calloc(3*len+1,sizeof(char));
        if(ret==NULL)return NULL;
        
        char* buf=(char*)calloc(10,sizeof(char));
        if(buf==NULL)
        {
        	free(ret);
        	return NULL;
        }
        
        while(x<len)
        {
        		char c=str[x];
        		
        		if( ('a' <= c && c <= 'z')|| ('A' <= c && c <= 'Z')|| ('0' <= c && c <= '9') )
        		{
        			sprintf(buf,"%c",c);
        	
        		}
        		else
        		{
        			sprintf(buf,"%%%02X",c);
        		}
        	
        	strcat(ret,buf);
        	x++;
        }         
		free(buf);
		return ret;

	}
	return NULL;

}



char* string_XORcypher(char* str,const char* key)
{
	if(string_isNullOrEmpty(str) || string_isNullOrEmpty(key))
	{
		return str;	
	
	}
	
	int szstr=(int)strlen(str);
	int szkey=(int)strlen(key);
	
	int x=0;
	int y=0;
	
	
	
	while(x<szstr)
	{
		str[x]=str[x]^key[y];
		x++;
		y++;
		
		if(y==szkey)y=0;	
	
	}
	
	return str;
}
