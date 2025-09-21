#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int light_x; // ��������� �� ��� � ��������� ����
    int light_y; // ��������� �� ��� � ��������� ���� 
    int initial_tx; // ��������� ������� ���� �� ��� �
    int initial_ty; // ��������� ������� ���� �� ��� �
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore(); // ��������� ��������� ������


    while (1) {
        int remainingTurns; // ���������� ���������� �����, ������� ��� ����� �������
        cin >> remainingTurns; cin.ignore();

        string move = ""; // ������ ��� �������� ����������� �������� ����

        if (initial_ty > light_y) move += "N"; // ���� ��� ���� �����, ���� �� �����
        else if (initial_ty < light_y) move += "S"; // ���� ��� ���� �����, ���� �� ��


        if (initial_tx > light_x) move += "W"; // ���� ��� ������ �����, ���� �� �����
        else if (initial_tx < light_x) move += "E"; // ���� ��� ����� �����, ���� �� ������

        // ��������� ���������� ���� ����� ��������
        if (move.find('N') != string::npos) initial_ty--; // �������� ��� �� 1 ������ �����
        if (move.find('S') != string::npos) initial_ty++; // �������� ��� �� 1 ������ ����
        if (move.find('W') != string::npos) initial_tx--; // �������� ��� �� 1 ������ �����
        if (move.find('E') != string::npos) initial_tx++; // �������� ��� �� 1 ������ ������

        cout << move << endl; // ����� ����������� �������� ��� �������� ����
    }
}
