#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node{
    string nama;
    int umur;
    Node *next;
};

Node *head, *tail;

// inisialisasi Node
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

// tambah data :igor 20 -> add first
void insertFirst(string nama, int umur){
    Node *baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;

    // cek isEmpty?
    if(isEmpty() == true){
        head = tail = baru;
        tail->next  = NULL;
    }else{
        baru->next = head;
        head       = baru;
    }
}

// Tambah data yang lain nya -> Insert back
void insertBack(string nama, int umur){
    Node *baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }else{
        tail->next = baru;
        tail = baru;
    }

}

int countList(){
    Node *count;
    count = head;
    int total = 0;

    while(count != NULL){
        total++;
        count = count->next;
    }

    return total;
}

// Add Data antara carol dan ann : Futuba 18 -> insert middle
void insertMiddle(string nama, int umur, int posisi){
    if(posisi < 1 || posisi > countList()){
        cout << "Posisi diluar jangkauan" <<endl;
    }else if(posisi == 1){
        cout << "Posisi bukan posisi tengah" <<endl;
    }else{
        Node *baru, *bantu;
        baru = new Node();
        baru->nama = nama;
        baru->umur = umur;

        bantu = head;
        int number = 1;

        while(number < posisi - 1){
            bantu = bantu->next;
            number++;
        }
        baru->next  = bantu->next;
        bantu->next = baru;
    }
}

// ubah carol jadi : reyn 18 -> change middle
void changeMiddle(string nama, int umur, int posisi){
    Node *bantu;

    if(isEmpty() == false){
        if(posisi < 1 || posisi > countList()){
            cout << "Posisi diluar jangkauan" << endl;
        }else if(posisi == 1){
            cout << "Posisi bukan posisi tengah" <<endl;
        }else{
            bantu = head;
            int num = 1;

            while (num < posisi)
            {
                bantu = bantu->next;
                num++;
            }
            bantu->nama = nama;
            bantu->umur = umur;
        }
    }else{
        cout << "List Kamu masih kosong nih, coba tambahin data dulu ya" <<endl;
    }
}

// Hapus Data Akechi -> delete middle
void deleteMiddle(int posisi){
    Node *hapus, *bantu, *bantu2;

    if(posisi < 1 || posisi > countList()){
        cout << "Posisi di luar jangakuan" <<endl;
    }else if(posisi == 1){
        cout << "Posisi bukan posisi tengah" <<endl;
    }else{
        int num = 1;
        bantu   = head;

        while(num <= posisi){
            if(num == posisi-1){
                bantu2 = bantu;
            }

            if(num == posisi){
                hapus  = bantu;
            }

            bantu = bantu->next;
            num++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}


// tampil seluruh data
void showList(){
    Node *bantu;
    bantu = head;

    if(isEmpty() == false){
        cout << left << setw(7) << "[Nama_anda]" << right << setw(7) << "[Usia_anda]"<<endl;
        while(bantu != NULL){
            cout << left  << setw(7) << bantu->nama
                 << right << setw(7) << bantu->umur
                 << endl;
            bantu = bantu->next;
        }
        cout <<endl;
    }else{
        cout << "List kamu masih kosong nih, coba inputin data dulu deh" <<endl;
    }
}

int main(){
    init();
    cout << endl;
    insertFirst("Budi", 19);
    insertBack("Carol",20);
    insertBack("Ann",18);
    insertBack("Yusuke",19);
    insertBack("Akechi",20);
    insertBack("Hoshino",18);
    insertBack("Karin",18);
    showList();
    deleteMiddle(5);
    insertMiddle("Futaba",18, 3);
    insertFirst("Igor",20);
    changeMiddle("Reyn", 18, 3);
    showList();
}
