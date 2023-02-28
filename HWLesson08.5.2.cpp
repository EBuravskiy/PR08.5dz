#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    void GetCompanynameModel() {
        cout << "CompanyName: " << CompanyName << "\t" << "Model: " << Model << endl;
    }
    string CompanyName = "Mersedes";
    string Model = "model";
};

class PassengerCar : public virtual Car {
public:
    PassengerCar(string Model) {
        this->Model = Model;
    }
    PassengerCar(string CompanyName, string Model) {
        this->CompanyName = CompanyName;
        this->Model = Model;
    }
};

class Bus : public virtual Car {
public:
    Bus(string Model) {
        this->Model = Model;
    }
    Bus(string CompanyName, string Model) {
        this->CompanyName = CompanyName;
        this->Model = Model;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string CompanyName, string Model) : PassengerCar(CompanyName), Bus(Model) {
        this->CompanyName = CompanyName;
        this->Model = Model;
    }
};

int main()
{
    PassengerCar car("Mersedes", "GLA");
    car.GetCompanynameModel();
    Bus bus("Volvo", "9500");
    bus.GetCompanynameModel();
    Minivan minivan("Hyundai", "Staria");
    minivan.GetCompanynameModel();
    return 0;
}