#include<stdio.h>

int kthbit_of_n_rs(int n, int k){
  int m = n >> (k-1); 
  k = 1 & m;
  if(k != 0){
    k = 1;
    }
  return k; 
  }

void binary_of_n(int n){
  int s = 8*sizeof(n), i, m;
  for(i = 0; i < s; ++i){
    m = kthbit_of_n_rs(n,s-i);
    printf("%d ",m);
    } 
  
  } 
  
int main(){
  int n;
  printf("enter an integer:\n");
  scanf("%d", &n);
  printf("binary representation of %d: \n", n);
  binary_of_n(n);
  printf("\n");
  }  
