#include <iostream>
using namespace std;

int main()
{
    int riyon_2211102241;
    int arr[3][4] = {{3, 2, 5, 8}, {2, 5, 1, 5}, {6, 1, 2, 3}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
