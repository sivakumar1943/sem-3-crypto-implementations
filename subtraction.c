#include<stdio.h>

int main(){
  
  int i;
  unsigned long int a, b;
  
  unsigned char a1[4], b1[4];
  
  int s[4];
  
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
  printf("}\n");
  
  printf("{");
  for(i= 0; i < 3; ++i){
    printf("%hhu, ", b1[i]);
    }
    printf("%hhu", b1[3]);  
  printf("}\n");
  
  //subtratction of two numbers
  
 
  for(i = 0; i < 4; ++i){
    if(i < 3){
      if(a1[4-i-1] >= b1[4-i-1] ){
        s[4-i-1] = (int) (a1[4-i-1] - b1[4-i-1]);
        }
      else if(a1[4-i-2] > 0){
        s[4-i-1] =(int) (256+a1[4-i-1] - b1[4-i-1]);
        a1[4-i-2] = a1[4-i-2] - 1;
        }
      else{
        s[4-i-1] = (int)(a1[4-i-1] - b1[4-i-1]);
        }    
      }
    else{
      if(a1[0] >= b1[0]){
        s[0] = (int)(a1[0] - b1[0]);
        }
      else{
        s[0] = (int)(a1[0] - b1[0]);
        }  
      }  
    }
  printf("____________________\n");
  printf("{");
  for(i=0; i < 3; ++i){
    printf("%d, ", s[i]);
    }
    printf("%hhu", s[3]);
  printf("}\n");
  
  
  return 0;
  }
