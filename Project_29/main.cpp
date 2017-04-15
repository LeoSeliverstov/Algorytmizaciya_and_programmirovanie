#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale.h>



#include <cstddef>
#include <cmath>

using namespace std;

void keyboard_enter(int M[2][4]) {
    int i, j;
    cout << "\nВведите элементы массива: \n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            cin >> M[i][j];
        }
    }

    cout << "\nМассив: \n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }
}


void file_enter(int M[2][4]) {
    int i, j;
    std::ifstream file("massiv1.txt");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            file >> M[i][j];
        }
    }

    cout << "\nМассив: \n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }

}

void srednee(int M[2][4]) {
    int i, a, a1, sum, sredn;
    sum = 0;
    sredn = 0;
    cout << "\nVyberite stolbets: \n";
    cin>>a;
    a1 = a - 1;

    for (i = 0; i < 2; i++) {
        sum += M[i][a1];
    }
    sredn = (sum) / 2;
    cout << "\nSredn: " << sredn;

    FILE *f2;
    f2 = fopen("sredn.txt", "w");
    fprintf(f2, "\n %d %d", sredn, a);
    fclose(f2);
}

void save(int M[2][4]) {
    char name[20];
    cout << "\nВведите имя файла: \n";
    cin>>name;
    FILE *f1;
    f1 = fopen(name, "w");

    for (int l = 0; l < 2; l++) {
        for (int k = 0; k < 4; k++) {
            fprintf(f1, "   %3d", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }

    fclose(f1);

    cout << "\nПроизведена запись в файл.";
}

int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "Russian");
    int i, j, sw, sw1, sum, c1 = 1, a1, M[2][4];
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

    printf("\n\n\nМЕНЮ:\n1) Подсчет среднего арифметического\n2) Запись даннных в файл\n3) Выход из программы");

    while (1) {
        cout << "\n\n\nВведите команду ";
        cin>>sw;

        switch (sw) {
            case 1:
                srednee(M);
                break;

            case 2:
                save(M);
                break;

            default: return 0;
        }
    }
}
