#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

void keyboard(int M[3][6]) {
    int i, j;
    cout << "\nВведите элементы массива: \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 6; j++) {
            cin >> M[i][j];
        }
    }

    cout << "\nМассив: \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 6; j++) {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }

}

void file_enter(int M[3][6]) {
    int i, j;
    std::ifstream file("massiv1.txt");
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 6; j++) {
            file >> M[i][j];
        }
    }

    cout << "\nМассив: \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 6; j++) {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }

}

void find_max(int M[3][6]) {
    int max, a1, j;
    cout << "\nВыберите строку: \n";
    cin>>a1;
    max = M[a1][0];

    for (j = 0; j < 6; j++) {
        if (M[a1][j] > max) {
            max = M[a1][j];
        }
    }
    cout << "\nMax: " << max;

    FILE *f2;
    f2 = fopen("max.txt", "w");
    fprintf(f2, "\n %d %d", max, a1);
    fclose(f2);
}

void find_min(int M[3][6]) {
    int a2, j, min;
    cout << "\nВыберите строку: \n";
    cin>>a2;
    min = M[a2][0];

    for (j = 0; j < 6; j++) {
        if (M[a2][j] < min) {
            min = M[a2][j];
        }
    }
    cout << "\nMin: " << min;

    FILE *f3;
    f3 = fopen("min.txt", "w");
    fprintf(f3, "\n %d %d", min, a2);
    fclose(f3);
}

void file_save(int M[3][6]) {
    int max, min, a1, a2;
    FILE *f1;
    f1 = fopen("massiv2.txt", "w");


    for (int l = 0; l < 3; l++) {
        for (int k = 0; k < 6; k++) {
            fprintf(f1, "  %3d", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }

    fclose(f1);

    cout << "\nПроизведена запись в файл.";
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    int i, j, sw, sw1, c1 = 1, M[3][6];
    printf("\n\nМЕНЮ:\n1) Ввести массив с клавиатуры\n2) Чтение массива из файла\n\n");

    while (c1) {
        cout << "\nВведите команду: ";
        cin>>sw1;

        switch (sw1) {
            case 1:
                keyboard(M);
                c1 = 0;
                break;

            case 2:
                file_enter(M);
                c1 = 0;
                break;

            default: printf("\nОшибка: неправильный символ.\n\n");
        }
    }

    printf("\n\n\nМЕНЮ:\n1) Поиск максимального\n2) Поиск минимального\n3) Запись даннных в файл\n4) Выход из программы");

    while (1) {
        cout << "\n\n\nВведите команду ";
        cin>>sw;

        switch (sw) {
            case 1:
                find_max(M);
                break;

            case 2:
                find_min(M);
                break;

            case 3:
                file_save(M);
                break;

            default: return 0;
        }
    }
}
