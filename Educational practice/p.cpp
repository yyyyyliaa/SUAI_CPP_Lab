#include <iostream>

using namespace std;

int main()
{
int a[30][30], n, m, k = 8;

for (n = 0; n < 30; n++) {
a[0][n] = 1; a[n][0] = 1;
}

for (n = 1; n < k; n++)
        for (m = 1; m < k; m++)
a[n][m] = a[n-1][m] + a[n][m-1];

for (n = 0; n < k; n++) {
for (m = 0; m <= n; m++)
printf("%d", a[m][n-m]);
return 0;
}

