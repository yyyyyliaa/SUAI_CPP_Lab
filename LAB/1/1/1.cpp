#include "1.h"

Figure::Figure(int x, int y){
    coordX = x;
    coordY = y;
}

Rectangle::Rectangle(int x, int y, int height, int width):Figure(x, y){
    p_height = height;
    p_width = width;
}

Rectangle::Rectangle(int x, int y, int height, int width):Figure(){
    coordX = x;
    coordY = y;
    p_height = height;
    p_width = width;
}

Figure::Figure(){
}
