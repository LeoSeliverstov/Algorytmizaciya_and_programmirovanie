#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

float keybard_enter(float matrix[2][6])
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            cout << "\nВведите элемент массива:" << " X[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    return matrix[2][6];

}

float file_enter(float matrix[2][6])
{
    int i, j;
    ifstream F("matrix.txt", ios::in);
    for (i = 0; i < 2; i++)
        for (j = 0; j < 6; j++)
            F >> (matrix[i][j]);
    F.close();
    cout << endl;
    return matrix[2][6];
}

void out_matrix_display(float matrix[2][6]) {
    int i, j;
    cout << "Массив:\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            cout << fixed << setprecision(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void out_matrix_file(float matrix[2][6]) {
    int i, j;
    ofstream F("end_matrix.txt", ios::app);
    F << "Конечная матрица:";
    F << "\r";
    for (i = 0; i < 2; i++) {
        F << "\n";
        for (j = 0; j < 6; j++) {
            F << fixed << setprecision(4) << matrix[i][j] << "  ";
        }
        F << "\r";
    }
    F << endl << endl;
    F.close();
    cout << "\nФайлы успешно созданы!\n\n";
}

void min_el_matrix(float matrix[2][6]) {
    int i, j;
    float min = INT_MAX;
    for (;;) {
        int N = 0;
        cout << "Введите номер столбца, в которой нужно найти минимальный элемент:\n";
        cin>>N;

        if (N > 0 && N <= 2) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 6; j++) {
                    if (matrix[N - 1][j] < min)
                        min = matrix[N - 1][j];
                }
            }

            ofstream F("min_max.txt", ios::app);
            F << "Минимальный элемент " << fixed << setprecision(4) << N << " строки:\n\n" << min << "\n";
            F << "\r\n";
            F.close();

            cout << "Минимальный элемент " << N << " строки:\n\n";
            cout << min << endl;
            cout << "\nНайти минимальный элемент в другой строке? (Y/N)\n\n";
            char ch;
            cin>>ch;
            if (ch != 'Y') {
                break;
            }
        } else {
            cout << "Ошибка! Такой строки нет. Повторите ввод.\n\n";
        }
    }
}

void max_el_matrix(float matrix[2][6]) {
    int i, j;
    float max = 0;
    for (;;) {
        int N = 0;
        cout << "\nВведите номер строки, в которой нужно найти максимальный элемент:\n";
        cin>>N;

        if (N > 0 && N <= 2) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 6; j++) {
                    if (matrix[N - 1][j] > max)
                        max = matrix[N - 1][j];
                }
            }
            ofstream F("min_max.txt", ios::app);
            F << "Максимальный элемент " << fixed << setprecision(4) << N << " строки:\n\n" << max << "\n";
            F << "\r\n";
            F.close();
            cout << "Максимальный элемент " << N << " строки:\n\n";
            cout << max << endl;
            cout << "\nНайти максимальный элемент в другой строке? (Y/N)\n\n";
            char ch;
            cin>>ch;
            if (ch != 'Y') {
                break;
            }
        } else {
            cout << "Ошибка! Такой строки нет. Повторите ввод.\n\n";
        }
    }
}

int main()
{
    float matrix[2][6];
    char answer_1, answer_2;
    setlocale(LC_ALL, "russian");
    for (;;) {
        cout << "\nПрограмма вычисления максимального или минимального элемента матрицы в заданной строке\n" << endl;
        cout << "1. Загрузить массив из файла\n2. Ввести вручную\n\n" << endl;
        cin>>answer_1;

        if (answer_1 == '1') file_enter(matrix);
        if (answer_1 == '2') keybard_enter(matrix);
        if ((answer_1 == '1') || (answer_1 == '2')) break;
    }
    out_matrix_display(matrix);
    cout << "\n\n";

    for (;;)
    {
        cout << "\n\n1. Найти минимальный элемент в строке\
           \n2. Найти максимальный элемент в стороке\
           \n3. Записать конечные файлы\
           \n4. Выйти из программы\n" << endl;
        cin>>answer_2;
        if (answer_2 == '4') break;

        switch (answer_2) {
            case '1': min_el_matrix(matrix);
                break;
            case '2': max_el_matrix(matrix);
                break;
            case '3': out_matrix_file(matrix);
                break;
            default: cout << "\nВыберите 1, 2, 3 или 4!\n";
                break;
        }
    }
    return 0;
}
