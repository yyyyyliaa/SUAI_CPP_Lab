#include "modmath.h"
using namespace std;
// ���: ��������������� + ������� ����� ��������� ��� ������������ ��� �� �����, �����������, ������� ������ ������������(����� � �����) �������� � ������ ��������� � �����
int main() 
{
 system("chcp 1251");
 system("cls");
 int mod;
 int control;
 int check = 1;
 cout << "������� ������ ���� �����" << endl;
 while (check != 0)
 {
  cin >> mod;
  check = checker(mod);
 }
 int c;
 modmath math1(mod);
 modmath math2(mod);
 modmath math3(mod);
 cout << "������� ����� a � b" << endl;
 cin >> math1;
 cin >> math2;
 cout << "�������� ������� ��� �������� ��� �������" << endl;
 cout << "1 ��� +" << endl;
 cout << "2 ��� -" << endl;
 cout << "3 ��� *" << endl;
 cout << "4 ��� /" << endl;
 cout << "5 ��� ���������� ��������" << endl;
 cout << "6 ��� ������" << endl;
 cout << "7 ��� ������������" << endl;
 cout << "0 ��� ������ �� ���������" << endl;
 cin >> control;
 while (control != 0)
 {
  if (control == 1) 
  {
   c = math2 + math1;
   math3.set(c);
   cout << math3;
  }
  if (control == 2) 
  {
   c = math2 - math1;
   math3.set(c);
   cout << math3;
  }
  if (control == 3) 
  {
   c = math2 * math1;
   math3.set(c);
   cout << math3;
  }
  if (control == 4) 
  {
   c = math2 / math1;
   math3.set(c);
   cout << math3;
  }
  if (control == 5) 
  {
   if (math1 == math2)
   {
	cout << "== True" << endl;
   }
   if (math1 != math2)
   {
	cout << "!= True" << endl;
   }
   if (math1 >= math2)
   {
	cout << ">= True" << endl;
   }
   if (math1 <= math2)
   {
	cout << "<= True" << endl;
   }
   if (math1 > math2)
   {
	cout << "> True" << endl;
   }
   if (math1 < math2)
   {
	cout << "< True" << endl;
   }
  }
  if (control == 6) 
  {
   c = math2.get();
   math2 += math1;
   cout << "+ "<< math2;
   math2.set(c);
   math2 -= math1;
   cout << "- " << math2;
   math2.set(c);
   math2 /= math1;
   cout << "/ " << math2;
   math2.set(c);
   math2 *= math1;
   cout << "* " << math2;
   math2.set(c);
  }
  if (control == 7)
  {
   math3 = math2;
   cout << math3;
  }
  cout << endl;
  cin >> control;
 }

}