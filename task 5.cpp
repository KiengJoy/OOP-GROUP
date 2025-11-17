#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> // Added for stringstream
using namespace std;

// ===== Base Class =====
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

    void updateModel(string newModel) {
        model = newModel;
    }

    string getBrand() { return brand; }
    string getModel() { return model; }

    static int getCount() {
        return count;
    }
};
int Vehicle::count = 0;


// ===== Derived Class: Car =====
class Car : public Vehicle {
private:
    int seats;

public:
    Car(string b, string m, int s) : Vehicle(b, m), seats(s) {}

    void displayInfo() {
        cout << "Car -- Brand: " << brand << ", Model: " << model
             << ", Seats: " << seats << endl;
    }

    int getSeats() { return seats; }
};


// ===== Derived Class: Motorbike =====
class Motorbike : public Vehicle {
private:
    int engineCapacity;

public:
    Motorbike(string b, string m, int ec) : Vehicle(b, m), engineCapacity(ec) {}

    void displayInfo() {
        cout << "Motorbike -- Brand: " << brand << ", Model: " << model
             << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }

    int getEngineCapacity() { return engineCapacity; }
};


// ===== Main Save to File =====
int main() {
    cout << "Vehicle Management System" << endl << endl;

    Car car1("Toyota", "Corolla", 5);
    Car car2("Honda", "Civic", 4);
    Motorbike bike1("Yamaha", "R15", 150);
    Motorbike bike2("Suzuki", "Gixxer", 155);

    Vehicle* vehicles[4] = { &car1, &car2, &bike1, &bike2 };

    vector<string> vehicleData;

    for(int i = 0; i < 4; i++) {
        Car* c = dynamic_cast<Car*>(vehicles[i]);
        Motorbike* m = dynamic_cast<Motorbike*>(vehicles[i]);
        stringstream info;

        if(c) {
            info << "Car," << c->getBrand() << "," << c->getModel() << "," << c->getSeats();
        } 
        else if(m) {
            info << "Motorbike," << m->getBrand() << "," << m->getModel() << "," << m->getEngineCapacity();
        } 
        else {
            info << "Vehicle," << vehicles[i]->getBrand() << "," << vehicles[i]->getModel();
        }

        vehicleData.push_back(info.str());
    }

    ofstream outfile("vehicles.txt");

    for(int i = 0; i < vehicleData.size(); i++) {
        outfile << vehicleData[i] << endl;
    }

    outfile.close();
    cout << "\nVehicle details written to vehicles.txt successfully!" << endl;

    return 0;
}

