#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // общее количество узлов включая шлюзы
    int l; // количество связей
    int e; // количество шлюзов
    cin >> n >> l >> e;

    // создаем векор, который хранит два связанных узла
    vector<pair<int, int>> links;
    for (int i = 0; i < l; i++) {
        int n1; // первый узел
        int n2; // второй узел
        cin >> n1 >> n2;
        links.push_back({ n1, n2 }); // push_back добавляет пару узлов в вектор links
    }
    // создаем вектор для хранения шлюзов
    vector<int> gateways;
    for (int i = 0; i < e; i++) {
        int ei; // индекс узла шлюза
        cin >> ei;
        gateways.push_back(ei); // push_back добавляет индекс шлюза в вектор geteways
    }

    // основной игровой цикл
    while (1) {
        int si; // индекс узла где находится агент
        cin >> si;


        bool cut = false; // флаг, показывает разрыв связи, false - разрыв еще не произошел
        // проверяем есть ли связь между агентом и шлюзом, если есть - разрываем ее
        for (pair<int, int> link : links) {
            // проходим по каждому шлюзу
            for (int g : gateways) {
                // проверка на связи между агентом и шлюзом
                if ((link.first == si && link.second == g) || (link.first == g && link.second == si)) {
                    // если есть такая связь, то вывод
                    cout << link.first << " " << link.second << endl;

                    // удаляем связь (т.е. пару узлов)
                    // сдвигаем все пары, не равные link, в начало вектора и возвращает итератор на начало "хвоста" ненужных элементов
                    vector<pair<int, int>>::iterator newEnd = remove(links.begin(), links.end(), link);
                    // c помощью erase удаляем все элементы в диапазоне от newEnd до links.end()
                    links.erase((newEnd), links.end());
                    cut = true; // разрыв произошел
                    break; // выход из цикла
                }
            }
            if (cut) break; // если связь разорвана - выходим из цикла 
        }
        // если связи агент - шлюз нет, то ужадаляем связь шлюз - узел 
        // если разрыв еще не произошел
        if (!cut) {
            // проходим по каждому шлюзу
            for (auto link : links) {
                // проходим по каждому шлюзу
                for (int g : gateways) {
                    // если первый узел шлюз или второй узел шлюз 
                    if (link.first == g || link.second == g) {
                        // если есть такая связь, то вывод
                        cout << link.first << " " << link.second << endl;
                        // удаляем связь
                        // сдвигаем все пары, не равные link, в начало вектора и возвращает итератор на начало "хвоста" ненужных элементов
                        vector<pair<int, int>>::iterator newEnd = remove(links.begin(), links.end(), link);
                        // c помощью erase удаляем все элементы в диапазоне от newEnd до links.end()
                        links.erase(newEnd, links.end());
                        cut = true; // разрыв произошел
                        break; // выход из цикла
                    }
                }
                if (cut) break; // если связь разорвана выходим из цикла 
            }
        }

    }
}
