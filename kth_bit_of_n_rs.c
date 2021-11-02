#include<stdio.h>

int kthbit_of_n_rs(int n, int k){
  int m = n >> (k-1); 
  k = 1 & m;
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
  m = kthbit_of_n_rs(n,k); 
  
  printf("%d th bit of %d is: %d\n",k,n,m);
  
  
  return 0;
  }  
