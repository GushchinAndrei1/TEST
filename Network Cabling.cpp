#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore(); // ���-�� ������
    vector<long long> X(n); // ������������ ������ ���������� x
    vector<long long> Y(n); // ������������ ������ ���������� y

    // ���� ��� ���������� �������� ������
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        X[i] = x; // ��������� X ���������� i-�� ������
        Y[i] = y; // ��������� Y ���������� i-�� ������
    }

    // ������� ����������� � ������������ �
    long long minX = *min_element(X.begin(), X.end());
    long long maxX = *max_element(X.begin(), X.end());

    // ����� ��������������� ������ ��������� ��� �������� ����� �������� ��������
    long long lengthHorizont�able = abs(maxX - minX);

    /// ���������� �������� ��������������� ������ �� ����������� ������� ��������� ������ �����
    sort(Y.begin(), Y.end());
    long long medianY = Y[n / 2];

    long long lengthVerticalCable = 0; // ������������� ���������� ��� ������������� ������

    // ������� ����� ���� ������������ ������� 
    for (int i = 0; i < n; i++) {
        lengthVerticalCable += llabs(Y[i] - medianY);
    }
    // �������� �����
    long long L = lengthVerticalCable + lengthHorizont�able;
    cout << L << endl;
}