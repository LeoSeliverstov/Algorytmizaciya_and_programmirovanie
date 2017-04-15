#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void keyboard_enter(int M[4][6]) {
    int i, j;
    cout << "\nВведите элементы массива: \n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            cin >> M[i][j];
        }
    }
    cout << "\nМассив: \n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d  ", M[i][j]);
        }
        cout << endl;
    }
}

void file_enter(int M[4][6]) {
    int i, j;
    std::ifstream file("massiv1.txt");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            file >> M[i][j];
        }
    }
    cout << "\nМассив: \n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d   ", M[i][j]);
        }
        cout << endl;
    }
}

void srednee(int M[4][6]) {
    int i, a, a1, sum, sredn;
    sum = 0;
    sredn = 0;
    cout << "\nВыберите строку: \n";
    cin>>a;
    a1 = a - 1;
    for (i = 0; i < 4; i++) {
        sum += M[i][a1];
    }
    sredn = (sum) / 4;
    cout << "\nСреднее арифметическое элементов строки: " << sredn;

    ofstream F("sredn.txt", ios::app);
    F << "Среднее арифметическое " << fixed << setprecision(4) << a << " строки:\n\n" << sredn << "\n";
    F << "\r\n";
    F.close();
}

void save(int i, int j, int s1, int s2, int s3, int M[4][6]) {
    s1 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            if (M[i][j] < 0)
                s1 = s1 + 1;
        }
    }

    s2 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            if (M[i][j] > 0)
                s2 = s2 + 1;
        }
    }

    s3 = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            if (M[i][j] == 0)
                s3++;
        }
    }

    FILE *f1, *f2;
    f1 = fopen("massiv2.txt", "w");
    for (int l = 0; l < 4; l++) {
        for (int k = 0; k < 6; k++) {
            fprintf(f1, "%3d  ", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout << "\nДанные записаны в файл.";
}

int main() {
     setlocale(LC_ALL, "rus");
    int i, j, sw, sw1, c1 = 1, s1, s2, s3;
    int M[4][6];
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

    printf("\n\n\nМЕНЮ:\n1) Среднее арифметическое\n2) Запись данных в файл\n3) Vyhod");
    while (1) {
        cout << "\n\n\nВведите команду: ";
        cin>>sw;
        switch (sw) {
            case 1:
                srednee(M);
                break;

            case 2:
                save(i, j, s1, s2, s3, M);
                break;

            default: return 0;
        }
    }
}
