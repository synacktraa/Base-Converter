#ifndef UTILS_H /* Include guard */
#define UTILS_H

//Function declarations
int power(int base, int exp);
int isLower(int ch);
int isDigit(int n);
int Strlen(const char* string);
int Strcmp(const char* string_1, const char* string_2);
int AtoI(const char* string);
void reverse(char* string);
int delete(char* string, int index, int u_size);
void memreset(char* string, int u_size);

#endif




