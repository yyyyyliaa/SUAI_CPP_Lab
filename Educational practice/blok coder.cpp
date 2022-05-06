#include <stdio.h>

int kniga[4] = {0x00, 0x0D, 0x16, 0x1B};

int koder(int m){
    return kniga[m];
}

int main(){
    int m = 1;
    int a = koder(m);
    printf("%d", a);

    return 0;

}




// int bin2dec(char* arr, int n){
//     int num =0;
//     for(int i =n-1; i>-1; i--){
//         if (arr[i] =='1'){
//             num+=pow(2,i); 
//         }
//     }
//     return num;
// }

// int main(){
//     // char a =  0x1B;
//     // printf("%c", a);

//     int arr[4] = {0x00,0x0D,0x16,0x1B};

//     char k[] = {11};
//     int b = bin2dec(k, 2);
//     printf("%d", arr[b]);


//     return 0;

// }