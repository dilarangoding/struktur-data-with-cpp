#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode{
    public:
        string name;
        string phone_number;

        HashNode(string name, string phone_number){
            this->name = name;
            this->phone_number= phone_number;
        }
};

class HashMap{
    private:
        vector<HashNode*> table[TABLE_SIZE];
    public:
        int hashFunc(string key){
            int hash_val = 0;

            for(char c : key){
                hash_val += c;
            }
            return hash_val % TABLE_SIZE;
        }

        void insert(string name, string phone_number){
            int hash_val = hashFunc(name);

            for(auto node: table[hash_val]){
                if(node->name == name){
                    node->phone_number = phone_number;
                    return;
                }
            }

            table[hash_val].push_back(new HashNode(name,phone_number));
        }

        void remove(string name){
            int hash_val= hashFunc(name);

            for (auto it = table[hash_val].begin(); it !=
                table[hash_val].end(); it++) {
                if ((*it)->name == name) {
                    table[hash_val].erase(it);
                    return;
                }
            }
        }

        string searchByName(string name){
            int hash_val = hashFunc(name);

            for(auto node : table[hash_val]){
                if(node->name == name){
                    return node->phone_number;
                }
            }

            return "";
        }

        void print(){
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                cout << i << ": ";
                for (auto pair : table[i]){
                    if(pair != nullptr){
                       cout << "[" << pair->name << ", " << pair->phone_number << "]";
                    }
                }
                cout << endl;
            }

        }
};

int main(){
    HashMap employee_map;

    employee_map.insert("Mistah","12345");
    employee_map.insert("Pastah","5678");
    employee_map.insert("Pastah","5678");
    cout << "Nomor HP Mistah : " << employee_map.searchByName("Mistah") << endl;
    employee_map.print();
}
