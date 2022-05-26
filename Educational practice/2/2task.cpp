#include <iostream>
#define N 4

int w(int number) {
    int counter = 0;
    while (number > 0) {
        counter += (number & 1);
        number = (number >> 1);
    }
    return counter;
}

int main() {
    int M[N] = {0x0, 0x0D, 0x16, 0x1B};
    int minLen = 100;
    int currLen = 20;
    int fir = 0;
    int sec = 0;

    for (int k = 0; k < N; k++) {
        int i = k + 1;
        while (i < N) {
            currLen = w(M[k] ^ M[i]);
            if (currLen < minLen) {
                minLen = currLen;
                fir = M[k];
                sec = M[i];
            }
            i++;
        }
    }
    std::cout<<"Minimum length -"<<minLen<< "our values ("<<fir<<"; "<<sec<<")"<<std::endl;
    return 0;
}

