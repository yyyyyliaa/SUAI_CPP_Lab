#include <stdio.h>

int function(long long int temp)
{
	int result = 1;
	for (int i = 1; i <= temp; i++) result *= i;
	return result;
}

int func(long long int n) {
	int count = 0;
	while (n != 0) {
		// n = n >> 1;
		// count++;
		count++;
		n &= n - 1;
	}
	return count - 1;
}

int binCoeff(long long int n, long long int k){

	long long int result = 1;

	if (n>k) result = function(n) / (function(k) * function(n-k));
    else if (k==0||n==k) result = 1;
    else if (n==0) result = 0;

	return result;
	
}

int main() { 

long long int n = 29;
	// int C, m, n;
	// printf_s("Vvedite ''n'' (celoe):\n");
	// scanf_s("%d", &n);
	// int count = func(n);

	for (int i = 0; i <= n; i++) {
		int C = binCoeff(n, i);
		printf_s(" %d- %d\n",i, C);
	}
	return 0;
}

