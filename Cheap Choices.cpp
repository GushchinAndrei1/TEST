#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// ��������� ��� �������� ������ 
struct Item {
    string category;
    string size;
    int price = 0;
    bool sold = false;

};

int main()
{
    int c;
    cin >> c; cin.ignore(); // ���������� �������
    int p;
    cin >> p; cin.ignore(); // ���������� ����������� 

    vector<Item> items; // ������ ��� �������� �������

    // ��������� ������
    for (int i = 0; i < c; i++) {
        string line;
        getline(cin, line); // ������ ������ �������
        stringstream ss(line); // ����� ������ ����� ����� ������ ������ �� �����

        Item item; // �������� ����������
        ss >> item.category >> item.size >> item.price; // ������������ ������ �� ������ 
        items.push_back(item); // ������ ������ � ������ items
    }
    // �������� ������
    for (int i = 0; i < p; i++) {
        string order;
        getline(cin, order); // ������ ������ �������
        stringstream ss(order); // ����� ������ ����� ����� ������ ������ �� �����

        string category1; // �����
        string size1; // �����
        ss >> category1 >> size1; // ��������� �� ������ ��������� � ������

        int bestPrice = 1000000000; // ������ ������� ������� ����� ����� ����� ����������
        int bestIndex = -1; // ���� ����� ���

        // ������� ���� �������
        for (int j = 0; j < (int)items.size(); j++) {
            // ����� �� ������, ��������� ��������� � ������
            if (!items[j].sold && items[j].category == category1 && items[j].size == size1) {
                // ���� ���� ������ ����������, �� ��������� ���� � ������
                if (items[j].price < bestPrice) {
                    bestPrice = items[j].price;
                    bestIndex = j;
                }
            }
        }
        // ���� ����� �� ������, �� ������� NONE
        if (bestIndex == -1) {
            cout << "NONE" << endl;
        }
        // ���� ����� ������ ������� ���� � � ������� �������� ����� ��� ��������� 
        else {
            cout << items[bestIndex].price << endl;
            items[bestIndex].sold = true;
        }
    }
}