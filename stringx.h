#ifndef STRINGX_H
#define STRINGX_H

#ifdef __cplusplus
extern "C" {
#endif

char* string_clone(const char* str);
char* string_trim(const char* str,const char* keys);


char* string_trim(const char* str);
char* string_trimRight(const char* str);
char* string_trimLeft(const char* str);
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

int string_countOccurence(const char* str,const char* token);
int string_isNullOrEmpty(const char* str);
const char* safe_string(const char* str);



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




#define echo(s) puts(safe_string(s))



#ifdef __cplusplus
}
#endif

#endif
