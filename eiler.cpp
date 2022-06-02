#include <iostream>
#include <Windows.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 6;
    int MatSm[n][n] = { 0 };
    int col[n];
    int ost[n - 1][2];
    int i, j, v, c, min, ind1, ind2;
    cout << "Введите весовую матрицу 6х6:";
    for (i = 0;i < n;i++)
        for (j = 0;j < n;j++)
            cin >> MatSm[i][j]; //ввод матрицы
    for (i = 0;i < n;i++) col[i] = i;
    for (v = 0; v < n - 1;v++)
    {
        min = INT_MAX;
        for (i = 0;i < n;i++)
            for (j = 0;j < n;j++)
                if (col[i] != col[j] && MatSm[i][j] < min && MatSm[i][j] != 0) //находим ребро с минимальным весом, одна из вершин которого еще не перекрашена 
                {
                    min = MatSm[i][j]; ind1 = i;ind2 = j; //запоминаем минимальный вес и индексы вершин ребра
                }
        ost[v][0] = ind1 + 1;ost[v][1] = ind2 + 1; //добавляем ребро к остовному дереву
        c = col[ind2];
        for (i = 0;i < n;i++)
            if (col[i] == c) col[i] = col[ind1];//перекрашиваем вторую вершину в цвет первой
    }
    cout << "Остовное дерево:";
    for (int i = 0; i < n - 1; i++)
        cout << "{" << ost[i][0] << "," << ost[i][1] << "}, ";
    return 0;
}