#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            throw exception("Error! Division by zero!");
        }
        else {
            this->numerator = numerator;
            this->denominator = denominator;
            this->value = (double)this->numerator / (double)this->denominator;
        }
    }

    void Print() {
        if (this->denominator == 1) {
            cout << this->numerator << endl;
        }
        else if (this->numerator == 0) {
            cout << this->numerator << endl;
        }
        else {
            cout << this->numerator << "/" << this->denominator << endl;
        }
    }

    int NOD (int numerator, int denominator) {
        while (denominator > 0) {
            int value = numerator % denominator;
            numerator = denominator;
            denominator = value;
        }
        return numerator;
    }

    void reduce() {
        int devisor = NOD(abs(numerator), denominator);
            if (devisor != 1) {
                numerator = numerator / devisor;
                denominator = denominator / devisor;
            }
    }

    Fraction operator * (const Fraction& other) {
        Fraction temp;
        temp.numerator = this->numerator * other.numerator;
        temp.denominator = this->denominator * other.denominator;
        temp.reduce();
        return temp;
    }

    Fraction operator / (const Fraction& other) {
        Fraction temp;
        temp.numerator = this->numerator * other.denominator;
        temp.denominator = this->denominator * other.numerator;
        temp.reduce();
        return temp;
    }

    Fraction operator + (const Fraction& other) {
        Fraction result;
        if (this->denominator == other.denominator) {
            result.numerator = this->numerator + other.numerator;
            result.denominator = this->denominator;
            result.reduce();
            return result;
        }
        else if (this->denominator != other.denominator) {
            Fraction nffraction;
            Fraction nsfraction;
            nffraction.numerator = this->numerator * other.denominator;
            nffraction.denominator = this->denominator * other.denominator;
            nsfraction.numerator = this->denominator * other.numerator;
            result.numerator = nffraction.numerator + nsfraction.numerator;
            result.denominator = nffraction.denominator;
            result.reduce();
            return result;
        }
    }

    Fraction operator - (const Fraction& other) {
        Fraction result;
        if (this->denominator == other.denominator) {
            result.numerator = this->numerator - other.numerator;
            result.denominator = this->denominator;
            result.reduce();
            return result;
        }
        else if (this->denominator != other.denominator) {
            Fraction nffraction;
            Fraction nsfraction;
            nffraction.numerator = this->numerator * other.denominator;
            nffraction.denominator = this->denominator * other.denominator;
            nsfraction.numerator = this->denominator * other.numerator;
            nsfraction.denominator = this->denominator * other.denominator;
            result.numerator = nffraction.numerator - nsfraction.numerator;
            result.denominator = nffraction.denominator;
            result.reduce();
            return result;
        }
    }
    bool operator == (const Fraction& other) {
        return this->value == other.value;
    }

    bool operator != (const Fraction& other) {
        return !(this->value == other.value);
    }
    
    bool operator < (const Fraction& other) {
        return this->value < other.value;
    }

    bool operator > (const Fraction& other) {
        return this->value > other.value;
    }

    bool operator >= (const Fraction& other) {
        return this->value >= other.value;
    }

    bool operator <= (const Fraction& other) {
        return this->value <= other.value;
    }

private:
    int numerator;
    int denominator;
    double value;
};


int main()
{
    try {
        cout << "Enter the numerator of the first fraction: ";
        int a,b;
        cin >> a;
        cout << "Enter the denominator of the first fraction: ";
        cin >> b;
        Fraction first(a, b);
        cout << "Enter the numerator of the second fraction: ";
        cin >> a;
        cout << "Enter the denominator of the second fraction: ";
        cin >> b;
        Fraction second(a, b);
        Fraction result;
        cout << "The result of multiplyng fractions: ";
        result = first * second;
        result.Print();
        cout << "The result of dividing fractions: ";
        result = first / second;
        result.Print();
        cout << "The result of sum fractions: ";
        result = first + second;
        result.Print();
        cout << "The result of subtracting fractions: ";
        result = first - second;
        result.Print();
        cout << "Fraction Comparsion Result:\n";
        cout << "==\t";
        bool comparsion = first == second;
        cout << comparsion << endl;
        cout << "!=\t";
        comparsion = first != second;
        cout << comparsion << endl;
        cout << ">\t";
        comparsion = first > second;
        cout << comparsion << endl;
        cout << "<\t";
        comparsion = first < second;
        cout << comparsion << endl;
        cout << ">=\t";
        comparsion = first >= second;
        cout << comparsion << endl;
        cout << "<=\t";
        comparsion = first <= second;
        cout << comparsion << endl;

    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
