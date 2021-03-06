#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    int i, j, sw, sw1, c1=1, a1, a2;
    float min, max, M[4][5];
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
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        cin >> M[i][j];
                    }
                }
                
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
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
                for (i = 0; i <20; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        file >> M[i][j];
                    }
                }

                cout<<"\nМассив: \n";
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
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
                cout<<"\nВыберите строку: \n";
                cin>>a1;
                max= M[a1][0];
                
                for (j=0 ;j<5 ;j++)
                {
                    if(M[a1][j]>max)
                    {
                        max=M[a1][j];
                    }
                }
                cout<<"\nMax: "<<max;
            }
            break;
        
            case 2:
            {
                cout<<"\nВыберите строку: \n";
                cin>>a2;
                min= M[a2][0];
                
                for (j=0 ;j<5 ;j++)
                {
                    if(M[a2][j]<min)
                    {
                        min=M[a2][j];
                    }
                }
                cout<<"\nMin: "<<min;
            }
            break;
            
            case 3:
            {
                FILE *f1, *f2;
                f1=fopen("massiv1.txt", "w");
                f2=fopen("max_min.txt", "w");
                
                for (int l=0; l<4; l++)
                {
                    for (int k=0; k<5; k++)
                    {
                        fprintf(f1,"  %.3f", M[l][k]);
                    }
                    fprintf(f1, "\r\n");
                }
                fprintf(f2,"\n %.3f %.3f %d %d", max, min, a1, a2);
                fclose(f1);
                fclose(f2);
                cout<<"\nПроизведена запись в файл.";
            }
            break;
           
            default: return 0;
        }
    }
}
