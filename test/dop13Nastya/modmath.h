#pragma once
#include <stdlib.h>
#include <iostream>
class modmath {

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

class RGB{

private:
    int p_red;
    int p_green;
    int p_blue;

public: 
    RGB();
    RGB(int red, int green, int blue);

    void getRGB(int red, int green, int blue);
    void setRGB(int red, int green, int blue);
    
    RGB operator+(RGB& other);
    // int operator-(RGB& other);

    void printRGB();


};

int checker(int mod);