#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> mahasiswa;

    mahasiswa["Joko"] = 89;
    mahasiswa["Puan"] = 76;
    mahasiswa["Bowo"] = 65;

    cout << "Daftar Nilai Mahasiswa:"<<endl;

    auto itr = mahasiswa.begin();
    while (itr != mahasiswa.end())
    {
        cout << itr->first << " : " << itr->second << endl;
        itr++;
    }


}
