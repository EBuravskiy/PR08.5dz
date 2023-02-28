#include <iostream>
#include <string>
using namespace std;

class Figure {
public:
    Figure(double firstvar, double secondvar) {
        this->firstvar = firstvar;
        this->secondvar = secondvar;
    };
    Figure(double radius) {
        this->radius = radius;
    }
    double virtual CalculateArea() = 0;
    double firstvar = 0;
    double secondvar = 0;
    double radius = 0;
    const double PI = 3.1415926535;
};

class Parallelogram : public Figure {
public:
    Parallelogram(double firstvar, double secondvar) : Figure(firstvar, secondvar) {}
    Parallelogram(double firstvar) : Figure(radius) {
        this->firstvar = radius;
    }
    double virtual CalculateArea() override {
        return firstvar * secondvar;
    }
};

class Circle : public Figure {
public:
    Circle(double radius) : Figure(radius){}
    double CalculateArea() override {
        return PI * (radius * radius);
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double firstvar, double secondvar) : Parallelogram (firstvar, secondvar) {};
}; 

class Square : public Parallelogram {
public:
    Square(double firstvar) : Parallelogram(firstvar) {
        this->firstvar = firstvar;
    }
    double CalculateArea () {
        return firstvar * firstvar;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus (double firstvar, double secondvar) : Parallelogram (firstvar, secondvar) {};
    double CalculateArea() {
        return firstvar * secondvar;
    }
};


int main()
{
    try {
        cout << "Select the figure for which you want to calculate the area:\n" << "1. Parallelogram\n" << "2. Rectangle\n" << "3. Square\n" << "4. Rhombus\n" << "5. Circle\n";
        int count;
        cin >> count;
        double firstvar, secondvar, radius;
        switch (count) {
        case 1: {
            cout << "Enter the side and heigth of the parallelogram:\n";
            cout << "Side: ";
            cin >> firstvar;
            cout << "Heigth: ";
            cin >> secondvar;
            Parallelogram par(firstvar, secondvar);
            Figure* parallelogram = &par;
            cout << "The area of the parallelogram is " << parallelogram->CalculateArea() << endl;
        }
              break;
        case 2: {
            cout << "Enter the sides of the rectangle:\n";
            cout << "Firstside: ";
            cin >> firstvar;
            cout << "Secondside: ";
            cin >> secondvar;
            Rectangle rect(firstvar, secondvar);
            Figure* rectangle = &rect;
            cout << "The area of the rectangle is " << rectangle->CalculateArea() << endl;
        }
              break;
        case 3: {
            cout << "Enter the side of the square:\n";
            cin >> firstvar;
            Square sq(firstvar);
            Figure* square= &sq;
            cout << "The area of the square is " << square->CalculateArea() << endl;
        }
              break;
        case 4: {
            cout << "Enter the side and heigth of the rhombus:\n";
            cout << "Side: ";
            cin >> firstvar;
            cout << "Heigth: ";
            cin >> secondvar;
            Rhombus rhom(firstvar, secondvar);
            Figure* rhombus= &rhom;
            cout << "The area of the rhombus is " << rhombus->CalculateArea() << endl;
        }
              break;
        case 5: {
            cout << "Enter the radius of the circle:\n";
            cin >> radius;
            Circle rad(radius);
            Figure* circle = &rad;
            cout << "The area of the circle is " << circle->CalculateArea() << endl;
        }
              break;
        default: {
            throw exception("Wrong entered number!");
        }
            break;
        }
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}