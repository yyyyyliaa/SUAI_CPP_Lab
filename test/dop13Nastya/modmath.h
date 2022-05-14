#pragma once
#include <stdlib.h>
#include <iostream>
class modmath
{
private:
 int mod;
 int num;
public:
 modmath(int a, int b);
 modmath(int b);
 void set(int c);
 int get();
 int operator+(const modmath& other);
 int operator-(const modmath& other);
 int operator+=(const modmath& other);
 int operator-=(const modmath& other);
 int operator*(const modmath& other);
 int operator*=(const modmath& other);
 int operator/(const modmath& other);
 int operator/=(const modmath& other);
 bool operator==(const modmath& other);
 bool operator>(const modmath& other);
 bool operator<(const modmath& other);
 bool operator!=(const modmath& other);
 bool operator<=(const modmath& other);
 bool operator>=(const modmath& other);
 int operator=(const modmath& other);
 friend std::istream& operator>> (std::istream& in, modmath& temp);
 friend std::ostream& operator<< (std::ostream& out, const modmath& temp);
};
int checker(int mod);
class polynom
{
private:
 int poly[4];
public:
 polynom(int a[]);
 int operator+=(const polynom& other);
 int set(int c, int t);
 int get();

};
