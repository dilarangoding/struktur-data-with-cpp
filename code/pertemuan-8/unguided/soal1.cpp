#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int binarySearch(const char arr[], int low, int high, char target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (tolower(arr[mid]) == tolower(target))
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void searchChar(const char arr[], int length, char target) {
    int index = binarySearch(arr, 0, length - 1, target);

    if (index != -1) {
        cout << "Huruf ditemukan pada indeks: " << index << endl;

        int left = index - 1;
        while (left >= 0 && tolower(arr[left]) == tolower(target)) {
            cout << "Huruf ditemukan pada indeks: " << left << endl;
            left--;
        }

        int right = index + 1;
        while (right < length && tolower(arr[right]) == tolower(target)) {
            cout << "Huruf ditemukan pada indeks: " << right << endl;
            right++;
        }
    }
    else {
        cout << "Huruf tidak ditemukan." << endl;
    }
}

int main() {
    const int MAX_SIZE = 100;
    char sentence[MAX_SIZE];
    char target;

    cout << "Masukkan kalimat: ";
    cin.getline(sentence, MAX_SIZE);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    searchChar(sentence, strlen(sentence), target);

    return 0;
}
