#include <iostream>

using namespace std;

class Car{
    public:
        string brand;
        string model;
        int year;

    void nitro(){
        cout << "Nitro Diaktiv-kan, Ngeengggg";
    }

};


int main(){

    Car carObj;
    carObj.brand = "Toyota";
    carObj.model = "Supra";
    carObj.year  = 1980;

    cout << carObj.brand << " " << carObj.model << " " << " " << carObj.year << endl;

    carObj.nitro();
}
