#include <iostream>
using namespace std;

int main(){
    int a;

    cout << "Masukkan panjang Array: ";
    cin  >> a;

    int array[a], ganjil[a],genap[a];
    int jml_genap = 0, jml_ganjil = 0;

    cout << "Masukkan " << a << " angka\n";
    for(int i = 0; i < a; i++){
        cout << "Array ke-" << i << ": ";
        cin  >> array[i];
    }

    for(int i = 0; i < a; i++){
        if(array[i] % 2 == 0){
            genap[jml_genap] = array[i];
            jml_genap++;
        }else{
            ganjil[jml_ganjil] = array[i];
            jml_ganjil++;
        }
    }

     cout << "Data Array ";
     for(int i = 0; i < a; i++){
       cout << array[i] << " ";
     }
     cout << endl;

     cout << "Bilangan Genap ";
     for(int i = 0; i < jml_genap; i++){
       cout << genap[i];
       if(i < jml_genap - 1){
         cout << ", ";
       }
     }
     cout << endl;

     cout << "Bilangan ganjil ";
     for(int i = 0; i < jml_ganjil; i++){
       cout << ganjil[i];
       if(i < jml_ganjil - 1){
         cout << ", ";
       }
     }
     cout << endl;
}
