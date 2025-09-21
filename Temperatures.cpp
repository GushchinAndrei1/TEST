#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // ���������� ���������� ��� �������
    cin >> n; cin.ignore();
    int closestToZero = 5527; // �������������� ���������� ������������ ������������� 5526, 
    // ����� �������� ����������� ����� ����� � ����, ��� 5527
    for (int i = 0; i < n; i++) {
        int t; // ������� ����������� (�� -273 �� 5526)
        cin >> t; cin.ignore();

        // ���� ����� ����������� ����� � ���� ��� ����� �� ������ � �������������
        if (abs(t) < abs(closestToZero) || (abs(t) == abs(closestToZero) && t > closestToZero)) {
            closestToZero = t; //  ��������� closestToZero. 
        }
        if (n == 0)
            cout << 0 << endl;  // ���� ����������� �� ������, �� ������� 0
        else

            cout << closestToZero << endl; // ������� ����������� ��������� � ����
    }