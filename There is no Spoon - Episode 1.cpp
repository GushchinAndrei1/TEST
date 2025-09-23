#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width; // количество клеток по оси Х
    cin >> width; cin.ignore();
    int height; // количество клеток по оси Y
    cin >> height; cin.ignore();

    // будем хранить сетку как список строк
    vector<string> grid(height); // создаем вектор для хранения строк
    // с помощью цикла for читаем каждую строку и записываем в вектор
    for (int i = 0; i < height; i++) {
        getline(cin, grid[i]); // каждая строка может содержать узел - "0" и пустую клетку "."
    }
    // перебираем все клетки
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == '0') {
                // если нашли узел, то фиксируем его координаты
                int x1 = x;
                int y1 = y;

                // ищем ближайший узел справа, если его нет, то тогда координаты  x2 = -1 и y2 = -1 
                int x2 = -1;
                int y2 = -1;
                for (int ix = x + 1; ix < width; ix++) {
                    if (grid[y][ix] == '0') {
                        // если нашли узел, то фиксируем его координаты
                        x2 = ix;
                        y2 = y;
                        break; // выходим из цикла 
                    }
                }

                // ищем ближайший узел снизу, если его нет, то тогда координаты  x3 = -1 и y3 = -1 
                int x3 = -1;
                int y3 = -1;
                for (int iy = y + 1; iy < height; iy++) {
                    if (grid[iy][x] == '0') {
                        //если нашли узел, то фиксируем его координаты
                        x3 = x;
                        y3 = iy;
                        break; // выходим из цикла
                    }
                }
                // резульут в виде строки координат
                cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            }
        }
    }
}