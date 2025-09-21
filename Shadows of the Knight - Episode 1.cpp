#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w; // ������ �������
    int h; // ������ ������
    cin >> w >> h; cin.ignore(); // ���� ����������
    int n; // max ����� �����
    cin >> n; cin.ignore(); // ���� ����������
    int x0; // ���. ���������� �� ����������� 
    int y0; // ���. ���������� �� ��������� 
    cin >> x0 >> y0; cin.ignore(); // ���� ���������

    int left = 0; // ������� ����� ���������
    int right = w - 1; // ������� ������ ��������� (-1 ��� ��� ������ � ����)
    int upper = 0; // ������� ������� ���������
    int bottom = h - 1; // ������� ������ ��������� (-1 ��� ��� ������ � ����)



    while (1) {
        string bomb_dir; // (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        if (bomb_dir.find('U') != string::npos) { // �������� ��������, ������� ������ �����, ������� find ���� � ������ U, UR, R, DR, D, DL, L or UL
            bottom = y0 - 1;
        }
        if (bomb_dir.find('R') != string::npos) { // �������� ��������, ������� ����� �����
            left = x0 + 1;
        }
        if (bomb_dir.find('D') != string::npos) { // �������� ��������, ������� ������� �����
            upper = y0 + 1;
        }
        if (bomb_dir.find('L') != string::npos) { // �������� ��������, ������� ������ �����
            right = x0 - 1;
        }

        x0 = (right + left) / 2; // ������ ����� ��������� �� �������� ��������� ������, ������ ��� ������� � ������
        y0 = (bottom + upper) / 2;


        cout << x0 << " " << y0 << endl; // ����� ����� ��������� ��� ������������ ������
    }
}