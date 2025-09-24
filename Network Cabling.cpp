#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore(); // кол-во зданий
    vector<long long> X(n); // диначмичекий массив координаты x
    vector<long long> Y(n); // диначмичекий массив координаты y

    // цикл для считывания координт зданий
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        X[i] = x; // сохраняем X координату i-го здания
        Y[i] = y; // сохраняем Y координату i-го здания
    }

    // находим минимальный и максимальный Х
    long long minX = *min_element(X.begin(), X.end());
    long long maxX = *max_element(X.begin(), X.end());

    // длина горизонатльного кабеля считается как разность между крайними зданиями
    long long lengthHorizontСable = abs(maxX - minX);

    /// Определяем ординату горизонатльного кабеля по определению медианы конечного списка чисел
    sort(Y.begin(), Y.end());
    long long medianY = Y[n / 2];

    long long lengthVerticalCable = 0; // инициализация переменной для вертикального кабеля

    // подсчет суммы длин вертикальных кабелей 
    for (int i = 0; i < n; i++) {
        lengthVerticalCable += llabs(Y[i] - medianY);
    }
    // итоговая длина
    long long L = lengthVerticalCable + lengthHorizontСable;
    cout << L << endl;
}