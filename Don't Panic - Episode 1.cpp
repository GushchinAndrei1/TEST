#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nb_floors; // колличесвто этажей
    int width; // количнство позиций на этаже
    int nb_rounds; // максимальное число раундов
    int exit_floor; // этаж на котором находится выход
    int exit_pos; // похиция выхода на этом этаже
    int nb_total_clones; // общее количество клонов
    int nb_additional_elevators; // игонор, всегда 0
    int nb_elevators; // количество лифтов
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();

    // ограничения, можно было не писать
    if (nb_floors < 1 || nb_floors > 15) return 0;
    if (width < 5 || width > 100) return 0; // в данном эпизоде не используется
    if (nb_rounds < 10 || nb_rounds > 200) return 0; // в данном эпизоде не используется
    if (exit_floor < 0 || exit_floor >= nb_floors) return 0;
    if (exit_pos < 0 || exit_pos > width) return 0; // в данном эпизоде не используется
    if (nb_total_clones < 2 || nb_total_clones > 50) return 0; // в данном эпизоде не используется
    if (nb_elevators < 0 || nb_elevators > 100) return 0;



    // цикл для ввода этажей и лифтов на нем
    vector<int> elevatorPos(nb_floors, -1);
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // этажи на котором находится лифт
        int elevator_pos; // позиция лифта
        cin >> elevator_floor >> elevator_pos; cin.ignore();

        // проверяем позицию этажа и записываем в вектор elevatorPos
        if (elevator_floor >= 0 && elevator_floor < nb_floors) {
            elevatorPos[elevator_floor] = elevator_pos;
            continue;
        }
    }


    while (1) {
        int clone_floor; // этаж на котором находится ведущий клон
        int clone_pos; // позиция на котором находится ведущий клон
        string direction; // направление движеня ведущего клона
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();

        // ограничения 
        if (clone_floor < -1 || clone_floor >= nb_floors) return 0;
        if (clone_pos < -1 || clone_pos >= width) return 0; // в данном эпизоде не используется

        // если клона нет, то ждем его
        if (clone_floor == -1) {
            cout << "WAIT" << endl;
            continue;
        }
        // выбираем цель клона
        int target;
        if (clone_floor == exit_floor) { // если клон находится на этаже с выходом, то цель - позиция выхода exit_pos
            target = exit_pos;
        }
        else { // иначе цель - позиция лифта
            target = elevatorPos[clone_floor];
        }
        // если цели нет, то ЖДЕМ
        if (target == -1) {
            cout << "WAIT" << endl;
            continue;
        }
        // блокируем клона если его направление  не в сторону лифта или выхода
        if ((direction == "LEFT" && clone_pos < target) || (direction == "RIGHT" && clone_pos > target)) {
            cout << "BLOCK" << endl;
        }
        // иначе ждем
        else {
            cout << "WAIT" << endl;
        }

    }
}
