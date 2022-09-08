#include <iostream>
using namespace std;

int main(){
    int houses[5]={1, 10, 5, 8, 2};
    int count = 5;
    int money[1]={0};

    int var = 0;

    for(int i = 0; i<count; i++){
        for(int shift = 2; i+shift<count; shift++){
                int check = i;
                money[var]+=houses[check];
        }
    }
}


// int main(){
//     cout<<"Enter coutn house: ";
//     int size;
//     cin>>size;

//     cout<<"Enter count money in houses:"<<endl;
//     int* num=(int*)malloc(sizeof(int)*size);
//     for (int i = 0; i<size; i++){
//         cin>>num[i];
//     }
//     int max = 0;
//     int index = 0;
//     for(int i = 0; i<size; i++){
//         int j = i;
//         int maxTmp = num[j];
//         int plus = 2;
//         while (j+plus<=size){
//             j+=plus;
//             maxTmp+=num[j];
//         }
//         if (maxTmp>max) {
//             max = maxTmp;
//             index = i;
//         }
//     }

//     cout<<max<<"   "<<index<<endl;
// }




// #include <iostream>
// using namespace std;

// int main(){
//     cout<<"Enter coutn house: ";
//     int size;
//     cin>>size;

//     cout<<"Enter count money in houses:"<<endl;
//     int* num=(int*)malloc(sizeof(int)*size);
//     for (int i = 0; i<size; i++){
//         cin>>num[i];
//     }
//     int max = 0;
//     int index = 0;
//     for(int i = 0; i<size; i++){
//         int j = i;
//         int maxTmp = num[j];
//         while (j+2<=size){
//             j+=2;
//             maxTmp+=num[j];
//         }
//         if (maxTmp>max) {
//             max = maxTmp;
//             index = i;
//         }
//     }

//     cout<<max<<"   "<<index<<endl;
// }