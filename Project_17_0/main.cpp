#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

float keybard_enter(float matrix[4][5]) // Ввод массива с клавиатуры
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            cout << "\nВведите элемент массива:" << " X[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    return matrix[4][5];

}

void GenerateRandomFile(float matrix[4][5]) {
    ofstream workfile;
    workfile.open("matrix.txt");
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        int rnd = rand();
//        float rnd2 = rnd / 100;
        sleep(129);
        workfile << rnd;
        workfile << " ";
    }
    workfile.close();
}

float file_enter(float matrix[4][5]) //Функция ввода массива из файла
{
    int i, j;
    ifstream F("matrix.txt", ios::in); //Открываю файл для чтения
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            F >> (matrix[i][j]); //Записываю элементы из файла в массив
    F.close(); //Закрываю файл
    cout << endl;
    return matrix[4][5];
}

void out_matrix_display(float matrix[4][5]) {
    int i, j;
    cout << "Массив:\n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            cout << fixed << setprecision(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void out_matrix_file(float matrix[4][5]) {
    int i, j;
    ofstream F("end_matrix.txt", ios::app); //открываю файл для записи
    F << "Конечная матрица:";
    F << "\r";
    for (i = 0; i < 4; i++) {
        F << "\n";
        for (j = 0; j < 5; j++) {
            F << fixed << setprecision(4) << matrix[i][j] << "  "; //обеспечиваю запись в виде матрицы [4x5]
        }
        F << "\r";
    }
    F << endl << endl;
    F.close(); //Закрываю файл
    cout << "\nФайлы успешно созданы!\n\n"; //Сообщаю пользователю о завершении операции
}

void min_el_matrix(float matrix[4][5]) {
    int i, j;
    float min = INT_MAX;
    for (;;) {
        int N = 0;
        cout << "Введите номер строки, в которой нужно найти минимальный элемент:\n";
        cin>>N;

        if (N > 0 && N <= 4) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 5; j++) {
                    if (matrix[N - 1][j] < min)
                        min = matrix[N - 1][j];
                }
            }

            ofstream F("min_max.txt", ios::app);
            F << "Минимальный элемент " << fixed << setprecision(4) << N << " строки:\n\n" << min << "\n";
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

void max_el_matrix(float matrix[4][5]) {
    int i, j;
    float max = 0;
    for (;;) {
        int N = 0;
        cout << "\nВведите номер строки, в которой нужно найти максимальный элемент:\n";
        cin>>N;

        if (N > 0 && N <= 4) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 5; j++) {
                    if (matrix[N - 1][j] > max)
                        max = matrix[N - 1][j];
                }
            }
            ofstream F("min_max.txt", ios::app);
            F << "Максимальный элемент " << fixed << setprecision(4) << N << " строки:\n\n" << max << "\n";
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

int main() //Главная функция, выполнение программы
{
    float matrix[4][5];
    char answer_1, answer_2;
    setlocale(LC_ALL, "russian");

    for (;;) {
        cout << "\nПрограмма вычисления максимального или минимального элемента матрицы в заданной строке\n" << endl;
        cout << "1. Загрузить массив из файла\n2. Ввести вручную\n\n" << endl;
        cin>>answer_1;

        if (answer_1 == '1') file_enter(matrix);
        if (answer_1 == '2') keybard_enter(matrix);
        if (answer_1 == '3') GenerateRandomFile(matrix);
        if ((answer_1 == '1') || (answer_1 == '2') || (answer_1 == '3')) break;
    }
    out_matrix_display(matrix);
    cout << "\n\n";

    for (;;) //бесконечный цикл
    {
        cout << "\n\n1. Найти минимальный элемент в строке\
           \n2. Найти максимальный элемент в строке\
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
