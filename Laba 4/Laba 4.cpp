#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int m, n;

const int height = 10;
const int weight = 40;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };

//Проверка, является ли введенное число типом инт
bool is_number(char number[]) {
    for (int i = 0; i < 100; i++) {
        if ((char)number[i] != -52 && number[i] != '\0') {
            if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]))
                return false;
        }
        else
            return true;
    }
}
//Перевод из чар числа в инт число
int char_to_int(char number[]) {
    int number_of_digits = 0;

    for (int i = 0; number[i] != '\0'; i++) {
        if ((char)number[i] != -52) {
            number_of_digits++;
        }
    }

    if (number_of_digits == 1) {
        return ((char)(number[0] - 48));
    }
    if (number_of_digits == 2) {
        return ((char)(number[0] - 48) * 10 + (char)(number[1] - 48));
    }
    if (number_of_digits == 3) {
        return (((char)(number[0] - 48) * 100) + (((char)(number[1])) - 48) * 10 + (char)(number[2]) - 48);
    }
}

int rec(int m, int n) {
	if (m == n && n == 0) return 1;
	else
		if (m == n) return 1;
		else
			if (m > 0 && m < n)
				return (rec(m, n - 1) + rec(m - 1, n - 1));
}

void frame(const int height, const int weight) {
    for (int i = 0; i <= weight; i++) {
        cout << "-";
    }
    cout << "\n";
    for (int i = 0; i < height - 2; i++) {
        for (int j = 0; j <= weight; j++) {
            if (j == 0 || j == weight) cout << "|";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i <= weight; i++) {
        cout << "-";
    }
}
void inputData(int &_m, int &_n, const int height, const int weight, COORD position, HANDLE hConsole) {
    char m[20];
    char n[20];

    frame(height, weight);

    position = { 5, 3 };
    SetConsoleCursorPosition(hConsole, position);

    cout << "write m: ";
    cin >> m;

    while (!is_number(m) || char_to_int(m) < 0) {
        system("cls");
        frame(height, weight);

        position = { 10, 1 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Error. Write again";

        position = { 5, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "write m: ";

        cin >> m;
    }

    _m = char_to_int(m);

    position = { 5, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "write n: ";
    cin >> n;

    while (!is_number(n) || (char_to_int(n) < char_to_int(m))) {
        system("cls");
        frame(height, weight);

        position = { 5, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "write m: " << m;


        position = { 5, 1 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Error. Write again: ";

        position = { 5, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "write n: ";
        cin >> n;
    }

    _n = char_to_int(n);

    position = { 0, 9 };
    SetConsoleCursorPosition(hConsole, position);
}
void showAnswer(int m, int n, const int height, const int weight, COORD position, HANDLE hConsole) {
    system("cls");
    frame(height, weight);

    position = { 5, 2 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "M: " << m;

    position = { 5, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "N: " << n;

    position = { 5, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "rec: " << rec(m, n);

}
void mainScreen(const int height, const int weight, COORD position, HANDLE hConsole) {
    frame(height, weight);
    position = { 15, 3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Программа";

    position = { 10, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Рекурсивные вычисления";

    position = { 14, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Группа 1092";

    position = { 9, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Рыбаков Павел Алексеевич";

    position = { 3, 8 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Enter - continue         Esc - exit";

    position = { 0, 9 };
    SetConsoleCursorPosition(hConsole, position);
}

void lifeCycle(int m, int n, const int height, const int weight, COORD position, HANDLE hConsole) {

    bool life_cycle = true;
    char choise;

    do {
        //ASCII "Esc" = 27, ASCII "Enter" = 13;
        system("cls");
        mainScreen(height, weight, position, hConsole);

        life_cycle = ((choise = _getch()) == 27) ? 0 : 1;

        if (choise == 27) {
            life_cycle = false;
            system("cls");
        }
        else if (choise == 13) {
            system("cls");
            inputData(m, n, height, weight, position, hConsole);

            cout << "\n\nPress any key to the continue";
            _getch();

            showAnswer(m, n, height, weight, position, hConsole);
            cout << "\n\n\n\n\nPress any key to the continue";
            _getch();

        }
        else {
            system("cls");
        }

    } while (life_cycle);


}

int main(){
	setlocale(LC_ALL, "rus");

    lifeCycle(m, n, height, weight, position, hConsole);

	return 0;
}