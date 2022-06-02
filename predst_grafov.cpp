#include <Windows.h>
#include <iostream>
using namespace std;

void SmToInc(int a[][5])
{
    int MI[5][5] = { {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0} };;
    int SpR[5][2] = { {2, 1}, //список ребер, чтобы знать из какой точки ребро выходит/в какую входит
                      {3, 2},
                      {4, 3},
                      {5, 4},
                      {3, 5}, };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5;j++)
        {
            if (a[i][j] == 1) for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 1;l++)
                {
                    if (i + 1 == SpR[k][l] && j + 1 == SpR[k][l + 1])
                        MI[i][k] = 1;
                    if (j + 1 == SpR[k][l] && i + 1 == SpR[k][l + 1])
                        MI[i][k] = -1;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5;j++)
        {
            cout << MI[i][j] << ' ';
        } cout << endl;
    }
}
void IncToSm(int a[][5]) {

    int MS[5][5] = { {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0} };;
    int SpR[5][2] = { {2, 1},
                      {3, 2},
                      {4, 3},
                      {5, 4},
                      {3, 5}, };
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5;j++)
        {
            if (a[i][j] != 0) for (int k = 0; k < 5; k++)
            {
                if (k == j)
                {
                    int t1 = 0, t2 = 0;
                    for (int l = 0; l < 1;l++)
                    {
                        t1 = SpR[k][l];
                        t2 = SpR[k][l + 1];
                        MS[t1 - 1][t2 - 1] = 1; MS[t2 - 1][t1 - 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5;j++)
        {
            cout << MS[i][j] << ' ';
        } cout << endl;
    }
}
int main()

{
    setlocale(LC_ALL, "Russian");
    int MatSm[5][5] = { {0, 1, 0, 0, 0},
                         {1, 0, 1, 0, 0},
                         {0, 1, 0, 1, 1},
                         {0, 0, 1, 0, 1},
                         {0, 0, 1, 1, 0} };
    int MatInc[5][5] = { {-1, 0, 0, 0, 0},
                        {1, -1, 0, 0, 0},
                        {0, 1, -1, 0, 1},
                        {0, 0, 1, -1, 0},
                        {0, 0, 0, 1, -1} };
    cout << "Матрица инцидентности из матрицы смежности" << endl;
    SmToInc(MatSm);
    cout << "Матрица смежности из матрицы инцидентности" << endl;
    IncToSm(MatInc);
    return 0;
}