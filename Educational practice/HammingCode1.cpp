#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define N 5
#define D 3

unsigned char count_ones(unsigned char n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

int main() {
  int M = 0; 
  int size = pow(2,N);
  int mark[32] = {0};
  int CodeBook[32] = {0};
  int zero;

  do{
    zero = -1;
    for(int i = CodeBook[M]; i<size; i++){
      if (mark[i]==0){
        zero = i;
        break;
      }
    }
    if (zero!=-1){
      CodeBook[M] = zero;
      mark[zero] = 2; // Отметим взятое слово в массиве пометок.
      M++;
      for(int i = CodeBook[M-1]; i< size; i++){
        if(mark[i] == 0 && (count_ones(i^CodeBook[M-1])<D)){
          mark[i] = 1;
        }
      printf("%d ", mark[i]);
      }
      cout<<endl;
    }
  }while(zero!=-1);
   
   
  for (int i = 0; i<size; i++){
    if ((CodeBook[i]!=0)||(i==0)) cout<<CodeBook[i]<<", ";
  }



    return 0;
}