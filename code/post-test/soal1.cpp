#include <iostream>
#include <string>
using namespace std;

// fungsi dari division method
int dim(const string &kata, int tableSize)
{
    int sum = 0;
    for (char c : kata)
    {
        sum += c;
    }
    return sum % tableSize;
}

int main()
{
    string ajojing = "AJOJING";
    string charlie = "CHARLIE";
    int table_Size = 30;

    int indeksAjojing = dim(ajojing, table_Size);
    int indeksCharlie = dim(charlie, table_Size);

    cout << ajojing << " ditemukan pada indeks ke-" << indeksAjojing << endl;
    cout << charlie << " ditemukan pada indeks ke-" << indeksCharlie << endl;

    return 0;
}
