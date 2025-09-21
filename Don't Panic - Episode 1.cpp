#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nb_floors; // ����������� ������
    int width; // ���������� ������� �� �����
    int nb_rounds; // ������������ ����� �������
    int exit_floor; // ���� �� ������� ��������� �����
    int exit_pos; // ������� ������ �� ���� �����
    int nb_total_clones; // ����� ���������� ������
    int nb_additional_elevators; // ������, ������ 0
    int nb_elevators; // ���������� ������
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();

    // �����������
    if (nb_floors < 1 || nb_floors > 15) return 0;
    if (width < 5 || width > 100) return 0; // � ������ ������� �� ������������
    if (nb_rounds < 10 || nb_rounds > 200) return 0; // � ������ ������� �� ������������
    if (exit_floor < 0 || exit_floor >= nb_floors) return 0;
    if (exit_pos < 0 || exit_pos > width) return 0; // � ������ ������� �� ������������
    if (nb_total_clones < 2 || nb_total_clones > 50) return 0; // � ������ ������� �� ������������
    if (nb_elevators < 0 || nb_elevators > 100) return 0;



    // ���� ��� ����� ������ � ������ �� ���
    vector<int> elevatorPos(nb_floors, -1);
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // ����� �� ������� ��������� ����
        int elevator_pos; // ������� �����
        cin >> elevator_floor >> elevator_pos; cin.ignore();

        // ��������� ������� ����� � ���������� � ������ elevatorPos
        if (elevator_floor >= 0 && elevator_floor < nb_floors) {
            elevatorPos[elevator_floor] = elevator_pos;
            continue;
        }
    }


    while (1) {
        int clone_floor; // ���� �� ������� ��������� ������� ����
        int clone_pos; // ������� �� ������� ��������� ������� ����
        string direction; // ����������� ������� �������� �����
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();

        // ����������� 
        if (clone_floor < -1 || clone_floor >= nb_floors) return 0;
        if (clone_pos < -1 || clone_pos >= width) return 0; // � ������ ������� �� ������������

        // ���� ����� ���, �� ���� ���
        if (clone_floor == -1) {
            cout << "WAIT" << endl;
            continue;
        }
        // �������� ���� �����
        int target;
        if (clone_floor == exit_floor) { // ���� ���� ��������� �� ����� � �������, �� ���� - ������� ������ exit_pos
            target = exit_pos;
        }
        else { // ����� ���� - ������� �����
            target = elevatorPos[clone_floor];
        }
        // ���� ���� ���, �� ����
        if (target == -1) {
            cout << "WAIT" << endl;
            continue;
        }
        // ��������� ����� ���� ��� �����������  �� � ������� ����� ��� ������
        if ((direction == "LEFT" && clone_pos < target) || (direction == "RIGHT" && clone_pos > target)) {
            cout << "BLOCK" << endl;
        }
        // ����� ����
        else {
            cout << "WAIT" << endl;
        }

    }
}