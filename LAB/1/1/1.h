class Figure{
protected:
    int coordX;
    int coordY;
public:
    Figure(){};
    Figure(int x, int y);
};

class Rectangle: public Figure{
private:
    int p_height;
    int p_width;
public:
    Rectangle(int x, int y, int height, int width);
};