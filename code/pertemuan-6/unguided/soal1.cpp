#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

string balikkata(string kata) {
    char stack[MAX_SIZE];
    int top = -1;
    string kataTerbalik = "";

    for (int i = 0; i < kata.length(); i++) {
        if (top < MAX_SIZE - 1) {
            top++;
            stack[top] =kata[i];
        }
        else {
            cout << "Hello World!" << endl;
            return "";
        }
    }

    while (top >= 0) {
        kataTerbalik += stack[top];
        top--;
    }

    return kataTerbalik;
}

bool isPalindrom(string kalimat){
    string balik = balikkata(kalimat);
    return kalimat == balik;
}

int main() {
    string kata;
    cout << "Masukkan kata: ";
    getline(cin, kata);

    string balik = balikkata(kata);
    cout << "Data: " << balik << endl<<endl<<endl;

    string kalimat;
    cout << "Masukan kalimat: ";
    cin  >> kalimat;

    bool palindrom = isPalindrom(kalimat);
    if(palindrom){
        cout << "Kalimat tersebut : Palindrom" <<endl;
    }else{
        cout << "Kalimat tersebut : Bukan palindrom" <<endl;
    }

    return 0;
}
