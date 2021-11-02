#include<stdio.h>

/**
Write a C-program to find the k-th bit of an integer n
– using only left shift and AND operators
**/
int kthbit_of_n_ls(int n, int k){
  int m = 1 << (k-1); 
  k = n & m;
  if(k != 0){
    k = 1;
    }
  return k; 
  }
  

int main() {
  
  int n, m, k;
  
  printf("enter an integer:\n");
  scanf("%d", &n);
  printf("enter bit position value you want to know:\n");
  scanf("%d", &k);
  m = kthbit_of_n_ls(n,k); 
  
  printf("%d th bit of %d is: %d\n",k,n,m);
  
  
  return 0;
  }
