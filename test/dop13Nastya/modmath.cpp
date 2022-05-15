#include "modmath.h"
#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;

modmath::modmath(int a, int b) {
 mod = b;
 num = a % mod;
}

modmath::modmath(int b) {
 mod = b;
}

int modmath::operator+(const modmath& other){
    return ((this->num + other.num)%mod);
}

int modmath::operator-(const modmath& other){
 int c = ((this->num - other.num) % mod);
 return c;
}

int modmath::operator=(const modmath& other){
 this->num = other.num;
 this->num = this->num % this->mod;
 return this->num;
}

int modmath::operator*(const modmath& other) {
 return ((this->num*other.num)%mod);
}

int modmath::operator/(const modmath& other){
 int num = other.num % other.mod;
 int num2 = this->num % this->mod;
 if (num != 0){
  while (num2 % num != 0){
   num2 += this->mod;
  }
  return ((num2 / num) % other.mod);
 }
 else {
  cout << "error" << endl;
  return 0;
 }
}

int modmath::operator+=(const modmath& other){
 num += other.num;
 return num = (num % mod);
}

int modmath::operator-=(const modmath& other){
 if (num - other.num < 0) num += this->mod;
 
 num -= other.num % other.mod;
 return num = (num % mod);
}

int modmath::operator*=(const modmath& other) {
 this->num = ((this->num % this->mod) * (other.num % other.mod)) % this->mod;
 return this->num;
}

int modmath::operator/=(const modmath& other) {
 this->num = this->num % this->mod;
 while ((this->num) % (other.num % mod) != 0) {
  this->num += this->mod;
 }

 this->num = (this->num / (other.num % other.mod)) % this->mod;
 return this->num;
}

bool modmath::operator==(const modmath& other) {
 if (this->mod == other.mod) {
  if ((other.num % this->mod) == (this->num % this->mod)) return true;
  else return false;
 }
}

bool modmath::operator!=(const modmath& other) {
 if (this->mod == other.mod) {
  if ((other.num % this->mod) != (this->num % this->mod)) return true;

  else return false;
 }
}

bool modmath::operator>=(const modmath& other) {
 if (this->mod == other.mod){
  if ((other.num % this->mod) == (this->num % this->mod)|| (other.num % this->mod) > (this->num % this->mod))
    return true;
  
  else return false;
 }
}
bool modmath::operator<=(const modmath& other) {
 if (this->mod == other.mod){
  if ((other.num % this->mod) == (this->num % this->mod)|| (other.num % this->mod) < (this->num % this->mod))
    return true;

  else return false;
 }
}

bool modmath::operator>(const modmath& other) {
 if (this->mod == other.mod){
  if ((other.num % this->mod) > (this->num % this->mod))
    return true;
  
  else return false;
 }
}
bool modmath::operator<(const modmath& other) {
 if (this->mod == other.mod){
  if ((other.num % this->mod) < (this->num % this->mod))
    return true;
  else return false;
 }
}

istream& operator>>(istream& in, modmath& temp) {
    in >> temp.num;
    return in;
}

ostream& operator<<(ostream& out, const modmath& r) {
    out << r.num << endl;
    return out;
}

int checker(int mod) {
 int a = 0;
 for (int i = 2; i <= sqrt(mod); i++) {
  if (mod % i == 0){
   a = 1;
   break;
  }
  else a = 0;
 }
 return a;
}

void modmath::set(int c) {
 this->num = c;
}

int modmath::get() {
 return num;
}

RGB::RGB(int red, int green, int blue){
    setRGB(red, green, blue);
}

void RGB::getRGB(int red, int green, int blue){
    red = this->p_red;
    green = this->p_green;
    blue = this->p_blue;
}

void RGB::setRGB(int red, int green, int blue){
    this->p_red = red;
    this->p_green = green;
    this->p_blue = blue;
}

RGB RGB::operator+(RGB& other){
    this->p_red = (this->p_red + other.p_red)%255;
    this->p_green = (this->p_green+other.p_green)%255;
    this->p_blue = (this->p_blue+other.p_blue)%255;
    return *this;
}

void RGB::printRGB(){
    cout<<"("<<p_red<<", "<<p_green<<", "<<p_blue<<")"<<endl;
}