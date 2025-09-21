#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // количество температур для анализа
    cin >> n; cin.ignore();
    int closestToZero = 5527; // инициализируем переменную максимальной температураой 5526, 
    // любая введённая температура будет ближе к нулю, чем 5527
    for (int i = 0; i < n; i++) {
        int t; // текущая температура (от -273 до 5526)
        cin >> t; cin.ignore();

        // Если новая температура ближе к нулю или равна по модулю и положительная
        if (abs(t) < abs(closestToZero) || (abs(t) == abs(closestToZero) && t > closestToZero)) {
            closestToZero = t; //  обновляем closestToZero. 
        }
        if (n == 0)
            cout << 0 << endl;  // если температуры не заданы, то выводим 0
        else

            cout << closestToZero << endl; // выводим температуры ближайшую к нулю
    }