#include <iostream>
#include <iomanip>

using namespace std;
class Node
{
public:
    string name;
    int price;

    Node *next;
    Node *prev;

};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }


    void push(string name, int price)
    {
        Node* temp = new Node();
        temp->name = name;
        temp->price = price;
        temp->next = nullptr;
        if (head == nullptr) {
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            return;
        }
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    int countList(){
        Node *count;
        count = head;
        int total = 0;

        while(count != nullptr){
            total++;
            count = count->next;
        }

        return total;
    }

    // Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific -> insert middle

    void insertByPos(string name, int price, int pos){
        if(pos < 0 || pos > countList()){
            cout << "Cek Ulang Posisi" <<endl;
            return;
        }

       Node* newNode = new Node();
       newNode->name = name;
       newNode->price = price;

        if (!head) {
            head = tail = newNode;
        } else if (pos == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (pos == countList()) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < pos - 1; i++) {
                current = current->next;
            }
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    // Update produk Hanasui menjadi Cleora dengan harga 55.000
    bool update(string name, int price, int posisi){
        Node* current = head;
        int counter = 1;
        while(current != nullptr) {
            if(counter == posisi) {
                current->name = name;
                current->price = price;
                break;
            }
            current = current->next;
            counter++;
        }
    }

     void pop(){
        if (head == nullptr){
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != nullptr){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        delete temp;
    }

    void deleteAll(){
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Hapus produk wardah

    void deleteByPos(int pos){
        if(head == nullptr){
            return;
        }

        if(pos == 1){
            Node* temp = head;
            head = head->next;

            if(head != nullptr){
                head->prev = nullptr;
            }else{
                tail = nullptr;
            }

            delete temp;
            return;
        }

        Node* curr = head;
        int count = 1;

        while(curr != nullptr && count < pos){
            curr = curr->next;
            count++;
        }

        if (curr == nullptr){
            return;
        }

        if(curr == tail){
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    // Tampilkan Seluruh Data

    void display(){
        Node *current = head;

        cout << left << setw(15) << "Nama Produk" << right << setw(18) << "Harga" << endl;
        while (current != nullptr){
            cout << left << setw(15) << current->name
                 << right << setw(18) << current->price
                 << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList list;
    while (true){
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;
        switch (choice) {
        case 1:
        {
            list.push("Originote", 60000);
            list.push("Somethinc", 150000);
            list.push("Skintific", 60000);
            list.push("Wardah",  50000);
            list.push("Hanasui",  30000);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            string  newName;
            int newPrice,posisi;
            cout << "Masukan nama produk baru: ";
            cin  >> newName;
            cout << "Masukan harga produk baru: ";
            cin  >> newPrice;
            cout << "Masukan Posisi: ";
            cin  >> posisi;
            list.update(newName, newPrice, posisi);
            break;
        }
        case 4:
        {
            int pos,price;
            string name;
            cout << "Masukan Nama Produk: ";
            cin  >> name;
            cout << "Masukan harga Produk: ";
            cin  >> price;
            cout << "Masukan urutan posisi: ";
            cin  >> pos;
            list.insertByPos(name,price, pos);
            break;
        }
        case 5:
        {
            int pos;
            cout << "Masukan posisi yang ingin dihapus: ";
            cin  >> pos;
            list.deleteByPos(pos);
            break;
        }
        case 6:
        {
             list.deleteAll();
            break;
        }
        case 7:
        {
            list.display();
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            return 0;
        }
        }
    }
    return 0;
}
