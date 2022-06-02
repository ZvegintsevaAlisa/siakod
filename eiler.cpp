#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <stack>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int MatSm[6][6] = { {0, 1, 1, 0, 0, 0},
                       {1, 0, 1, 1, 1, 0},
                       {1, 1, 0, 0, 1, 1},
                       {0, 1, 0, 0, 1, 0},
                       {0, 1, 1, 1, 0, 1},
                       {0, 0, 1, 0, 1, 0} };
    stack <int> st;
    int sv[6] = { 0 };
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (MatSm[i][j] == 1) sv[i]++;
    int n;
    cout << "Введите стартовую вершину:";
    cin >> n;
    st.push(n);
    cout << "Эйлеров цикл:";
    while (st.empty() == false) {
        int v = st.top();
        if (sv[v - 1] == 0) {
            cout << v;
            st.pop();
            if (st.empty() == false) cout << " => ";
        }
        else {
            for (int m = 0; m < 6; m++)
                if (MatSm[v - 1][m] == 1) {
                    MatSm[v - 1][m] = 0;
                    MatSm[m][v - 1] = 0;
                    st.push(m + 1);
                    sv[m]--; sv[v - 1]--;
                    break;
                }
        }
    }
    return 0;
}