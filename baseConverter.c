#include<stdio.h>

/*
	BINARY[BASE-2], DECIMAL[BASE-10], HEXADECIMAL[BASE-16], OCTAL[BASE-8]

   CONVERSIONS :-

	BINARY TO DECIMAL
	BINARY TO HEXADECIMAL
	BINARY TO OCTAL

	DECIMAL TO BINARY
	DECIMAL TO HEXADECIMAL
	DECIMAL TO OCTAL

	HEXADECIMAL TO BINARY
	HEXADECIMAL TO DECIMAL
	HEXADECIMAL TO OCTAL

	OCTAL TO BINARY
	OCTAL TO DECIMAL
	OCTAL TO HEXADECIMAL
*/
int number;
char hexa[100];

int choice_input();
void value_input(int);
int power(int, int);

int binToDec(int);
void binToHex(int);
void binToOct(int);
void decToBin(int);
void decToHex(int);
void decToOct(int);
int hexToDec(char*);
void hexToBin(char*);
void hexToOct(char*);
int octToDec(int);
void octToBin(int);
void octToHex(int);


int choice_input(){

   int choice;

	printf("\nWhich base do you want it to convert to? \n");
	printf("\n1. BINARY TO DECIMAL\n2. BINARY TO HEXADECIMAL\n3. BINARY TO OCTAL\n");
   printf("\n4. DECIMAL TO BINARY\n5. DECIMAL TO HEXADECIMAL\n6. DECIMAL TO OCTAL\n");
   printf("\n7. HEXADECIMAL TO DECIMAL\n8. HEXADECIMAL TO BINARY\n9. HEXADECIMAL TO OCTAL\n");
   printf("\n10. OCTAL TO DECIMAL\n11. OCTAL TO BINARY\n12. OCTAL TO HEXADECIMAL\n");
	printf("Enter you Choice: ");
	scanf("%d", &choice);

   return choice;
}

void value_input(int choice){

   if((choice>=1 && choice<=3)){
      printf("Enter the Binary: ");
	   scanf("%d", &number);
   } else if((choice>=4 && choice<=6)){
      printf("Enter the Decimal: ");
	   scanf("%d", &number);
   } else if((choice>=7 && choice<=9)){
      printf("Enter the Hexadecimal: ");
      scanf("%100s", hexa);
      // fgets(hexa, 100, stdin);
   } else if((choice>=10 && choice<=12)){
      printf("Enter the Octal: ");
	   scanf("%d", &number);
   }
}

int power(int base, int p){ //this user defined function takes a number and power vaue and returns base^p
   int result = 1;
   if(p){ //if the value is not 0, it runs the statement below
      for(int i = p; i > 0; i--){ //i i set to p and condition checks if i is greater than 1 if yes...it runs the statement
      // in the for block which is base is multiplied by base until i is equal 1 
         result *= base;
      }
      return result;
   }
   else{ //if the value of p is 0
      return result; //returns 1
   }
}

int binToDec(int n){ // function to convert binary value to decimal value

	int binary = n, dec = 0, bitShiftValue = 1; //binary variable is set to the binary value provided by the user and dec to 0, bitshiftValue to 11

	while(binary){ //checks if binary is not 0 [can also be written as binary != 0]
      
      int remain = binary % 10; // rem is set to the remainder after binary is divided by 10
      dec += bitShiftValue*remain; // decimal value is incremented with the remainder and the bit value the remainder is on
      bitShiftValue *= 2; //bit is shifted to next bit so it can do further calculations
      binary = binary/10; // binary is divided by 10 to get the quotient which can further used by while loop to find the decimal
      // until the binary is 0 
  	}
   return dec; //finally return the decimal value
}

void binToHex(int n){ //function to convert binary value to hexadecimal value
   
   int binary = n; // binary is set to binary value
   int dec = binToDec(binary); //dec variable stores the return value of binToDec function which converts bin value to dec value and returns it
   decToHex(dec); //finally we call the decToHex function which converts the given decimal value to hex value and prints it

}

void binToOct(int n){ //function to convert binary value to Octal value
   
   int binary = n; // binary is set to binary value
   int dec = binToDec(binary); //dec variable stores the return value of binToDec function which converts bin value to dec value and returns it
   decToOct(dec); //finally we call the decToOct function which converts the given decimal value to octal value and prints it
   
}

void decToBin(int n){ //function to convert decimal value to binary value
   
   int dec = n, binary[100]; // dec variable is set to user provided decimal value, declaring an integer array of 100 size.
   int i = 0; // i set to 0
   while(dec){ // while dec is not 0 [can be written as dec != 0]

      int remain = dec % 2; //remain variable is set to the remainder when decimal is divided by 2 [possible outcomes are only 1 and 0]
      binary[i++] = remain; //binary array then stores the remainder.
      dec = dec/2; //dec is divided by 2 and the quotient is set to dec variable which will further used by while loop.
   }
   printf("0b");
   for(int j = i-1; j >= 0; j--) //in for loop j is set to value of i-1 and checks if j greater than or equal 0, if yes
   // it prints the elements of binary until the j variable is 0 [this gives the binary value]
      printf("%d", binary[j]);
}

void decToHex(int n){ //this function converts decimal value to hexadecimal value
 
   int dec = n; //dec variable is set to user provided decimal value
   int remain, j, i = 0; //declaring remain and j variable as integers and initializing i to 0
   char hex[100]; //declaring character array named hex of size 100
 
   while(dec){ // while dec is not 0 [can be written as dec != 0]

      remain = dec % 16; //remain variable is set to the remainder after decimal is divided by 16
      if (remain < 10) //checks if remain is less than 10, if yes current element of hex array is set to remain + 48
         hex[i++] = 48 + remain;
      else //if remain is greater than or equals 10, current element of hex array is set to remain + 55
         hex[i++] = 55 + remain;
      dec = dec/ 16; //dec is divided by 16 and the quotient is set to dec variable which will further used by while loop.
   }
   hex[i] = '\0'; //as hex array is a string, we need to give a null character at the end of string.
    
   printf("0x");
   for (j = i-1; j >= 0; j--) //loops in reverse and prints the elements of hex 
      printf("%c", hex[j]);
}

void decToOct(int n){ //this fucntion converts decimal value to octal value

   int dec = n; //dec variable is set to user provided decimal value
   int remain, count = 0, i = 0, oct[100];

   while(dec){ // while dec is not 0

      remain = dec % 8; //remain will be set to remainder after diving dec by 8
      oct[i++] = remain; //oct array will store the remain value with incrementation of i.
      count++; //count is incremented (which will used later to reverse print the array to get octal value)
      dec = dec/8; // dec will be set to quotient after dividing dec by 8
   }
 
   printf("0o");
   for (int j = count-1; j >= 0; j--) //looping the array oct in reverse to print it's content
      printf("%d", oct[j]);
}

int hexToDec(char* h){ // this function converts hex value to dec value

   auto int decimal(int,int,int); //using auto keyword to use a nested function
   int decimal(int bit, int count, int minValue){ //this nested function converts the single hex
   // character to it's decimal value and returns it.

      int num = 0, hexPow = 0;
      hexPow = power(16, bit); //hexPow is set to 16^bit
      num += (*(h+count)-minValue)*hexPow; //num is set to the decimal value of the hex char 
      return num; //finally returning the num
   } 
   int dec = 0, bitshift = 0, cnt = 0;
   // for(int i = 0; *(h+i) != '\0'; i++)
   //    cnt++;
   //    [OR] 
   // for(int i = 0; h[i] != '\0'; i++)
   //    cnt++;
   //    [OR]
   char* ptr = h; //pointer to char variable ptr is set to the first element of the given array
   while(*ptr != '\0'){ //checks if value at the pointer is not null
      cnt++; //cnt is incremented
      ptr++; //pointer is incremented to check the if the string is ended or not
   }
   while(cnt >= 0){ // while cnt is greater than -1
      --cnt; //cnt is decremented
      //Refer ascii table to understand more precisely.
      if((*(h+cnt) >=97 && *(h+cnt) <=102)) // checks if the value at the given index of the array is between 97 and 102
      //between decimal value 97 and 102, the char value a-f is located [lowercase]
         dec += decimal(bitshift, cnt, 87); //if yes dec is incremented to value returned by decimal function
      else if((*(h+cnt) >=65 && *(h+cnt) <=70)) // checks if the value at the given index of the array is between 65 and 70
      //between decimal value 65 and 70, the char value A-F is located [uppercase]
         dec += decimal(bitshift, cnt, 55); //if yes dec is incremented to value returned by decimal function
      else if((*(h+cnt) >=48 && *(h+cnt) <=57)) // checks if the value at the given index of the array is between 48 and 57
      //between decimal value 48 and 57, the char value 0-9 is located
         dec += decimal(bitshift, cnt, 48); //if yes dec is incremented to value returned by decimal function
      
      bitshift++; //bitshift is incremented, the present bit is passed to decimal function for 
      //calculating the decimal
   }
   return dec;
}
   
void hexToBin(char* h){ //this function converts hex value to bin value
   int dec = hexToDec(h); //dec is set to value returned by hexToDec function
   decToBin(dec); // calling decToBin function which converts the decimal to binary value and prints it.
}

void hexToOct(char* h){ //this function converts hex value to octal value
   int dec = hexToDec(h); //dec is set to value returned by hexToDec function
   decToOct(dec); // calling decToOct function which converts the decimal to octal value and prints it.
}

int octToDec(int n){//this function converts octal value to dec value
   int dec = 0, oct = n, remain, count = 0, octPow;

   while(oct){ //while oct is not 0
      count++; //increment count
      oct = oct/10; //oct is set to the quotient after diving oct by 10 
   }
   oct = n; //oct is again set to user given oct value
   for(int i = 0; i <= count; i++){//loops until i is count
      remain = oct % 10; //remain is set to the remainder after dividing oct by 10
      octPow = power(8, i); //octPow is set to value of 8^i
      dec += remain * octPow; //dec is incremented with the product of remain and octPow
      oct = oct/10; //oct is set to the quotient after dividing oct by 10
   }
   return dec;

}

void octToBin(int n){ //this function converts oct value to binary value
   
   int dec = octToDec(n); //dec is set to the value returned by ocToDec function
   decToBin(dec); //converts dec value to binary value and prints it.
}

void octToHex(int n){ //this function converts oct value to hex value
   
   int dec = octToDec(n); //dec is set to the value returned by ocToDec function
   decToHex(dec); //converts dec value to hex value and prints it.
}

int main(){

   int choice = choice_input();
   value_input(choice);
   switch(choice){

      case 1:
         printf("0d%d",binToDec(number));
         break;
      case 2:
         binToHex(number);
         break;
      case 3:
         binToOct(number);
         break;
      case 4:
         decToBin(number);
         break;
      case 5:
         decToHex(number);
         break;
      case 6:
         decToOct(number);
         break;
      case 7:
         printf("0d%d", hexToDec(hexa));
         break;
      case 8:
         hexToBin(hexa);
         break;
      case 9:
         hexToOct(hexa);
         break;
      case 10:
         printf("0d%d",octToDec(number));
         break;
      case 11:
         octToBin(number);
         break;
      case 12:
         octToHex(number);
         break;
      default:
         printf("Something went wrong!");      
   }

	return 0;
}