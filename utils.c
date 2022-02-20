
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

int isDigit(int ch){
   if(ch >= 48 && ch <= 57)
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

int Strncmp(const char* string1, const char* string2, int size){

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

int Strncmpi(const char* string1, const char* string2, int size){

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

void Strncat(char* string1, const char* string2, int size){

   int total_size = Strlen(string1)+Strlen(string2);
   int i, j;

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

int AtoI(const char* str){ //changes number stored in a string to integer
   int res = 0;
   char *ptr = (char*)str;

   while (*ptr != '\0') {
      if (isDigit(*ptr)) {
         // Integer part
         res *= 10; // Shift the previous digits to the left
         res += *ptr - 48; // Add the new one

      }
      ptr++;
   }
   return res;
}


float AtoF(const char* str) {
   
   float res = 0.0F;
   char *ptr = (char*)str;
   int afterDecimalPoint = 0;
   float div = 1; // Divider to place digits after the deciaml point

   while (*ptr != '\0') {
      if (isDigit(*ptr)) {
         // Integer part
         if (!afterDecimalPoint) {
            res *= 10; // Shift the previous digits to the left
            res += *ptr - 48; // Add the new one
         }
         // Decimal part
         else {
            div *= 10;
            res += (float)(*ptr - 48) / div;
         }
      }
      else if (*ptr == '.')
         afterDecimalPoint = 1;
      else
         break;
      ptr++;
   }
   return res;
}

void reverse(char*str){
   
   int len = 0, temp;
   char*ptr = str;
   while(*ptr != '\0'){
      len++;
      ptr++;
   }
   int i = 0, j = len-1;
   while(i < j){
      temp  = *(str+i);
      *(str+i) = *(str+j);
      *(str+j) = temp;
      ++i;
      --j;
   }
}

void ItoA(int dec, char*str){
   int i = 0;
   if(dec == 0){str[i++] = 48;}
   else{
   while(dec){
         str[i++] = (dec%10) + 48;
         dec /= 10;
      }
   *(str+i) = '\0';
   reverse(str);
   }
}


void FtoA(float dec, char* str, int cnt){
   
   float diff = 0.0F;
   int realdec = (int)dec;
   int i = 0, counter = 0, j;
   char after_point_value[20];

   if(dec == realdec) {ItoA(realdec, str);}
   else{
      ItoA(realdec, str);
      while(*(str+i) != '\0'){i++;}

      *(str+(i++)) = '.';
      *(str+i) = '\0';

      diff = dec - realdec;

      while((int)diff != diff){
         diff *= 10;
      }
      
      ItoA(diff, after_point_value);

      if(after_point_value[cnt]-48 == 9)
         after_point_value[cnt-1] += 1;
      for(i, j = 0; j < cnt; j++){
         str[i++] = after_point_value[j];
      }
      str[i] = '\0';
   }
}

int binSearch_retIndex(char*data, int size, int element){

    int low, high, mid;
    low = 0;
    high = size-1;
    while(low < high){
        if(element == data[low]){
           return low;
            break;
        } else if(element == data[high]){
           return high;
            break;
        } else {
            mid = (low+high)/2;
            if (element == data[mid]){
               return mid;
                break;
            } else if (element < data[mid]){
                high = mid-1;
            } else if (element > data[mid]){
                low = mid+1;
            }
        }
    }

}
int binSearch_retStat(char*data, int size, int element){

    int low, high, mid;
    low = 0;
    high = size-1;
    while(low <= high){
        
      mid = (low+high)/2;
      if (element == data[mid]){
         return 1;
            break;
      } else if (element < data[mid]){
            high = mid-1;
      } else if (element > data[mid]){
            low = mid+1;
      }

    }

}

int linear_search(char*data, int size, int element){

   int i;
   for(i = 0; i < size; i++){
      if(*(data+i) == element){
         return 1;
         break;
      }
   } 
   return 0;
}

int linear_search_ret_ind(char*data, int size, int element){

   int i;
   for(i = 0; i < size; i++){
      if(*(data+i) == element){
         return i;
         break;
      }
   } 
   return -1;
}

int insert(char*data, int index, int element, int uSize, int tSize){

    if(uSize >= tSize)
        return -1;
    for(int i = uSize-1; i >= index; i--)
        *(data+i+1) = *(data+i);
    
    *(data+index) = element;
    uSize++;
    return 0;
}

int delete(char*data, int index, int length){

    int i;
    for (i = index; i < (length)-1; i++)
    {
        *(data+i) = *(data+i+1);
    }
    *(data+i) = '\0';
    length--;
    return length;

}

void Memset(char*data, int val, int len){
   
   for(int i = 0; i < len; i++){
      *(data+i) = val;
   }
}

