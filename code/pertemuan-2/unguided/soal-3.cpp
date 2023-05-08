#include <iostream>

using namespace std;

int main(){
    int p, i, maks, min, menu;
    double avg, sum;

    cout << "1. Mencari Nilai Maksimum" <<endl;
    cout << "2. Mencari Nilai Minimum" <<endl;
    cout << "3. Mencari Nilai Rata-rata" <<endl;
    cout << "Masukkan menu [1-3]: ";
    cin  >> menu;

    cout << "Masukkan panjang Array: ";
    cin  >> p;

    int array[p];
    cout << "Masukkan " << p << " angka\n";
    for( i = 0; i < p; i++){
        cout << "Array ke-" << i << ": ";
        cin  >> array[i];
    }

    switch(menu){
        case 1:
              maks = array[0];
              for(i = 0; i < p; i++){
                if(array[i] > maks){
                    maks = array[i];
                    }
                }
                cout << "Nilai Maksimum adalah " << maks << endl;
            break;
        case 2:
              min  = array[0];
              for(i = 0; i < p; i++){
                    if(array[i] < min){
                        min = array[i];
                    }
                }
                cout << "Nilai Minumun adalah " << min << endl;
            break;
        case 3:
              sum = 0;
             for(int i = 0; i < p; i++){
                 sum += array[i];
             }
             avg = sum / p;

             cout << "Nilai Rata-rata " << avg << endl;
            break;
        default:
            cout << "Menu yang dimasukan salah";
            break;
    }


}
