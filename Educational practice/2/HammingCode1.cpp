#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

#define N 5
#define D 3

unsigned long long count_ones(unsigned long long n) {
  unsigned long long w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

int main() {
    
  int M = 0; 
  int size = pow(2,N);
  unsigned long long* mark = (unsigned long long*)malloc(sizeof(unsigned long long)*size);
  unsigned long long* CodeBook = (unsigned long long*)malloc(sizeof(unsigned long long)*size);
  unsigned long long zero;

  do{
    zero = -1;
    for(unsigned long long i = CodeBook[M]; i<size; i++){
      if (mark[i]==0){
        zero = i;
        break;
      }
    }
    if (zero!=-1){
      CodeBook[M] = zero;
      mark[zero] = 2; // Отметим взятое слово в массиве пометок.
      M++;
      for(unsigned long long i = CodeBook[M-1]+1; i< size; i++){
        if(mark[i] == 0 && (count_ones(i^CodeBook[M-1])<D)){
          mark[i] = 1;
        }
      cout<< mark[i]<<" ";
      }
      cout<<endl;
    }
  }while(zero!=-1);
   
   
  for (unsigned long long i = 0; i<size; i++){
    if ((CodeBook[i]!=0)||(i==0)) cout<<CodeBook[i]<<", ";
  }

  cout<<endl;

  free(mark);
  free(CodeBook);

  cout << "runtime = " << (double) clock()/CLOCKS_PER_SEC << endl;

  return 0;
}