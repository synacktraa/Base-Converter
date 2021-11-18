#ifndef STRINGFUNC_H /* Include guard */
#define STRINGFUNC_H

//Function declarations
int isLower(int);
int isUpper(int);
int toLower(int);
int toUpper(int);
char *Strcpy(char*, char*);
int Strlen(const char*);
int Strcmp(const char*, const char*);
int Strcmpi(const char*, const char*);
int Strncmp(const char*, const char*, size_t);
int Strncmpi(const char*, const char*, size_t);
void Strncat(char*, const char*, size_t);


#endif

