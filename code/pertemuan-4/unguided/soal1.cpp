#include <iostream>
#include <iomanip>

using namespace std;

struct Node{
    string name;
    long long nim;

    Node *next;
};

Node *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}


bool isEmpty(){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

// - insertfirst
void insertFirst(string name, long long nim){
    Node *baru = new Node;
    baru->name = name;
    baru->nim  = nim;
    baru->next = NULL;
    if(isEmpty() == true){
        head = tail = baru;
        tail->next  = NULL;
    }else{
        baru->next = head;
        head = baru;
    }
}

// insertBack
void insertBack(string name, long long nim){
    Node *newNode = new Node;
    newNode->name = name;
    newNode->nim = nim;
    newNode->next = NULL;

    if(isEmpty() == true){
        head = tail = newNode;
        tail->next  = NULL;
    }else{
        tail->next =newNode;
        tail = newNode;
    }
}

int countList(){
    Node *count;
    count = head;
    int num = 0;

    while(count != NULL){
        num++;
        count = count->next;
    }

    return num;
}

    // - insertMiddle
void insertMiddle(string name, long long nim, int pos ){
    if(pos < 1 || pos > countList()){
        cout << "Posisi diluar jangkauan cuy" <<endl;
    }else if(pos == 1){
        cout << "Posisi bukan ditengah" <<endl;
    }else{
        Node *newNode, *temp;
        newNode = new Node();
        newNode->name = name;
        newNode->nim  = nim;
        temp = head;

        int num = 1;
        while(num < pos - 1){
            temp = temp->next;
            num++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void changeFirst(string name, long long nim){
        if(isEmpty() == false){
            head->name = name;
            head->nim = nim;
        }else{
            cout << "List masih kosong!" << endl;
        }
}


    // - changeMiddle
void changeMiddle(string name, long long nim, int pos){
    Node *temp;
    if(isEmpty() == 0){
        if(pos < 1 || pos > countList()){
            cout << "Posisi diluar jangakauan cuy" << endl;
        }else if(pos == 1){
            cout << "Posisi bukan ditengah" <<endl;
        }else{
            temp = head;
            int num = 1;
            while(num < pos){
                temp = temp->next;
                num++;
            }
            string n = temp->name;
            temp->name = name;
            temp->nim  = nim;

            cout << "Data " << n << " telah diganti dengan data " << name << endl<<endl;
        }
    }else{
        cout << "List masih kosong" << endl;
    }

}

    // - changeBack
void changeBack(string name, long long nim){
    if(isEmpty() == 0){
        string n = tail->name;
        tail->name = name;
        tail->nim  = nim;
        cout << "Data " << n << " telah diganti dengan data " << name <<endl<<endl;
    }else{
        cout << "List masih kosong cuy" << endl;
    }
}
    // - delete back
void deleteBack(){
    Node *del, *temp;

    if(isEmpty() == false){
        if(head != tail){
            string n = tail->name;
            del = tail;
            temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
            delete del;

            cout << "Data " << n << " berhasil dihapus"<<endl<<endl;
        }else{
            head = tail = NULL;
        }
    }else{
        cout << "List kamu masih kosong nih" << endl;
    }
}
// Delete First
void deleteFirst(){
    Node *del;
    if(isEmpty() == false){
        if(head->next != NULL){
            del = head;
            head  = head->next;
            delete del;
        }else{
            head = tail = NULL;
        }
    }else{
        cout << "List Kosong" << endl;
    }
}

// - deleteMiddle
void deleteMiddle(int pos){
    Node *temp, *del, *prev;
    if(pos < 1 || pos > countList()){
        cout << "Posisi diluar jangkauan cuy" <<endl;
    }else if(pos == 1){
        cout << "Posisi bukan ditengah" <<endl;
    }else{
        int num = 1;
        temp = head;

        while(num  <= pos){
            if(num == pos - 1){
                prev = temp;
            }if(num == pos){
                del = temp;
            }

            temp = temp->next;
            num++;
        }
        string n = del->name;
        prev->next = temp;
        delete del;

        cout << "Data " << n << " berhasil dihapus!"<<endl<<endl;
    }
}

// clear List
void clearList(){
     Node *temp, *del;
    temp = head;
    while(temp != NULL){
        del = temp;
        temp = temp->next;
        delete del;
    }
    head = tail = NULL;
    cout << "List berhasil dihapus!"<< endl;
}

    // - Display
void display(){
    Node *temp;
    temp = head;
    if(isEmpty() == false){
        cout << "DATA MAHASISWA" <<endl<<endl;
        cout << left << setw(15) << "Nama" << left << setw(20) << "Nim" <<endl;
        while(temp != NULL){
            cout << left << setw(15) << temp->name
                 << left << setw(30) << temp->nim  << endl;
            temp = temp->next;
        }
        cout <<endl;
    }else{
        cout << "List kamu masih kosong nih, isi dulu ya";
    }
}


int main(){
    init();

    while(true){
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" <<endl<<endl;
        cout << "1. Tambah Depan"<<endl;
        cout << "2. Tambah Belakang"<<endl;
        cout << "3. Tambah Tengah"<<endl;
        cout << "4. Ubah Depan"<<endl;
        cout << "5. Ubah Belakang"<<endl;
        cout << "6. Ubah Tengah"<<endl;
        cout << "7. Hapus Depan"<<endl;
        cout << "8. Hapus Belakang"<<endl;
        cout << "9. Hapus Tengah"<<endl;
        cout << "10. Hapus List"<<endl;
        cout << "11. Tampilkan"<<endl;
        cout << "0. Keluar"<<endl<<endl;

        int choice;
        cout << "Pilih Operasi : ";
        cin  >>choice;

        switch (choice){
            case 1:{
                string name;long long nim;
                cout << "\n-Tambah Depan-"<<endl<<endl;
                cout << "Masukan Nama : ";
                cin  >> name;
                cout << "Masukkan Nim : ";
                cin  >> nim;
                cout << endl;

                insertFirst(name, nim);
                cout << "Data " << name << " berhasil diinput!" <<endl<<endl;
                break;
            }
            case 2:{
                string name; long long nim;
                cout << "\n-Tambah Belakang-" <<endl<<endl;
                cout << "Masukkan Nama : ";
                cin  >> name;
                cout << "Masukkan Nim : ";
                cin  >> nim;
                cout << endl;
                insertBack(name,nim);
                cout << "Data " << name << " berhasil diinput!" <<endl<<endl;
                break;
            }
            case 3:{
                string name; long long nim; int pos;
                cout << "\n-Tambah Tengah-" <<endl<<endl;
                cout << "Masukkan Nama : ";
                cin  >> name;
                cout << "Masukkan Nim : ";
                cin  >> nim;
                cout << "Masukkan Posisi : ";
                cin  >> pos;
               cout << endl;

                insertMiddle(name, nim, pos);
                cout << "Data " << name << " berhasil diinput!" <<endl<<endl;
                break;
            }
            case 4:{
                changeFirst("Sample",2121);
                break;
            }
            case 5:{
                    string name; long long nim;
                    cout << "\n-Ubah Belakang-" <<endl<<endl;
                    cout << "Masukkan Nama : ";
                    cin  >> name;
                    cout << "Masukkan Nim : ";
                    cin  >> nim;
                    cout << endl;

                    changeBack(name, nim);
                break;
            }
            case 6:{
                    string name; long long nim; int pos;
                    cout << "\n-Ubah Tengah-" <<endl<<endl;
                    cout << "Masukkan Nama : ";
                    cin  >> name;
                    cout << "Masukkan Nim : ";
                    cin  >> nim;
                    cout << "Masukkan Posisi : ";
                    cin  >> pos;
                    cout << endl;

                    changeMiddle(name, nim, pos);
                break;
            }
            case 7:{
                deleteFirst();
                break;
            }
            case 8:{
                cout << "-Hapus Belakang-" <<endl<<endl;
                deleteBack();
                break;
            }
            case 9:{
                int num;
                cout << "Masukkan posisi : ";
                cin  >> num;
                cout <<endl;
                deleteMiddle(num);
                break;
            }
            case 10:{
                clearList();
                break;
            }
            case 11:{
                display();
                break;
            }
            case 0:{
                return 0;
                break;
            }
            default:{
                return 0;
                break;
            }
        }
    }

    return 0;
}
