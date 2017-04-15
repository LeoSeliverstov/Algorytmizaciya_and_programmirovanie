#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

void keyboard_enter(int M[3][6]) {
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

void summa(int M[3][6]) {
    int i, a1, sum;
    cout << "\nВыберите столбец: \n";
    cin>>a1;

    sum = 0;
    for (i = 0; i < 3; i++) {
        sum += M[i][a1];
    }
    cout << "\nСумма столбца: " << sum;

    FILE *f2;
    f2 = fopen("sum.txt", "w");
    for (int k = 0; k < 6; k++) {
        sum = 0;
        fprintf(f2, "%d     ", k);

        for (int l = 0; l < 3; l++) {
            fprintf(f2, "   %d", M[l][k]);
            sum += M[l][k];
        }

        fprintf(f2, "       %3d", sum);
        fprintf(f2, "\r\n");
    }
    fclose(f2);
}

void save(int M[3][6]) {
    FILE *f1;
    f1 = fopen("massiv2.txt", "w");


    for (int l = 0; l < 3; l++) {
        for (int k = 0; k < 6; k++) {
            fprintf(f1, "   %3d", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }


    fclose(f1);

    cout << "\nПроизведена запись в файл.";
}

int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "Russian");
    int i, j, sw, sw1, sum, c1 = 1, a1, M[3][6];
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

    printf("\n\n\nМЕНЮ:\n1) Подсчет суммы элементов столбца\n2) Запись даннных в файл\n3) Выход из программы");

    while (1) {
        cout << "\n\n\nВведите команду ";
        cin>>sw;

        switch (sw) {
            case 1:
                summa(M);
                break;

            case 2:
                save(M);
                break;

            default: return 0;
        }
    }
}
