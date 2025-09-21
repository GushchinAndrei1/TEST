#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int light_x; // положение по оси Х источника силы
    int light_y; // положение по оси У источника силы 
    int initial_tx; // начальная позиция Тора по оси Х
    int initial_ty; // начальная позиция Тора по оси У
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore(); // считываем начальные данные


    while (1) {
        int remainingTurns; // оставшееся количество ходов, которое Тор может сделать
        cin >> remainingTurns; cin.ignore();

        string move = ""; // строка для хранения направления движения Тора

        if (initial_ty > light_y) move += "N"; // если Тор выше света, идем на север
        else if (initial_ty < light_y) move += "S"; // если Тор ниже света, идем на юг


        if (initial_tx > light_x) move += "W"; // если Тор правее света, идем на запад
        else if (initial_tx < light_x) move += "E"; // если Тор левее света, идем на восток

        // обновляем координаты Тора после движения
        if (move.find('N') != string::npos) initial_ty--; // сдвигаем Тор на 1 клетку вверх
        if (move.find('S') != string::npos) initial_ty++; // сдвигаем Тор на 1 клетку вниз
        if (move.find('W') != string::npos) initial_tx--; // сдвигаем Тор на 1 клетку влево
        if (move.find('E') != string::npos) initial_tx++; // сдвигаем Тор на 1 клетку вправо

        cout << move << endl; // вывод направление движения для текущего хода
    }
}
