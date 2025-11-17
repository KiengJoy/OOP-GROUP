#include <iostream>
using namespace std;

// Base Class
class Vehicle {
protected:
    string brand;
    string model;
    static int count;   // Static variable declaration

public:
    // Constructor
    Vehicle(string b, string m) : brand(b), model(m) {
        count++;
    }

    // Virtual function
    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }

    // Static function to get total count
    static int getCount() {
        return count;
    }
};

// Definition of static variable
int Vehicle::count = 0;


// Derived Class 1: Car
class Car : public Vehicle {
private:
    int seats;   // Variable declaration for Car class

public:
    Car(string b, string m, int s) : Vehicle(b, m), seats(s) {}

    void displayInfo() override {
        cout << "Car -- Brand: " << brand << ", Model: " << model
             << ", Seats: " << seats << endl;
    }
};


// Derived Class 2: Motorbike
class Motorbike : public Vehicle {
private:
    int engineCapacity;  // Variable declaration for Motorbike class

public:
    Motorbike(string b, string m, int ec) : Vehicle(b, m), engineCapacity(ec) {}

    void displayInfo() override {
        cout << "Motorbike -- Brand: " << brand << ", Model: " << model
             << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }
};


// Main Function
int main() {
    Car car1("Toyota", "Premio", 5);
    Motorbike bike1("Yamaha", "R1", 998);

    car1.displayInfo();
    bike1.displayInfo();

    cout << "Total Vehicles Created: " << Vehicle::getCount() << endl;

    return 0;
}

