#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// структура для описания товара 
struct Item {
    string category;
    string size;
    int price = 0;
    bool sold = false;

};

int main()
{
    int c;
    cin >> c; cin.ignore(); // количество товаров
    int p;
    cin >> p; cin.ignore(); // количество покупателей 

    vector<Item> items; // вектор для хранения товаров

    // считываем товары
    for (int i = 0; i < c; i++) {
        string line;
        getline(cin, line); // чтение строки товаров
        stringstream ss(line); // класс потока чтобы потом разить строку на части

        Item item; // создания экземпляра
        ss >> item.category >> item.size >> item.price; // вытаскивание ланных из потока 
        items.push_back(item); // запись товара в вектор items
    }
    // считывем заказы
    for (int i = 0; i < p; i++) {
        string order;
        getline(cin, order); // чтение строки заказов
        stringstream ss(order); // класс потока чтобы потом разить строку на части

        string category1; // заказ
        string size1; // заказ
        ss >> category1 >> size1; // извлекаем из строки категорию и размер

        int bestPrice = 1000000000; // ставим заранее большое число чтобы потом сравнивать
        int bestIndex = -1; // если товра нет

        // перебор всех товаров
        for (int j = 0; j < (int)items.size(); j++) {
            // товар не продан, совпадает категория и размер
            if (!items[j].sold && items[j].category == category1 && items[j].size == size1) {
                // если цена меньше предыдущий, то обнавляем цену и индекс
                if (items[j].price < bestPrice) {
                    bestPrice = items[j].price;
                    bestIndex = j;
                }
            }
        }
        // если товар не найден, то выводим NONE
        if (bestIndex == -1) {
            cout << "NONE" << endl;
        }
        // если товар найден выводим цену и в векторе помечаем товар как проданный 
        else {
            cout << items[bestIndex].price << endl;
            items[bestIndex].sold = true;
        }
    }
}