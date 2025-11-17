#include <iostream>
using namespace std;

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
        cout << "Model updated to: " << model << endl;
    }

    static int getCount() {
        return count;
    }
};

// Definition of static variable
int Vehicle::count = 0;

int main() {
    // Test object
    Vehicle v1("Toyota", "Corolla");  
    v1.displayInfo();

    v1.updateModel("Premio");
    v1.displayInfo();

    cout << "Total vehicles: " << Vehicle::getCount() << endl;

    return 0;
}

