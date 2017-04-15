#include <cstdlib>
#include <iostream>
#include <fstream.h>

using namespace std;

int main(int argc, char** argv)
{
    int i, j, sw, sw1, c1=1, a1, a2, min, max, M[3][4];
    printf("\n\nМЕНЮ:\n1) Ввести массив с клавиатуры\n2) Чтение массива из файла\n\n");
    
    while(c1)
    {
        cout<<"\nВведите команду: ";
        cin>>sw1;
        
        switch(sw1)
        {
            case 1:
            {
                cout<<"\nВведите элементы массива: \n";
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 4; j++)
                    {
                        cin >> M[i][j];
                    }
                }
                
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 4; j++)
                    {
                        cout<< M[i][j] <<"  ";
                    }
                    cout << endl;
                }
                c1=0;
            }
            break;
            
            case 2:
            {
                std::ifstream file("massiv1.txt");
                for (i = 0; i <15; i++)
                {
                    for(j = 0; j < 4; j++)
                    {
                        file >> M[i][j];
                    }
                }

                cout<<"\nМассив: \n";
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 4; j++)
                    {
                        cout<<M[i][j] << "  ";
                    }
                    cout << endl;
                }
                c1=0;
            }
            break;
            
            default: printf("\nОшибка: неправильный символ.\n\n");
        }
    }
    
    printf("\n\n\nМЕНЮ:\n1) Поиск максимального\n2) Поиск минимального\n3) Запись даннных в файл\n4) Выход из программы");
    
    while(1)
    {
        cout<<"\n\n\nВведите команду ";
        cin>>sw;
        
        switch(sw)
        {
            case 1:
            {
                cout<<"\nВыберите столбец: \n";
                cin>>a1;
                max= M[0][a1];
                
                for (i=0 ;i<3 ;i++)
                {
                    if(M[i][a1]>max)
                    {
                        max=M[i][a1];
                    }
                }
                cout<<"\nMax: "<<max;
            }
            break;
        
            case 2:
            {
                cout<<"\nВыберите столбец: \n";
                cin>>a2;
                min= M[0][a2];
                for (i=0 ;i<3 ;i++)
                {
                    if(M[i][a2]<min)
                    {
                        min=M[i][a2];
                    }
                }
                cout<<"\nMin: "<<min;
            }
            break;
            
            case 3:
            {
                FILE *f1, *f2;
                f1=fopen("massiv2.txt", "w");
                f2=fopen("max_min.txt", "w");
                
                for (int l=0; l<3; l++)
                {
                    for (int k=0; k<4; k++)
                    {
                        fprintf(f1,"  %d", M[l][k]);
                    }
                    fprintf(f1, "\r\n");
                }
                fprintf(f2,"\n %d %d %d %d", max, min, a1, a2);
                fclose(f1);
                fclose(f2);
                cout<<"\nПроизведена запись в файл.";
            }
            break;
           
            default: return 0;
        }
    }
}
