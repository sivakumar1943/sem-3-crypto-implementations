#include<stdio.h>

  
int main(){  
  int i,j;
  unsigned long int a, b;
  
  unsigned char a1[4], b1[4];
 
  unsigned long s[4], p1[8]={0,0,0,0,0,0,0,0}; unsigned char p[8] = {0,0,0,0,0,0,0,0}; 
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
  
  
  printf("{");
  for(i= 0; i < 3; ++i){
    printf("%hhu, ", a1[i]);
    }
    printf("%hhu", a1[3]);  
  printf("}  X  ");
  
  printf("{");
  for(i= 0; i < 3; ++i){
    printf("%hhu, ", b1[i]);
    }
    printf("%hhu", b1[3]);  
  printf("}\n");
  
  
  
  
  //multiplication
  for(i=0; i < 4; ++i){
    for(j = 0; j < 4; ++j){
      
      s[4-j-1] = (unsigned long)(a1[4-j-1] * b1[4-i-1]);
      p1[8-j-1-i] = p1[8-j-1-i] + s[4-j-1];
      
      
      }
    
    }
   
  
  //converting the product value into base 256. And storing it in p.
  for(i=0; i < 8; ++i){
    
      
      p[8-i-1] =(unsigned char) (p1[8-i-1] & 255);
      p1[8-i-2] = p1[8-i-2] + (p1[8-i-1] >> 8);
    
      
    }
  printf("_______________________________________\n");
  //printing the product value finally units digit corresponds to p[7].
  printf("{"); 
  for(i= 0; i < 7; ++i){
    printf("%hhu, ", p[i]);
    }
    printf("%hhu", p[7]);  
  printf("}\n");
  
  
  
  
  
  
  return 0;
  }
