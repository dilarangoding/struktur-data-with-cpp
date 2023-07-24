#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void inputSimpul(vector<string> &namaSimpul)
{
    int jumlahSimpul;

    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    namaSimpul.resize(jumlahSimpul);

    cout << "Silahkan masukkan nama simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }
}

void inputBobotAntarSimpul(vector<string> &namaSimpul, map<pair<string, string>, int> &bobotAntarSimpul)
{
    cout << "Silahkan masukkan bobot antar simpul:\n";
    for (int i = 0; i < namaSimpul.size(); i++)
    {
        for (int j = 0; j < namaSimpul.size(); j++)
        {
            string simpul1 = namaSimpul[i];
            string simpul2 = namaSimpul[j];
            int bobot;

            cout << simpul1 << " --> " << simpul2 << " = ";
            cin >> bobot;

            bobotAntarSimpul[make_pair(simpul1, simpul2)] = bobot;
        }
    }
}

void cetakGrafik(vector<string> &namaSimpul, map<pair<string, string>, int> &bobotAntarSimpul)
{
    cout << "\n\t";
    for (int i = 0; i < namaSimpul.size(); i++)
    {
        cout << setw(10) << namaSimpul[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < namaSimpul.size(); i++)
    {
        cout << namaSimpul[i] << "\t";
        for (int j = 0; j < namaSimpul.size(); j++)
        {
            string simpul1 = namaSimpul[i];
            string simpul2 = namaSimpul[j];
            int bobot = bobotAntarSimpul[make_pair(simpul1, simpul2)];

            cout << setw(10) << bobot << "\t";
        }
        cout << endl;
    }
}

int main()
{
    vector<string> namaSimpul;
    map<pair<string, string>, int> bobotAntarSimpul;

    inputSimpul(namaSimpul);
    inputBobotAntarSimpul(namaSimpul, bobotAntarSimpul);
    cetakGrafik(namaSimpul, bobotAntarSimpul);

    return 0;
}
