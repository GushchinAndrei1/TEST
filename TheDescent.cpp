#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // // ���������� ������������ ��� std, ����� �� ������ std:: ������ ���

int main()
{
    while (1) {

        int maximumeHight = -1; // "- 1" ��� ��� ����� ����� � ����� ������ ���� ����� ������� ���������� 
        int maximumIndex = 0; // � ��� ��������� ����� ���������� ������ ����� ������� ����

        // // ������ ������ 8 ��� � �����
        for (int i = 0; i < 8; i++) {
            int mountainH;
            cin >> mountainH; cin.ignore();
            // ���� ������� ���� ���� ���������, �� ���������� ������
            if (mountainH > maximumeHight) {
                maximumeHight = mountainH;
                maximumIndex = i;
            }
        }
        // �������� � ������ ����� ������� ����
        cout << maximumIndex << endl;
    }
}