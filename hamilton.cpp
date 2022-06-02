#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <vector>

using namespace std;
vector <bool> vis;
vector <int> path;
bool hmltn(int curr) {
    int const n = 6;
    int M[n][n] = { {0, 1, 0, 1, 1, 1},
                       {1, 0, 1, 1, 1, 0},
                       {0, 1, 0, 1, 1, 0},
                       {1, 1, 1, 0, 0, 1},
                       {1, 1, 1, 0, 0, 0},
                       {1, 0, 0, 1, 0, 0} };
    path.push_back(curr);//добавляем вершину  в вектор
    if (path.size() == n) //проверяем, не получен ли полный цикл(если в вектор вошли все вершины и между 1 и последней есть ребро)
        if (M[path[0]][path.back()] == 1)
            return true;
        else {
            path.pop_back();
            return false;
        }
    vis[curr] = true;
    for (int nxt = 0;nxt < n; nxt++)
        if (M[curr][nxt] == 1 && !vis[nxt]) //проверяем, есть ли цикл через соседние непосещенные вершины
            if (hmltn(nxt)) return true;
    vis[curr] = false; //если цикла нет, то отмечаем вершину непосещенной и удаляем из вектора 
    path.pop_back();
    return false;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 6;
    int MatSm[n][n] = { {0, 1, 0, 1, 1, 1},
                       {1, 0, 1, 1, 1, 0},
                       {0, 1, 0, 1, 1, 0},
                       {1, 1, 1, 0, 0, 1},
                       {1, 1, 1, 0, 0, 0},
                       {1, 0, 0, 1, 0, 0} };
    for (int i = 0; i < n; i++)
        vis.push_back(false);
    for (int i = 0; i < n; i++)
        hmltn(i);
    cout << "Гамильтонов цикл:";
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " -> ";
    cout << path[0];
    return 0;
}