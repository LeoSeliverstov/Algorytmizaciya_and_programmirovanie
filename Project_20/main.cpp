#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void keyboard_enter(int M[7][2])
{
    int i,j;
    cout<<"\nВведите элементы массива: \n";
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 2; j++)
        {
            cin >> M[i][j];
        }
    }
    cout<<"\nМассив: \n";
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%3d ", M[i][j]);
        }
        cout << endl;
    }
}

void file_enter(int M[7][2])
{
    int i,j;
    std::ifstream file("massiv1.txt");
    for (i = 0; i <14; i++)
    {
        for(j = 0; j < 2; j++)
        {
            file >> M[i][j];
        }
    }
    cout<<"\nМассив: \n";
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%3d ", M[i][j]);
        }
        cout << endl;
    }
}

void srednee(int M[7][2])
{
    int sum=0;
    int sredn=0;
    int a;
    cout<<"\nВыберите строку: \n";
    cin>>a;
    for (int j=0 ;j<2 ;j++)
    {
        sum += M[a][j];
    }
    sredn=(sum)/2;
    cout<<"\nСреднее арифметическое: "<<sredn;
    
    FILE *f2;
    f2=fopen("sredn.txt", "w");
    fprintf(f2,"\n %d %d", sredn, a);
    fclose(f2);
}

void save_matrix(int M[7][2])
{
    FILE *f1;
    f1=fopen("massiv2.txt", "w");
    for (int l=0; l<7; l++)
    {
        for (int k=0; k<2; k++)
        {
            fprintf(f1,"  %3d", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout<<"\nПроизведена запись в файл.";
}

int main()
{
    int i, j, sw, sw1, c1=1, a, sum, sredn, M[7][2];
    printf("\n\nМЕНЮ:\n1) Ввести массив с клавиатуры\n2) Чтение массива из файла\n\n");
    
    while(c1)
    {
        cout<<"\nВведите команду: ";
        cin>>sw1;
        
        switch(sw1)
        {
            case 1:
                keyboard_enter(M);
                c1=0;
            break;
            
            case 2:
                file_enter(M);
                c1=0;
            break;
            
            default: printf("\nОшибка: неправильный символ.\n\n");
        }
    }
    
    printf("\n\n\nМЕНЮ:\n1) Расчет среднего арифметического\n2) Запись даннных в файл\n3) Выход из программы");
    while(1)
    {
        cout<<"\n\n\nВведите команду ";
        cin>>sw;
        
        switch(sw)
        {
            case 1:
                srednee(M);
            break;
            
            case 2:
                save_matrix(M);
            break;
           
            default: return 0;
        }
    }
}
