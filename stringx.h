#ifndef STRINGX_H
#define STRINGX_H

#ifdef __cplusplus
extern "C" {
#endif

char* string_clone(const char* str);
char* string_join(const char* str1,const char* str2);

int string_countOccurence(const char* str,const char* token);
int string_isNullOrEmpty(const char* str);
const char* safe_string(const char* str);
    
#define echo(s) puts(safe_string(s))
    

char* string_trim(const char* str);
char* string_trimRight(const char* str);
char* string_trimLeft(const char* str);
char* string_trimMultiple(const char* str,const char* keys);
    
unsigned int string_endsWith(const char* str,const char* token);
unsigned int string_startsWith(const char* str,const char* token);

typedef enum
{
	Out,
	In
}TokensInclusion;

char* string_replaceBetweenTokens(const char* str,const char* tokenstart,const char* tokenend,const char* val,TokensInclusion withtokens);
char* string_extractBetweenTokens(const char* str,const char* tokenstart,const char* tokenend);
char* string_replace(const char* str,const char* oldval,const char* newval);





typedef struct
{
	char** fragments;
	unsigned int nr;

}SplitResult;

SplitResult* string_split(const char* str,const char* sep);


typedef struct
{
	char* name;
	char* value;
}TemplateParam;

char* string_parseTemplate(const char* templ,const char* starttoken,const char* endtoken,TemplateParam* params,int paramnr);



char* string_toLower(const char* str);
char* string_toUpper(const char* str);

char* string_XORcypher(char* str,const char* key);


char* string_htmlEncode(const char* str);
char* string_urlEncode(const char* str);




#ifdef __cplusplus
}
#endif

#endif
