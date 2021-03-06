#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    int i, j, sw, sw1, sum, c1=1, a, M[3][6];
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
                    for(j = 0; j < 6; j++)
                    {
                        cin >> M[i][j];
                    }
                }
                
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 6; j++)
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
                for (i = 0; i <18; i++)
                {
                    for(j = 0; j < 6; j++)
                    {
                        file >> M[i][j];
                    }
                }

                cout<<"\nМассив: \n";
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 6; j++)
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
    
    printf("\n\n\nМЕНЮ:\n1) Подсчет суммы элементов столбца\n2) Запись даннных в файл\n3) Выход из программы");
    
    while(1)
    {
        cout<<"\n\n\nВведите команду ";
        cin>>sw;
        
        switch(sw)
        {
            case 1:
            {
                cout<<"\nВыберите столбец: \n";
                cin>>a;

                sum=0;
                for (i=0 ;i<3 ;i++)
                {
                    sum+=M[i][a];
                }
                cout<<"\nСумма столбца: "<<sum;
            }
            break;
            
            case 2:
            {
                FILE *f1, *f2;
                f1=fopen("massiv2.txt", "w");
                f2=fopen("sum.txt", "w");
                
                for (int l=0; l<3; l++)
                {
                    for (int k=0; k<6; k++)
                    {
                        fprintf(f1,"  %d", M[l][k]);
                    }
                    fprintf(f1, "\r\n");
                }
                fprintf(f2,"\n %d %d", sum, a);
                fclose(f1);
                fclose(f2);
                cout<<"\nПроизведена запись в файл.";
            }
            break;
           
            default: return 0;
        }
    }
}
