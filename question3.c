#include<stdio.h>
#include<stdlib.h>

/**********************************************************************************************************************/
/* 
convertC2I is a function which takes a char pointer A as input and aan integer n which is size of the Array A

A is in base 256

gives an output C another array

C is the representation of A in base 2^26.

So convertC2I converts base 256 numbers to base 2^26 numbers.  
*/
/**************************************************************************************************************************/
/**************************************************************************************************************************/
long int* convertC2I(unsigned char *A, int n){
  int *B;
  int m, l;
  
 
  m = n*8;
  
  
  /* 
  A[0] represents units place, A[n-1] represents 256^n-1 digits place
  
  */
  
  // converting given base 256 number into binary
  
  B = (int*) malloc(m*sizeof(int));
  for(int i =0; i<n; ++i){
   int t = A[i];
   for(int k=0; k<8; ++k){
     
     int r = (t & (1 << k))/(1<< k);
      
     B[(8*i)+k] = r;
      
     }
   }
   
  
  /* 
  After converting into binary 
  B[0] is lsb and B[m-1] is msb
  */
  
  
  
  /* 
  converting binary B into base 2^26 C
  */ 
  
  int k = m % 26;
  if(k != 0){
    l = ((m - k)/26) + 1;
    }
  else l = m/26;
  
  
   long int *C;
   C = (long int*) malloc(l*sizeof(long int));
   if(k!= 0){
     for(int i=0; i<(l-1); ++i){
     int t =0;
     for(int j=0; j<26; ++j){
       t = t + (B[(26*i)+j] << j); 
       }
     C[i] = t;  
     }
     int t =0;
     for(int i =0; i<k; ++i){
       t = t+ (B[(26*(l-1))+i] << i);
       }
     C[l-1] = t;  
     }
   else{
     for(int i=0; i<l; ++i){
     int t =0;
     for(int j=0; j<26; ++j){
       t = t + (B[(26*i)+j] << j); 
       }
     C[i] = t;  
     }
     }
     
    /* 
    After converting C[0] is units digit and C[l-1] is 2^(l-1) place digit in base 2^26.
    */ 
     free(B);
     
  return C;   
  }
/***************************************************************************************************************************************/
/* 
convertI2C is a function which takes a char pointer A as input and an integer n which is size of the Array A

A is in base 2^26

gives an output C another array

C is the representation of A in base 256.

So convertI2C converts base 2^26 numbers to base 256 numbers.  
*/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
unsigned char* convertI2C(long int *A, int n){
       
       int m, l;
  
       m = 26*n;
        
       /* 
  A[0] represents units place, A[n-1] represents 2^((n-1)*26) digits place
  
  */   
       unsigned char* B;
       B = (unsigned char*) malloc(m*sizeof(unsigned char));
       
       for(int i =0; i<n; ++i){
   	 long int t = A[i];
   	 for(int k=0; k<26; ++k){
     
     	   int r = (t &(1<<k))/(1<<k);
      
     	   B[(26*i)+k] = r;
     	   
     	   }
   	 }
       
       /* 
  After converting into binary 
  B[0] is lsb and B[m-1] is msb
  */
  
  
  
   
  //converting binary B into base 2^26 C
  
       
       int k = m % 8;
  	if(k != 0){
    	  l = ((m - k)/8) + 1;
    		}
  	else l = m/8;
  	
  	unsigned char *C;
   	C = (unsigned char*) malloc(l*sizeof(unsigned char));
   
   	if(k!= 0){
     	  for(int i=0; i<(l-1); ++i){
     	    int t =0;
     	    for(int j=0; j<8; ++j){
       	t = t + (B[(8*i)+j] << j); 
       	}
     	    C[i] = t;  
     	    }
     
     	  int t =0;
     	  for(int i =0; i<k; ++i){
            t = t+ (B[(8*(l-1))+i] << i);
           }
     	   C[l-1] = t;  
           }
        else{
          for(int i=0; i<l; ++i){
             int t =0;
     	     for(int j=0; j<8; ++j){
       	t = t + (B[(8*i)+j] << j); 
       	}
     	     C[i] = t;  
             }
     	    }
  	/* 
    After converting C[0] is units digit and C[l-1] is 2^(l-1) place digit in base 2^26.
    */ 
     free(B);
     
  return C;
       
  }
/*************************************************************************************************************************************/  
/*
Input two numbers A and B in base 2^26 form
then add function will store their sum in C
which is again a base 2^26 number
*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
long int* add(long int* C, long int* A, long int* B, int n){
        int t = (1 << 26) -1;
        
        long int* C1;
        C1 = (long int*) malloc(n*sizeof(long int));
        //adding as poynomilas first
        for(int i=0; i<n; ++i){
          C1[i] = A[i] + B[i];
          }
          
        //now taking care of the carrybits
        
        for(int i=0; i<(n-1);++i){
          C[i] = C1[i] & t;
          C1[i+1] = C1[i+1] + (C1[i] >> 26);
          C[i+1] = C1[i+1];
          }  
        return C;
        }  
/**************************************************************************************************************************************/



/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
long int* mult(long int* C, long int*A, long int* B){
       
       int n = 5, m=10, t=((1<<26) - 1);
       
       long int C_00_1 = A[0]*B[0];
       long int C_02_1 = A[1]*B[1];
       long int C_01_1 = ((A[0] + A[1])*(B[0]+B[1])) - C_00_1 - C_02_1;
       
       long int *C_0_1, *C_2_1, *C_1_1, *C_2_11;
       C_0_1 = (long int*) malloc(m*sizeof(long int));
       C_2_1 = (long int*) malloc(m*sizeof(long int));
       C_1_1 = (long int*) malloc(m*sizeof(long int));
       C_2_11 = (long int*) malloc(m*sizeof(long int));
       
       for(int i =0; i<m; ++i){
         C_0_1[i] = 0;
         C_2_1[i] = 0;
         C_2_11[i] = 0;
         C_1_1[i] = 0;
         }
       C_0_1[0] = C_00_1;
       C_0_1[1] = C_01_1;
       C_0_1[2] = C_02_1;
       
       long int C_20_2 = A[2]*B[2];
       long int C_220_2 = A[3]*B[3];
       long int C_222_2 = A[4]*B[4];
       long int C_221_2 = ((A[3] + A[4])*(B[3]+B[4])) - C_220_2 - C_222_2;
       
       
       long int D_0 = (A[2]+A[3])*(B[2]+B[3]);
       long int D_2 = A[4]*B[4];
       long int D_1 = ((A[2]+A[3]+A[4])*(B[2]+B[3]+B[4])) - D_0 - D_2;
       
       C_2_1[2] = C_20_2;
       C_2_1[3] = D_0 - C_20_2 - C_220_2;
       C_2_1[4] = D_1 - C_221_2 + C_220_2;
       C_2_1[5] = D_2 - C_222_2 + C_221_2;
       C_2_1[6] = C_222_2;
       
       //Now C_2_11 = C_0_1 + C_2_1
       
       for(int i =0; i<m; ++i){
         C_2_11[i] = C_0_1[i] + C_2_1[i];
         }
       
       //now for C_1_1
       
       long int E_00 = A[0]*B[0];
       long int E_02 = (A[1]+A[2])*(B[1]+B[2]);
       long int E_01 = ((A[0]+A[1]+A[2])*(B[0]+B[1]+B[2])) - E_00 - E_02;
       
       long int E_20 = A[3]*B[3];
       long int E_22 = A[4]*B[4];
       long int E_21 = ((A[3]+A[4])*(B[3]+B[4]))-E_20-E_22;
       
       long int H_0 = A[0]*B[0];
       long int H_20 = (A[1]+A[2]+A[3])*(B[1]+B[2]+B[3]);
       long int H_22 = A[4]*B[4];
       long int H_21 = (A[1]+A[2]+A[3]+A[4])*(B[1]+B[2]+B[3]+B[4]);
       
       long int K_0 = A[0]+A[1]+A[2]+A[3];
       long int K_1 = A[4];
       long int L_0 = B[0]+B[1]+B[2]+B[3];
       long int L_1 = B[4];
       
       long int H_10 = K_0*L_0;
       long int H_12 = A[4]*B[4];
       long int H_11 = ((K_0+K_1)*(L_0+L_1)) - H_10-H_12;
       
       long int *E;
       E = (long int*) malloc(m*sizeof(long int));
       for(int i=0; i<m; ++i){
         E[i] = 0;
         }
       
       E[0] = E_00;
       E[1] = E_01-H_20;
       E[2] = E_02+H_10-H_21;
       E[3] = H_11+H_20-H_22;
       E[4] = H_12+H_21+E_20;
       E[5] = H_22+E_21;
       E[6] = E_22;
       
       //C_1_1 = E - C_2_11
       for(int i=0; i<m; ++i){
         C_1_1[i] = E[i] - C_2_11[i];
         }
       
       //C1 = C_0_1 + C_1_1*r + C_2_1*r*r  
       
       //C_1_1r = C_1_1*r; C_2_1rr = C_2_1*r*r;
       
       long int *C_1_1r, *C_2_1rr, *C1;
       C_1_1r = (long int*) malloc(m*sizeof(long int));
       C_2_1rr = (long int*) malloc(m*sizeof(long int));  
       C1 = (long int*) malloc(m*sizeof(long int));
       
       for(int i=0; i<(m-1); ++i){
         C_1_1r[i+1] = C_1_1[i];
         }
       for(int i=0; i<(m-2); ++i){
         C_2_1rr[i+2] = C_2_1[i];
         }  
       for(int i=0; i<m; ++i){
         C1[i] = C_0_1[i] + C_1_1r[i] + C_2_1rr[i];
         }
       
       //taking care of the bits
       for(int i=0; i<(m-1);++i){
          C[i] = C1[i] & t;
          C1[i+1] = C1[i+1] + (C1[i] >> 26);
          C[i+1] = C1[i+1];
          }       
       
       
       return C;
       }  
  
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
int main(){
  unsigned char A[16], B[16];
  int i, b= 1<<8;
  unsigned int seed;  
printf("enter seed value:\n");
scanf("%u", &seed);

srand(seed);
for(i =0; i < 15; ++i){
  int s,t;
  s = abs(rand() % b);
  t = abs(rand()% b);
  
  A[15-i-1] = s ;
  B[15-i-1] = t;
   
  }
  int s,t;
  t = abs(rand()%(b/2));
  
  s = abs(rand()%(b/2));
  A[15] = s; B[15] = t;
for(i =0; i<16; ++i){
  printf("%hhu ", A[16-i-1]);
  }
printf("\n");


for(i =0; i<16; ++i){
  printf("%hhu ", B[16-i-1]);
  }
printf("\n");

long int *A1, *B1, *C1, *C;
A1 = (long int*) malloc(5*sizeof(long int));
A1=convertC2I(A, 16);

B1 = (long int*) malloc(5*sizeof(long int));
B1=convertC2I(B, 16);

C1 = (long int*) malloc(5*sizeof(long int));

C = (long int*) malloc(5*sizeof(long int));

C = add(C1, A1, B1, 5);

unsigned char* E, *F;
E = (unsigned char*) malloc(16*sizeof(unsigned char));
F = (unsigned char*) malloc(33*sizeof(unsigned char));

//E = convertI2C(D, 5);

printf("addition:\n");
for(int i =0; i<5; ++i){
  printf("%ld ", A1[5-i-1]);
 }
 printf("\n");
 
 for(int i =0; i<5; ++i){
  printf("%ld ", B1[5-i-1]);
 }
 printf("\n");



for(int i =0; i<5; ++i){
  printf("%ld ", C[5-i-1]);
 }
 printf("\n");
 
 printf("multiplication:\n");
 long int *D, *D1;
 D = (long int*)malloc(10*sizeof(long int));
 D1 = (long int*)malloc(10*sizeof(long int));
 D=mult(D1, A1, B1);
 for(int i =0; i<10; ++i){
  printf("%ld ", D[10-i-1]);
 }
 printf("\n");
 
 printf("sum in base 256:\n");
 E=convertI2C(C,5);
 for(int i =0; i<16; ++i){
  printf("%d ", E[16-i-1]);
 }
 printf("\n");
 
 printf("product in base 256:\n");
 F=convertI2C(D,10);
  for(int i =0; i<33; ++i){
  printf("%hhu ", F[33-i-1]);
 }
 printf("\n");
  return 0;
  }
