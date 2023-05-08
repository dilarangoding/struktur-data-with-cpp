#include <iostream>

using namespace std;

// Program Single Linked List Non-Circular
// Deklrasi Struct Node

struct Node{
    int data;
    Node *next;
};

    Node *head;
    Node *tail;

void init(){
    head = NULL;
    tail = NULL;
}

// pengecekan
bool isEmpty(){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

// Tambah Depan
void insertDepan(int nilai){
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if(isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }else{
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(int nilai){
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if(isEmpty() == true){
        head = tail = baru;
        tail->next  = NULL;
    }else{
        tail->next =baru;
        tail = baru;
    }
}

int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;

    while(hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}


void insertTengah(int data, int posisi){
    if(posisi < 1 ||  posisi > hitungList()){
        cout << "Posisi diluar jangkauan" << endl;
    }else if(posisi == 1){
        cout << "Posisi bukan posisis tengah" << endl;
    }else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        bantu = head;
        int nomor = 1;
        while(nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan

void hapusDepan(){
    Node *hapus;
    if(isEmpty() == false){
        if(head->next != NULL){
            hapus = head;
            head  = head->next;
            delete hapus;
        }else{
            head = tail = NULL;
        }
    }else{
        cout << "List Kosong" << endl;
    }
}

void hapusBelakang(){
    Node *hapus;
    Node *bantu;

    if(isEmpty() == false){
        if(head != tail){
            hapus = tail;
            bantu = head;

            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }else{
            head = tail = NULL;
        }
    }else{
        cout << "List Kosong" <<endl;
    }
}

void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if(posisi < 1 || posisi > hitungList()){
        cout << "Posisi diluar jangkauan" <<endl;
    }else if(posisi == 1){
        cout << "Posisi bukan posisis tengah";
    }else{
        int nomor = 1;
        bantu = head;

        while(nomor <= posisi ){
            if(nomor == posisi - 1){
                bantu2 = bantu;
            }
            if(nomor == posisi){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

void ubahDepan(int data){
    if(isEmpty() == false){
        head->data = data;
    }else{
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(int data){
    if(isEmpty() == false){
        tail->data = data;
    }else{
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(int data, int posisi){
    Node *bantu;

    if(isEmpty() == false){
        if(posisi < 1 || posisi > hitungList()){
            cout << "Posisi diluar jangkuan" << endl;
        }else if(posisi == 1){
            cout << "Posisi bukan ditengah" <<endl;
        }else{
            bantu = head;
            int nomor = 1;
            while(nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }else{
        cout << "List masih kosong"<<endl;
    }
}

// hapus list

void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil dihapus!"<< endl;
}


void tampil(){
    Node *bantu;
    bantu = head;

    if(isEmpty() == false){
        while(bantu != NULL){
            cout << bantu->data << " "<< ends;
            bantu = bantu->next;
        }
        cout << endl;
    }else
    {
        cout << "List masih kosong" << endl;
    }

}

int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11,2);
    tampil();
}
