#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// fungsi hash sederhana
int hash_func(int key){
    return key % MAX_SIZE;
}

struct Node{
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value),next(nullptr){}
};

// Class hash table
class HashTable{
    private:
     Node** table;
    public:
        HashTable(){
            table = new Node*[MAX_SIZE]();
        }

        ~HashTable(){
            for(int i = 0; i < MAX_SIZE; i++){
                Node* current = table[i];
                while(current != nullptr){
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
        }

        //insertion
        void insert(int key, int value){
            int index = hash_func(key);
            Node* current = table[index];
            while(current != nullptr){
                if(current->key == key){
                    current->value = key;
                    return;
                }
                current = current->next;
            }
            Node* node = new Node(key, value);
            node->next = table[index];
            table[index] = node;
        }

        // Searching
        int get(int key){
            int index = hash_func(key);
            Node* current = table[index];
            while(current != nullptr){
                if(current->key == key){
                    return current->value;
                }
                current = current->next;
            }
            return -1;
        }

        // deletion
        void remove(int key){
            int index = hash_func(key);
                Node* current = table[index];
                Node* prev = nullptr;
                while(current != nullptr){
                    if(current->key == key){
                        if(prev == nullptr){
                            table[index] = current->next;
                        }else{
                            prev->next = current->next;
                        }
                        delete current;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
        }

        // Travesal
        void travese(){
            for (int i = 0; i < MAX_SIZE; i++) {
                Node* current = table[i];
                while (current != nullptr){
                    cout << current->key << ": " << current->value << endl;
                    current = current->next;
                }

            }

        }
};

int main(){
    HashTable ht;
    //insertion
    ht.insert(1,10);
    ht.insert(2,20);
    ht.insert(3,30);

    // searching

    cout << "Get key 1 " << ht.get(1) << endl;
    cout << "Get key 4 " << ht.get(4) << endl;

    // deletion
    ht.remove(4);

    // Traversal
    ht.travese();
}
