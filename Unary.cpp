#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string message;
    getline(cin, message); // ��������� ������

    string binary = "";
    // ����������� ������ ������ � 7 ������ ������������
    for (char c : message) {
        for (int i = 6; i >= 0; i--) {
            binary += ((c >> i) & 1) ? '1' : '0'; // ��������� ��������, ��������� � ������ 0 ��� 1
        }
    }
    int j = 0;
    string answer = "";
    // ���� ��� �������������� �������� ������ � ������� ���
    while (j < binary.size()) {
        char bit = binary[j];
        int count = 0;
        // ������� ��������� ������ �����
        while (j + count < binary.size() && binary[count + j] == bit) {
            count++;
        }
        // ���� ��� ����� 1, ������ ����� ����� 0
        if (bit == '1') {
            answer += "0 ";
        }
        // ���� ��� ����� 0, ������ ����� ����� 00
        else {
            answer += "00 ";
        }
        // ������ ����� �����, ���������� ����� ������ ����� ����� ��������� �����
        answer += string(count, '0');
        j += count; // ������� � ��������� �����
        // ������ ����� ������� 
        if (j < binary.size()) answer += " ";


    }
    // ����� �������� ���� 
    cout << answer << endl;
}