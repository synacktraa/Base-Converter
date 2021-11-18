#include <stddef.h>

int isLower(int ch){
   if(ch >= 97 && ch <= 122)
      return 1;
   return 0 ;
}

int isUpper(int ch){
   if(ch >= 65 && ch <= 90)
      return 1;
   return 0;
}

int toLower(int ch){

   int lower;
   if(ch >= 65 && ch <= 90){
      lower = ch+32;
   } else {
      lower = ch;
   }
   return lower;
}

int toUpper(int ch){

   int upper;
   if(ch >= 97 && ch <= 122){
      upper = ch-32;
   } else {
      upper = ch;
   }
   return upper;
}

char *Strcpy(char* destination, char* source){
   
   int i;
   for(i = 0; *(source+i) != '\0'; i++)
      *(destination+i) = *(source+i);

   *(destination+i) = '\0';
   
   return destination;
   
}

int Strlen(const char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}

int Strcmp(const char* string1, const char* string2){

   int len_string1 = Strlen(string1);
   int len_string2 = Strlen(string2);

   if((len_string1 - len_string2) == 0){
      for(int i = 0; i < len_string1; i++){
         if(*(string1+i) == *(string2+i))
            len_string2--;         
      }
      if(len_string2 == 0)
         return 0;
      else
         return 1;
   } else{
      return 1;
      }
}

int Strcmpi(const char* string1, const char* string2){

   int len_string1 = Strlen(string1);
   int len_string2 = Strlen(string2);
   
   if((len_string1 - len_string2) == 0){
      for(int i = 0; i < len_string1; i++){
         if(toLower(*(string1+i)) == toLower(*(string2+i)))
            len_string2--;         
      }
      if(len_string2 == 0)
         return 0;
      else
         return 1;
   } else{
      return 1;
      }
}

int Strncmp(const char* string1, const char* string2, size_t size){

   int check = size;
   for(int i = 0; i < size; i++){
      if(*(string1+i) == *(string2+i))
         check--;  
   }
   if(!check)
      return 0;
   else  
      return 1;
}

int Strncmpi(const char* string1, const char* string2, size_t size){

   int check = size;
   for(int i = 0; i < size; i++){
      if(toLower(*(string1+i)) == toLower(*(string2+i)))
         check--;  
   }
   if(!check)
      return 0;
   else  
      return 1;
}

void Strncat(char* string1, const char* string2, size_t size){

   int total_size = Strlen(string1)+Strlen(string2);
   size_t i, j;

   if (total_size < size){
      for(i = Strlen(string1), j = 0; i < total_size && j < Strlen(string2); i++, j++){
         *(string1+i) = *(string2+j);            
      }
      *(string1+i) = '\0';

   } else{
      for(i = Strlen(string1), j = 0; i < size-1 && j < Strlen(string2); i++, j++){
         *(string1+i) = *(string2+j);   
      }
      *(string1+i) = '\0';

   }
}
