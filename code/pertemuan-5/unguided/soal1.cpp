#include <iostream>
using namespace std;

const int MAX_SIZE = 10;


struct Node{
    int nim;
    int nilai;
};

// Class hash table
class HashTable{
    private:
     static const int tableSize= 10;
     Node* table[tableSize];
    public:
        HashTable(){
            for (int i = 0; i < tableSize; i++){
                table[i] = nullptr;
            }
        }

        int hashFunc(int nim){
            return nim % tableSize;
        }

        void add(int nim, int nilai){
            int index = hashFunc(nim);
            while(table[index] != nullptr && table[index]->nim != nim){
                index = (index + 1) % tableSize;
            }

            if(table[index] != nullptr){
                delete table[index];
            }

            table[index] = new Node;
            table[index]->nim = nim;
            table[index]->nilai = nilai;
        }

        void print(){
            for (int i = 0; i < tableSize; i++){
                if(table[i] != nullptr){
                    cout << "NIM: " << table[i]->nim << endl;
                    cout << "Nilai: " << table[i]->nilai <<endl<<endl;
                }
            }

        }

        void remove(int nim){
            int index = hashFunc(nim);
            while(table[index] != nullptr){
                if(table[index]->nim == nim){
                    break;
                }
                index = (index + 1) % tableSize;
            }

            if(table[index] == nullptr){
                cout << nim << " tidak ditemukan." <<endl;
                return;
            }

            delete table[index];
            table[index] = nullptr;
        }

        void searchByNim(int nim) {
            int index = hashFunc(nim);
            while (table[index] != nullptr) {
                if (table[index]->nim == nim) {
                    cout << "NIM: " << table[index]->nim << endl;
                    cout << "Nilai: " << table[index]->nilai << endl << endl;
                    return;
                }
                index = (index + 1) % tableSize;
             }
           cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
        }

        void searchByRentangNilai(){
            bool found = false;
            for(int i = 0; i < tableSize; i++){
                if(table[i] != nullptr && table[i]->nilai >=80 && table[i]->nilai <= 90){
                     cout << "NIM: " << table[i]->nim <<endl;
                     cout << "Nilai: " << table[i]->nilai <<endl<<endl;
                     found = true;
                }
            }
            if(!found){
                cout << "data dengan rentang nilai 80 - 90 tidak ditemukan" <<endl;
            }
        }


};

int main(){
    HashTable dataMhs;
    int choice, nim, nilai;

    do{
        cout << "\n--- Data mahasiswa ---" <<endl;
        cout << "1.Tambah Data" <<endl;
        cout << "2.Hapus Data" <<endl;
        cout << "3.Cari Data Berdasarkan NIM" <<endl;
        cout << "4.Cari Data Berdasarkan Rentang Nilai" <<endl;
        cout << "5.Print Data" <<endl;
        cout << "6.Keluar" <<endl;
        cout << "Pilih Menu [1-6]: ";
        cin >> choice;

        switch (choice){
        case 1:
                cout << "Masukkan NIM: ";
                cin  >> nim;
                cout << "Masukkan Nilai: ";
                cin  >> nilai;
                dataMhs.add(nim,nilai);
            break;
        case 2:
            cout << "Masukkan NIM : ";
            cin  >> nim;
            dataMhs.remove(nim);
            break;
        case 3:
            cout << "Masukkan NIM: ";
            cin  >> nim;
            dataMhs.searchByNim(nim);
            break;
        case 4:
            dataMhs.searchByRentangNilai();
            break;
        case 5:
            dataMhs.print();
            break;
        case 6:
            cout << "Keluar Program." <<endl;
            break;
        default:
            cout << "Menu salah. Silahkan Coba Lagi" << endl;
            break;
        }

    }while(choice != 6);

}
