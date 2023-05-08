#include <iostream>

using namespace std;

int main(){
    float tinggi,berat_ideal;
    char jenis_kelamin;

    cout << "Masukan Jenis kelamin (L/P): ";
    cin  >> jenis_kelamin;

    cout << "Masukan tinggi badan (CM): ";
    cin  >> tinggi;

    if(jenis_kelamin == 'L' || jenis_kelamin == 'l'){
        berat_ideal = (tinggi - 100) - ((tinggi - 100) * 0.1);
    }else if(jenis_kelamin == 'P' || jenis_kelamin == 'p'){
        berat_ideal = (tinggi - 100) - ((tinggi - 100) * 0.15);
    }else{
        cout << "Jenis kelamin tidak valid"<<endl;
    }

    cout << "Berat badan ideal anda adalah " << berat_ideal <<" Kg." <<endl;

}
