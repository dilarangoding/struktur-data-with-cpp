#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "antrian kosong" << endl;
    } else {
        Node* temp = front;
        int index = 1;
        while (temp != NULL) {
            cout << index << ". " << temp->nama << " NIM: " << temp->nim  << endl;
            temp = temp->next;
            index++;
        }
    }
}

int main() {
    int menu;
    string nama, nim;
    do{
        cout << "1.Masukkan Data"<<endl;
        cout << "2.Hapus Satu Data"<<endl;
        cout << "3.Reset Data"<<endl;
        cout << "4.Tampil Data"<<endl;
        cout << "Pilih Menu [1-4]: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Masukkan Nama Mahasiswa: ";
            cin  >> nama;
            cout << "Masukkan NIM Mahasiswa: ";
            cin  >> nim;
            enqueueAntrian(nama,nim);
            break;
        case 2:
            dequeueAntrian();
            break;
        case 3:
            clearQueue();
            break;
        case 4:
            viewQueue();
            break;
        case 0:
            cout << "Selamat Tinggal" <<endl;
            break;
        default:
            cout << "Pilihan tidak ada" <<endl;
            break;
        }
        cout <<endl;
    }while (menu != 0);


}
