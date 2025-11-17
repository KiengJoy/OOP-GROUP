#include <iostream>
#include <stdexcept>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
public:
    Vehicle(string b, string m) : brand(b), model(m) {}
    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }
};

class Car : public Vehicle {
public:
    int seats;
    Car(string b, string m, int s) : Vehicle(b, m) {
        if (s < 0) {
            throw invalid_argument("Invalid number of seats! Must be non-negative.");
        }
        seats = s;
    }

    void displayInfo() {
        cout << "Car -- Brand: " << brand << ", Model: " << model << ", Seats: " << seats << endl;
    }
};

class Motorbike : public Vehicle {
public:
    int engineCapacity;
    Motorbike(string b, string m, int ec) : Vehicle(b, m) {
        if (ec < 0) {
            throw invalid_argument("Invalid engine capacity! Must be non-negative.");
        }
        engineCapacity = ec;
    }

    void displayInfo() {
        cout << "Motorbike -- Brand: " << brand << ", Model: " << model
             << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }
};

int main() {
    try {
        Car car1("Toyota", "Corolla", 5);
        Motorbike bike1("Yamaha", "R15", 150);

        car1.displayInfo();
        bike1.displayInfo();
    }
    catch (invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

