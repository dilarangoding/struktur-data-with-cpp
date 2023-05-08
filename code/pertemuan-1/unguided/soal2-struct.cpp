#include <iostream>
#include <string>

using namespace std;

struct Car{
    string brand;
    string model;
    int year;
};

int main(){
    Car car1, car2;

    car1.brand = "Toyota";
    car1.model = "Supra";
    car1.year  = 1999;

    car2.brand = "Toyota";
    car2.model = "Corolla DX";
    car2.year  = 1980;

    cout << "Data Mobil 1: " << endl;
    cout << "Brand: " << car1.brand << endl;
    cout << "Model: " << car1.model << endl;
    cout << "Year: " << car1.year << endl <<endl;

    cout << "Data Mobil 2: " << endl;
    cout << "Brand: " << car2.brand << endl;
    cout << "Model: " << car2.model << endl;
    cout << "Year: " << car2.year << endl <<endl;

}
