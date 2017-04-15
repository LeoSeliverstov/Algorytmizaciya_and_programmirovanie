#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void keyboard_enter(int M[15])
{
    int i;
    for (i = 1; i <16; i++)
    {
        cout << "Введите " << i << " элемент массива: ";
        cin >> M[i];
    }

    cout<<"\nМассив:";
    for (i = 1; i <16; i++)
    {
        cout<<" "<<M[i];
    }
}

void file_enter(int M[15])
{
    int i;
    std::ifstream file("massiv1.txt");
    for (i = 1; i <16; i++)
    {
        file >> M[i];
    }
    cout<<"\nМассив:";
    for (i = 1; i <16; i++)
    {
        cout<<" "<<M[i];
    }
}

void summa(int M[15])
{
    int sum=0;
    for (int i = 1; i <16; i++)
        sum += M[i];
    cout <<"\nСумма элементов массива: "<< sum;
    FILE *f2;
    f2=fopen("sum.txt", "w");
    fprintf(f2,"\n %d", sum);
    fclose(f2);
}

void izmen(int M[15])
{
    int i;
    cout<<"Введите номер элемента: ";
    cin>>i;
    cout<<"Введите новое значение элемента: ";
    cin>>M[i];
    cout<<"\nМассив:";
    for (i = 1; i <16; i++)
    {
        cout<<" "<<M[i];
    }
}

void matrix_save(int M[15])
{
    FILE *f1;
    f1=fopen("massiv2.txt", "w");
    for (int j=0; j<5; j++)
    {
        for (int k=1; k<4; k++)
        {
            fprintf(f1,"  %d", M[k+(j*3)]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout<<"\nПроизведена запись в файл.";
}

int main()
{   setlocale(LC_ALL, "rus");

    int c1=1, c2=1, switch_2, switch_1, M[15];
    printf("\n\nМЕНЮ:\n1) Ввести массив с клавиатуры\n2) Чтение массива из файла\n\n");
  
    while(c2)
    {
        printf("\n\n\nМЕНЮ:\n1) Ввод массива с клавиатуры\n2) Чтение массива из файла\n3) Расчет суммы элементов массива\n4) Изменение элемента массива\n5) Запись данных в файл\n6) Выход из программы");
        cout<<"\n\n\nВведите команду: ";
        cin>>switch_2;
        switch(switch_2)
        {
            case 1:
                keyboard_enter(M);
            break;

            case 2:
                file_enter(M);
            break;
            
            case 3:
                summa(M);
            break;

            case 4:
                izmen(M);
            break;

            case 5:
                matrix_save(M);
            break;

            default: return 0;
        }
    }
}
