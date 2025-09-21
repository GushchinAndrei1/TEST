#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w; // ширина задания
    int h; // высота здания
    cin >> w >> h; cin.ignore(); // ввод парамтреов
    int n; // max число ходов
    cin >> n; cin.ignore(); // ввод парамтеров
    int x0; // нач. координата по горизонтали 
    int y0; // нач. координата по вертикали 
    cin >> x0 >> y0; cin.ignore(); // ввод координат

    int left = 0; // крайнее левое положение
    int right = w - 1; // крайнее правое положение (-1 так как отсчет с нуля)
    int upper = 0; // крайнее верхнее положение
    int bottom = h - 1; // крайнее нижнее положение (-1 так как отсчет с нуля)



    while (1) {
        string bomb_dir; // (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        if (bomb_dir.find('U') != string::npos) { // условынй оператор, отсекам нижнюю часть, функция find ищет в строке U, UR, R, DR, D, DL, L or UL
            bottom = y0 - 1;
        }
        if (bomb_dir.find('R') != string::npos) { // условынй оператор, отсекам левую часть
            left = x0 + 1;
        }
        if (bomb_dir.find('D') != string::npos) { // условынй оператор, отсекам верхнюю часть
            upper = y0 + 1;
        }
        if (bomb_dir.find('L') != string::npos) { // условынй оператор, отсекам правую часть
            right = x0 - 1;
        }

        x0 = (right + left) / 2; // расчет новых координат по принципу бинарного посика, каждый раз прыгаем к центру
        y0 = (bottom + upper) / 2;


        cout << x0 << " " << y0 << endl; // вывод новых координат для последующего посика
    }
}