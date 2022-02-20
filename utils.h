#ifndef UTILS_H /* Include guard */
#define UTILS_H

//Function declarations
int isLower(int);
int isUpper(int);
int toLower(int);
int toUpper(int);
char *Strcpy(char*, char*);
int Strlen(const char*);
int Strcmp(const char*, const char*);
int Strcmpi(const char*, const char*);
int Strncmp(const char*, const char*, int);
int Strncmpi(const char*, const char*, int);
void Strncat(char*, const char*, int);
int AtoI(const char*);
float AtoF(const char*);
void reverse(char*);
void ItoA(int, char*);
void FtoA(float, char*, int);
int binSearch_retIndex(char*, int, int);
int binSearch_retStat(char*, int, int);
int insert(char*, int, int, int, int);
int delete(char*, int, int);
int linear_search(char*, int, int);
int linear_search_ret_ind(char*, int, int);
void Memset(char*, int, int);

#endif

