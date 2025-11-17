#include <iostream>
using namespace std;

// Global Variable
string companyName = "AutoMakers Ltd";

// Base Class
class Vehicle {
protected:
    string brand;
    string model;
    static int count;
public:
    Vehicle(string b, string m) : brand(b), model(m) {
        count++;
    }

    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }

    static int getCount() {
        return count;
    }
};

int Vehicle::count = 0;


// Derived Class: Car
class Car : public Vehicle {
private:
    int seats;
public:
    Car(string b, string m, int s) : Vehicle(b, m), seats(s) {}

    void displayInfo() override {
        cout << "Car -- Brand: " << brand 
             << ", Model: " << model 
             << ", Seats: " << seats 
             << endl;
    }
};


// Derived Class: Motorbike
class Motorbike : public Vehicle {
private:
    int engineCapacity;
public:
    Motorbike(string b, string m, int ec) : Vehicle(b, m), engineCapacity(ec) {}

    void displayInfo() override {
        cout << "Motorbike -- Brand: " << brand 
             << ", Model: " << model 
             << ", Engine Capacity: " << engineCapacity << "cc" 
             << endl;
    }
};


// Main Function
int main() {
    cout << "Company: " << companyName << endl;

    Car car1("Toyota", "Corolla", 5);
    Car car2("Honda", "Civic", 4);
    Motorbike bike1("Yamaha", "R15", 150);
    Motorbike bike2("Suzuki", "Gixxer", 155);

    Vehicle* vehicles[4];
    vehicles[0] = &car1;
    vehicles[1] = &car2;
    vehicles[2] = &bike1;
    vehicles[3] = &bike2;

    // Polymorphism in action
    for(int i = 0; i < 4; i++) {
        vehicles[i]->displayInfo();
    }

    cout << "Total number of vehicles created: " 
         << Vehicle::getCount() << endl;

    return 0;
}

