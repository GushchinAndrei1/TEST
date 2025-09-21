#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string message;
    getline(cin, message); // считываем строку

    string binary = "";
    // преобразуем каждый символ в 7 битное предствление
    for (char c : message) {
        for (int i = 6; i >= 0; i--) {
            binary += ((c >> i) & 1) ? '1' : '0'; // тернарный оператор, добавляем в строку 0 или 1
        }
    }
    int j = 0;
    string answer = "";
    // цикл для преобразования бинарной строки в унарный код
    while (j < binary.size()) {
        char bit = binary[j];
        int count = 0;
        // подсчет одинковых подряд битов
        while (j + count < binary.size() && binary[count + j] == bit) {
            count++;
        }
        // если бит равен 1, первая часть блока 0
        if (bit == '1') {
            answer += "0 ";
        }
        // если бит равен 0, первая часть блока 00
        else {
            answer += "00 ";
        }
        // вторая часть блока, количество нулей равное длине серии одинковых битов
        answer += string(count, '0');
        j += count; // переход к следующей серии
        // пробел между сериями 
        if (j < binary.size()) answer += " ";


    }
    // вывод унарного кода 
    cout << answer << endl;
}