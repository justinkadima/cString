#ifndef STRINGX_H
#define STRINGX_H

#ifdef __cplusplus
extern "C" {
#endif

char* string_clone(const char* str);
char* string_trim(const char* str,const char* keys);
int string_countOccurence(const char* str,const char* token);

#ifdef --cplusplus
}
#endif

#endif