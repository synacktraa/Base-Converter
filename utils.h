#ifndef UTILS_H /* Include guard */
#define UTILS_H

//Function declarations
int power(int base, int exp);
int isLower(int ch);
int isUpper(int ch);
int isDigit(int n);
int toLower(int ch);
int toUpper(int ch);
char *Strcpy(char* destination, char* source);
int Strlen(const char* string);
int Strcmp(const char* string_1, const char* string_2);
int Strcmpi(const char* string_1, const char* string_2);
int Strncmp(const char* string_1, const char* string_2, int cmp_till);
int Strncmpi(const char* string_1, const char* string_2, int cmp_till);
void Strncat(char* destination, const char* source, int cat_till);
int AtoI(const char* string);
float AtoF(const char* string);
void reverse(char* string);
void ItoA(int n, char* out);
void FtoA(float f, char* out, int after_point_len);
int binSearch_retIndex(int* arr, int u_size, int data);
int binSearch_retStat(int* arr, int u_size, int data);
int linear_search(char* string, int u_size, int data);
int linear_search_ret_ind(char* string, int u_size, int data);
int insert(char* string, int index, int data, int u_size, int t_size);
int delete(char* string, int index, int u_size);
void memreset(char* string, int u_size);

#endif

