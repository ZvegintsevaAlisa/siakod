#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <vector>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 6;
    int MatSm[n][n] = { {0, 7, 9, 0, 0, 14},
                       {7, 0, 10, 15, 0, 0},
                       {9, 10, 0, 11, 0, 2},
                       {0, 15, 11, 0, 6, 0},
                       {0, 0, 0, 6, 0, 9},
                       {14, 0, 2, 0, 9, 0} };
    int Fl[n][n] = { 0 };
    int path[n][n];
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0;j < n;j++) //матрица путей
        {
            path[i][j] = j + 1;
        }
    for (i = 0; i < n; i++)
        for (j = 0;j < n;j++)
            if (MatSm[i][j] == 0 && i != j)
                Fl[i][j] = 999;
            else
                Fl[i][j] = MatSm[i][j];
    for (i = 0; i < n; i++) //проверяем, не короче ли пути напрямую путь из j в k через i 
        for (j = 0;j < n;j++)
            for (k = 0;k < n;k++)
                if (Fl[j][i] + Fl[i][k] < Fl[j][k]) //если да, то меняем вес пути в матрице и в матрице путей запоминаем, через какую вершину i нашли путь  
                {
                    Fl[j][k] = Fl[j][i] + Fl[i][k];
                    path[j][k] = i + 1;
                }
    cout << "Матрица длин кратчайших путей:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0;j < n;j++)
            cout << Fl[i][j] << " ";
        cout << endl;
    }
    cout << "Матрица путей:" << endl; 
    for (i = 0; i < n; i++)
    {
        for (j = 0;j < n;j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    return 0;
}