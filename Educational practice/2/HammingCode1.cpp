#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

//#define N 5
//#define D 3

unsigned long long count_ones(unsigned long long n)
{
  unsigned long long w = 0;
  while (n > 0)
  {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

chrono::duration<float> hammingCode(int D, int N, unsigned long long &count){
  size_t M = 0;
  unsigned long long size = pow(2, N);
  unsigned long long *mark = (unsigned long long *)malloc(sizeof(unsigned long long) * size);
  unsigned long long *CodeBook = (unsigned long long *)malloc(sizeof(unsigned long long) * size);
  unsigned long long zero;

  auto t1 = chrono::high_resolution_clock::now();
  do{
    zero = -1;
    for (unsigned long long i = CodeBook[M]; i < size; i++){
      if (mark[i] == 0){
        zero = i;
        break;
      }
    }
    if (zero != -1){
      CodeBook[M] = zero;
      mark[zero] = 2; // Отметим взятое слово в массиве пометок.
      M++;
      for (unsigned long long i = CodeBook[M - 1] + 1; i < size; i++)
      {
        if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
        {
          mark[i] = 1;
        }
        //cout << mark[i] << " ";
      }
      // cout << endl;
    }

  } while (zero != -1);

  auto t2 = chrono::high_resolution_clock::now();
  chrono::duration<float> duration = t2 - t1;

  // for (unsigned long long i = 0; i<size; i++){
  //   if ((CodeBook[i]!=0)||(i==0)) cout<<CodeBook[i]<<", ";
  // }

  // cout << endl;

  free(mark);
  free(CodeBook);

  count = M;

  return duration;
}

int main(){

  for (int D = 1; D < 19; D++){
    cout<<"d: "<<D<<endl;
    for (int N = 1; N < 17; N++){
      unsigned long long count = 0;
      auto duration = hammingCode(D, N, count);
      cout << "N: " << N << " Time: " << duration.count() << " count: " << count << endl;
    }
  }

  return 0;
}