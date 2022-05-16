#include "modmath.h"
using namespace std;

int main() {

   int r, g, b;

   cout<<"Enter value RED for color1:";
   cin>>r;
   while((r<0)||(r>255)){
      cout<<"ERROR! Parameter must be > 0 and < 255"<<endl;
      cout<<"Enter value RED for color1:";
      cin>>r;
   }

   cout<<"Enter value GREEN for color1:";
   cin>>g;
   while((g<0)||(g>255)){
      cout<<"ERROR! Parameter must be > 0 and < 255"<<endl;
      cout<<"Enter value GREEN for color1:";
      cin>>g;
   }

   cout<<"Enter value BLUE for color1:";
   cin>>b; 
   while((b<0)||(b>255)){
      cout<<"ERROR! Parameter must be > 0 and < 255"<<endl;
      cout<<"Enter value BLUE for color2:";
      cin>>b;
   }
   cout<<endl;

   RGB color1(r, g, b);

   cout<<"Enter value RED for color2:";
   cin>>r;
   while((r<0)||(r>255)){
      cout<<"ERROR! Parameter must be > 0 and < 255"<<endl;
      cout<<"Enter value RED for color2:";
      cin>>r;
   }

   cout<<"Enter value GREEN for color2:";
   cin>>g;
   while((g<0)||(g>255)){
      cout<<"ERROR! Parameter must be > 0 and < 255"<<endl;
      cout<<"Enter value GREEN for color2:";
      cin>>g;
   }

   cout<<"Enter value BLUE for color2:";
   cin>>b; 
   while((b<0)||(b>255)){
      cout<<"ERROR! Parameter must be > 0 and < 255"<<endl;
      cout<<"Enter value BLUE for color2:";
      cin>>b;
   }
   cout<<endl;

   RGB color2(r, g, b);
   RGB color3;

   color1.printRGB();
   color2.printRGB();
   color3 = color1 + color2;
   color3.printRGB();

}