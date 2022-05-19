#include <stdio.h>
#define N 4

float maximum(float* array) {
    float max = array[0];
    for (int i = 0; i< N; i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

int main() {
    float array[N];
    for (int i = 0; i < N; i++) scanf_s("%f", &array[i]);
    float max = maximum(array);
    printf("%f", max);
    return 0;
}