#include "modmath.h"
using namespace std;

int main() {
//  system("chcp 1251");
//  system("cls");

//  int mod;
//  int control;
//  int check = 1;
 
//  cout << "Enter the modules of these numbers" << endl;
//  while (check != 0){
//   cin >> mod;
//   check = checker(mod);
//  }
//  int c;

//  modmath math1(mod);
//  modmath math2(mod);
//  modmath math3(mod);

//  cout << "Enter numbers a and b" << endl;
//  cin >> math1;
//  cin >> math2;

//  cout << "Choose a function to operate on numbers" << endl;
//  cout << "1 for +" << endl;
//  cout << "2 for -" << endl;
//  cout << "3 for *" << endl;
//  cout << "4 for /" << endl;
//  cout << "5 for logical actions" << endl;
//  cout << "6 foe sugar" << endl;
//  cout << "7 for assignment" << endl;
//  cout << "0 for exit" << endl;

//  cin >> control;
//  while (control != 0) {

//   if (control == 1) {
//    c = math2 + math1;
//    math3.set(c);
//    cout << math3;
//   }

//   else if (control == 2) {
//    c = math2 - math1;
//    math3.set(c);
//    cout << math3;
//   }

//   else if (control == 3) {
//    c = math2 * math1;
//    math3.set(c);
//    cout << math3;
//   }

//   else if (control == 4) {
//    c = math2 / math1;
//    math3.set(c);
//    cout << math3;
//   }

//   else if (control == 5) {
//    if (math1 == math2) cout << "== True" << endl;
   
//    else if (math1 != math2) cout << "!= True" << endl;
   
//    else if (math1 >= math2) cout << ">= True" << endl;

//    else if (math1 <= math2) cout << "<= True" << endl;
   
//    else if (math1 > math2) cout << "> True" << endl;
   
//    else if (math1 < math2) cout << "< True" << endl;
//   }

//   else if (control == 6) {
//    c = math2.get();
//    math2 += math1;
//    cout << "+ "<< math2;
//    math2.set(c);
//    math2 -= math1;
//    cout << "- " << math2;
//    math2.set(c);
//    math2 /= math1;
//    cout << "/ " << math2;
//    math2.set(c);
//    math2 *= math1;
//    cout << "* " << math2;
//    math2.set(c);
//   }

//   if (control == 7){
//    math3 = math2;
//    cout << math3;
//   }

//   cout << endl;
//   cin >> control;
//  }

   RGB color1(10, 200, 0);
   RGB color2(30, 89, 78);
   RGB color3;

   color3.printRGB();
   color3 = color1 + color2;
   color3.printRGB();

}