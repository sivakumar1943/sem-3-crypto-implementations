#include<stdio.h>

int main(){
  int i, j;
  unsigned long int a, b;
  
  unsigned char a1[4], b1[4], s[5];
  
  unsigned int s1[4];
  
  printf("enter a positive integer in range [0, 4,294,967,295]:\n");
  scanf("%lu", &a);
  
  printf("enter a positive integer in range [0, 4,294,967,295]:\n");
  scanf("%lu", &b);
  
  for(i = 0; i < 4; ++i){
    a1[4 - i - 1] = a & 255;
    a = a >> 8;
    b1[4 - i - 1] = b & 255;
    b = b >> 8;
    
    }
    
  printf("   {");
  for(i= 0; i < 3; ++i){
    printf("%hhu, ", a1[i]);
    }
    printf("%hhu", a1[3]);  
  printf("}\n");
  
  printf("   {");
  for(i= 0; i < 3; ++i){
    printf("%hhu, ", b1[i]);
    }  
    printf("%hhu", b1[3]);
  printf("}\n");
  
  //addition of two numbers as polynomials first
  for(i = 0; i < 4; ++i){
    s1[i] = a1[i] + b1[i];
    }
  
  
  //taking care of the carry bits now
  
  
  for(i = 0; i < 5; ++i){
    if( i < 4){
      s[5-i-1] = s1[4-i-1] & 255;
      s1[4-i-2] = (s1[4-i -1] >> 8)+s1[4-i-2];
      s[5-i-2] = s1[4-i-2]; 
      }
      
    }
   printf("______________________\n");  
   printf("{");
   for(i = 0; i < 4; ++i){
    printf("%hhu, ", s[i]); 
    } 
   printf("%hhu", s[4]); 
    
   printf("}\n");
  return 0;
  }
