#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int countVowels(const char* sentence) {
    int count = 0;
    int length = strlen(sentence);

    for (int i = 0; i < length; i++) {
        char ch = tolower(sentence[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    const int MAX_SIZE = 100;
    char sentence[MAX_SIZE];

    cout << "Masukkan kalimat: ";
    cin.getline(sentence, MAX_SIZE);

    int vowelCount = countVowels(sentence);

    cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount << endl;

    return 0;
}
