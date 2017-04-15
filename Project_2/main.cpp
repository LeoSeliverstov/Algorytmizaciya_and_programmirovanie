#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void f_max (int i, int *M)
{
    int max;
    max= M[0];
    
    for (i=0 ;i<15 ;i++)
    {
        if(M[i]>max)
        {
            max=M[i];
        }
    }
    cout<<"\nMax: "<<max;
}

void f_min (int i, int *M)
{
    int min;
    min= M[i];
    for (i=0 ;i<15 ;i++)
    {
        if(M[i]<min)
        {
            min=M[i];
        }
    }
    cout<<"\nMin: "<<min;
}

void f_save (int i, int j, int *M)
{
    char name_file[20];
    
    FILE *f1;
    cout<<"Vvedie imya fayla: ";
    cin>>name_file;
    f1=fopen(name_file, "w");
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            fprintf(f1,"  %d", M[j+(i*3)]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout<<"\nDannye zapisany v fayl.";
}

int main()
{
    int i, j, c1=1, sw, sw1, M[15];
    printf("\n\nMENU:\n1) Vvesti massiv s klaviatury\n2) Chtenie massiva iz fayla\n\n");
    
    while(c1)
    {
        cout<<"\nVvedite comandu: ";
        cin>>sw1;
        switch(sw1)
        {
            case 1:
            {
                for (i = 0; i <15; i++)
                {
                    cout << "Vvedite " << i << " element massiva: ";
                    cin >> M[i];
                }
                
                cout<<"\nMassiv: ";
                for (i = 0; i <15; i++)
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
                
                cout<<"\nMassiv: ";
                for (i = 0; i <15; i++)
                {
                    cout<<" "<<M[i];
                }
                c1=0;
            }
            break;
            
            default: printf("\nOshibka: nepravilny symvol.\n\n");
        }
    }
    
    printf("\n\n\nMENU:\n1) Poisk maximalnogo\n2) Poisk minimalnogo\n3) Zapis dannyh v fayl\n4) Vyhod");
    while(1)
    {
        cout<<"\n\n\nVvedite comandu: ";
        cin>>sw;
        switch(sw)
        {
            case 1:
                f_max(i, M);
            break;
       
            case 2:
                f_min(i, M);
            break;
            
            case 3:
                f_save(i, j, M);
            break;
           
            default: return 0;
        }
    }
}

