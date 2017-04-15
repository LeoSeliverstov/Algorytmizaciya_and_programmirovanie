#include <cstdlib>
#include <iostream>
#include <fstream.h>

using namespace std;

int main(int argc, char** argv)
{
    int i, sw, sw1, c1=1, s1=0, s2=0, s3=0, M[15];
    printf("\n\nМЕНЮ:\n1) Ввести массив с клавиатуры\n2) Чтение массива из файла\n\n");
    
    while(c1)
    {
        cout<<"\nВведите команду: ";
        cin>>sw1;
        switch(sw1)
        {
            case 1:
            {
                for (i = 0; i <15; i++)
                {
                    cout << "Введите " << i << " элемент массива: ";
                    cin >> M[i];
                }
    
                for (int i = 0; i <15; i++)
                {
                    cout<<" "<<M[i];
                }
                c1=0;
            }
            break;
            
            case 2:
            {
                std::ifstream file("massiv1.txt");
                for (i = 0; i <15; i++)
                {
                    file >> M[i];
                }
                
                cout<<"\nМассив:";
                for (i = 0; i <15; i++)
                {
                    cout<<" "<<M[i];
                }
                c1=0;
            }
            break;
            
            default: printf("\nОшибка: неправильный символ.\n\n");
        }
    }
    
    printf("\n\n\nМЕНЮ:\n1) Число отрицательных элементов\n2) Число положительных элементов\n3) Число нулевых элементов\n4) Запись даннных в файл\n5) Выход из программы");
    while(1)
    {
        cout<<"\n\n\nВведите команду ";
        cin>>sw;
        switch(sw)
        {
            case 1:
            {
                for (i = 0; i <15; i++)
                    if (M[i]<0)
                    s1=s1+1;
                cout<<"\nЧисло отрицательных элементов: "<<s1;
            }
            break;
        
            case 2:
            {
                for (i = 0; i <15; i++)
                    if (M[i]>0)
                    s2=s2+1;
                cout<<"\nЧисло положительных элементов: "<<s2;
            }
            break;
            
            case 3:
            {
                for (i = 0; i <15; i++)
                    if (M[i]==0)
                        s3++;
                cout<<"\nЧисло нулевых элементов: "<<s3;
            }
            break;
            
            case 4:
            {
                FILE *f1, *f2;
                f1=fopen("massiv2.txt", "w");
                f2=fopen("S.txt", "w");
                for (int j=0; j<5; j++)
                {
                    for (int k=0; k<3; k++)
                    {
                        fprintf(f1,"  %d", M[k+(j*3)]);
                    }
                    fprintf(f1, "\r\n");
                }
                fprintf(f2,"\n %d %d %d", s1, s2, s3);
                fclose(f1);
                fclose(f2);
                cout<<"\nПроизведена запись в файл.";
            }
            break;
           
            default: return 0;
        }
    }
}

