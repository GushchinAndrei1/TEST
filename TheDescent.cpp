#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // // используем пространство имён std, чтобы не писать std:: каждый раз

int main()
{
    while (1) {

        int maximumeHight = -1; // "- 1" так как нужно чтобы в цикле первая гора стала текущим максимумом 
        int maximumIndex = 0; // в эту перменную будем записывать индекс самой высокой горы

        // // читаем высоты 8 гор с входа
        for (int i = 0; i < 8; i++) {
            int mountainH;
            cin >> mountainH; cin.ignore();
            // если текущая гора выше найденной, то онбновляем индекс
            if (mountainH > maximumeHight) {
                maximumeHight = mountainH;
                maximumIndex = i;
            }
        }
        // стреляем в индекс самой высокой горы
        cout << maximumIndex << endl;
    }
}