#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    string model;
    static int count;  // Static variable to track number of vehicles

public:
    // Constructor
    Vehicle(string b, string m) : brand(b), model(m) {
        count++;
    }

    // Virtual function for displaying vehicle info
    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }

    // Static function to get total count
    static int getCount() {
        return count;
    }
};

// Initialize static member
int Vehicle::count = 0;

// Derived class
class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor calls base class constructor
    Car(string b, string m, int d) : Vehicle(b, m), doors(d) {}

    // Override displayInfo
    void displayInfo() override {
        cout << "Brand: " << brand << ", Model: " << model 
             << ", Doors: " << doors << endl;
    }
};

int main() {
    // Create objects
    Vehicle v1("Toyota", "Corolla");
    Car c1("Honda", "Civic", 4);

    // Display info
    v1.displayInfo();
    c1.displayInfo();

    // Display total number of vehicles
    cout << "Total vehicles created: " << Vehicle::getCount() << endl;

    return 0;
}

