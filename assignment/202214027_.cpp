#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
    Rectangle(const Rectangle &r)
    {
        width = r.width;
        height = r.height;
    }
    int getArea()
    {
        return width * height;
    }
    bool isSquare()
    {
        return width == height;
    }
    int perimeter()
    {
        return 2 * (width + height);
    }
};

int main()
{
    Rectangle r1(5, 10);
    Rectangle r2(r1);
    r2.width = 7;
    cout << "Area of r1: " << r1.getArea() << endl;
    cout << "Area of r2: " << r2.getArea() << endl;
    cout << "r1 is a square? " << r1.isSquare() << endl;
    cout << "r2 is a square? " << r2.isSquare() << endl;
    cout << "Perimeter of r1: " << r1.perimeter() << endl;
    cout << "Perimeter of r2: " << r2.perimeter() << endl;
    return 0;
}
