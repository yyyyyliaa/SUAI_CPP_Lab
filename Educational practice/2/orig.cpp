#include <iostream>
#include <math.h>
#include <chrono>
typedef unsigned long long uint64;
using namespace std;

uint64 count_ones(uint64 n) {
    uint64 w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}
// Исходными данными программы является N - максимальная длина кода, D - минимальное расстояние кода. 

auto f(uint64 N, uint64 D, size_t &counter) {
    size_t M = 0; // заводим счётчик числа кодовых слов в книге
    uint64 size = pow(2, N);
    uint64 *mark = (unsigned long long *)malloc(sizeof(unsigned long long) * size);
    uint64 *CodeBook = (unsigned long long *)malloc(sizeof(unsigned long long) * size);


    uint64 zero = 0;
    auto t1 = chrono::high_resolution_clock::now();
    while (1) // выолняем шаги в цикле до тех пор пока нули находятся в пределах длины: 
    {
        // -------------------------------------------------
        for (zero = 0; (mark[zero] != 0 && zero < size); zero++); // Шаг 0 выполняем поиск первой свободной последовательности в массиве mark, записываем в zero
        if (zero >= size) break; // Если Шаг 0 перебрал все элементы выходим из 
        CodeBook[M] = zero; // Шаг 1 Выберем в качестве кодового слова первую свободную последовательнотсть        
        mark[zero] = 2;
        M++;

        for (uint64 i = 0; i < size;i++)
        {
            if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
                mark[i] = 1;

            // cout << mark[i] << " ";
        }
        cout << endl;
    }

    // cout << "Answers: ";
    // for (size_t i = 0; i < M; i++) cout << CodeBook[i] << " ";
    // cout << endl << M << endl;
    counter = M;

    for (unsigned long long i = 0; i<size; i++){
        if ((CodeBook[i]!=0)||(i==0)) cout<<CodeBook[i]<<", ";
    }
    return t1;
};


int main() {
    for (int d = 1; d <= 19; d++) {
            // cout << "d: " << d << endl;
            for (size_t n = 1; n < 17; n++)
            {   
                size_t counter = 0;
                auto t1 = f(n, d, counter);
                auto t2 = chrono::high_resolution_clock::now();
                chrono::duration<float> duration = t2 - t1;
                // cout << duration.count() << endl;

                // cout << endl;
                // cout << "N: " << n << " Time: " << duration.count() << " count: " << counter << endl;
            }


    }
    
}