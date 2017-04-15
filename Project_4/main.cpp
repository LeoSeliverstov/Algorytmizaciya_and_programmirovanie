#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

void keyboard_enter(int M[25]) {
    int i;
    for (i = 0; i < 25; i++) {
        cout << "Введите " << i << " элемент массива: ";
        cin >> M[i];
    }

    cout << "\nМассив:\n";
    for (i = 0; i < 25; i++) {
        cout << " " << M[i];
    }

}

void file_enter(int M[25]) {
    int i;
    std::ifstream file("massiv1.txt");
    for (i = 0; i < 25; i++) {
        file >> M[i];
    }

    cout << "\nМассив:\n";
    for (i = 0; i < 25; i++) {
        cout << " " << M[i];
    }

}

void change(int M[25]) {
    int i;
    cout << "Введите номер элемента: ";
    cin>>i;
    cout << "Введите новое значение элемента: ";
    cin >> M[i];

    cout << "\nМассив:";
    for (i = 0; i < 25; i++) {
        cout << " " << M[i];
    }
}

void srednee(int M[25]) {
    int sum = 0;
    int sredn = 0;
    int i;
    for (i = 0; i < 25; i++) {
        sum += M[i];
    }
    sredn = (sum) / 25;
    cout << "\nSredn: " << sredn;
    FILE *f2;
    f2 = fopen("srednee.txt", "w");
    fprintf(f2, "\n %d", sredn);
    fclose(f2);
}

void save(int M[25]) {
    FILE *f1;
    f1 = fopen("massiv2.txt", "w");
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            fprintf(f1, "  %d", M[k + (j * 5)]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout << "\nПроизведена запись в файл.";
}

int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "Russian");
    int i, sw, sw1, c1 = 1, sum, sredn, s1 = 0, s2 = 0, s3 = 0, M[25];
    printf("\n\nМЕНЮ:\n1) Ввести массив с клавиатуры\n2) Чтение массива из файла\n\n");

    while (c1) {
        cout << "\nВведите команду: ";
        cin>>sw1;
        switch (sw1) {
            case 1:
                keyboard_enter(M);
                c1 = 0;
                break;

            case 2:
                file_enter(M);
                c1 = 0;
                break;

            default: printf("\nОшибка: неправильный символ.\n\n");
        }
    }

    printf("\n\n\nМЕНЮ:\n1) Среднее арифметическое\n2) Изменение элемента массива\n3) Запись даннных в файл\n4) Выход из программы");
    while (1) {
        cout << "\n\n\nВведите команду ";
        cin>>sw;
        switch (sw) {
            case 1:
                srednee(M);
                break;

            case 2:
                change(M);
                break;

            case 3:
                save(M);
                break;

            default: return 0;
        }
    }
}
